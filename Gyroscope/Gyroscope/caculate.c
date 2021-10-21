#include <stdio.h>
#include <math.h>
#include <string.h>
#include "caculate.h"
#include "uart_own.h"
//
//定义全局变量
#define PI 3.1415926f    //圆周率
#define RtA 57.295779f   //弧度转为角度--180/pi
#define AtR 0.0174533f   //角度转变弧度--pi/180
#define G 9.780326f      //重力加速度
#define T 0.01           //惯导采样时间  f=100Hz
#define STA 200          //静态误差消除采样次数
#define DYN 25           //动态取值采样次数
float imu[6] = { 0.0f }; //六轴传感器数据[角速度x 角速度y 角速度z 加速度x 加速度y 加速度z]
//数据读取相关标志参数定义
unsigned int timeflag = 0;
unsigned int First_initflag = 0;
unsigned int receive_finish = 0;
unsigned int test_numb = 0;
//*******************************//
//捷联惯导姿态、位置实时解算函数--sins_process
//输入：IMU六轴数据[角速度x 角速度y 角速度z 加速度x 加速度y 加速度z]
//输出：AVP九轴姿态、位置更新数据[横滚角 俯仰角 航向角 速度x 速度y 速度z 位置x 位置y 位置z]
//*******************************//
float sins_process(void)
{   
	//计算相关参数定义
	float t = 0.01;//定义采样时间
	float pose[3] = { 0.0f };     //初始的姿态  航向(phi)俯仰(theta)横滚(gama)
	float velo[3] = { 0.0f };     //初始的速度
	float posi[3] = { 0.0f };     //初始的位置
	float updataFt[3] = { 0.0f };   //导航坐标系中的比力ft
	float UpdateQ[4];              //先存储初始的四元数，再存储更新后的四元数
	//float Anginc[3];             //角增量
	float upqnb[4];                //姿态更新四元数
	float tranqnb[4];              //用来存储共轭的更新后的四元数
	float aveimu[6] = { 0.0f };    //每s次动态的imu数据平均值
	float staimu[6] = { 0.0f };    //前m次静止时的imu数据平均值
	//float avp[9] = { 0.0f };       //AVP九轴姿态、位置更新数据[横滚角 俯仰角 航向角 速度x 速度y 速度z 位置x 位置y 位置z]
	//
	unsigned int m = 0, n = 0,s=0, i = 0, j = 0, flag = 0;
	if (First_initflag == 0)
	{
		//进行静止采样，消除本身惯导自身的零漂
		while (m < STA)  //采集m次数据 然后求平均值 作为静止时候的采样值
		{
			for (n = 0; n < 10; n++)
			{
				if (!receive_finish)
				{
					DELAY_US(20 * 1000);
				}
				else
					break;
			}
			Uartc_process();//接收惯导的数据
			receive_finish = 0;
			m++;
			for (j = 0; j < 6; j++)
			{
				staimu[j] += imu[j];
			}
		}
		//求出捷联惯导每一个输出信号的平均值
		for (j = 0; j < 6; j++)
		{
			staimu[j] = staimu[j] / m;
		}

		First_initflag = 1;
	}
	else
	{
		while (s < DYN)//采集s次数据 然后求平均值 作为动态时候的采样值
		{
			Uartc_process();//接收惯导的数据
			receive_finish = 0;
			s++;
			for (j = 0; j < 6; j++)
			{
			    aveimu[j] += imu[j];
			}
		}
		for (i = 0; i < 6; i++)
		{
			aveimu[i] = aveimu[i] / s;
		}
		//判断数据返回是否正常
		for (n = 0; n < 10; n++)
		{
			if (!receive_finish)
			{
				DELAY_US(20 * 1000);
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			flag = 0;
			if (Uartc_process())
			{
				//减去捷联惯导每一个输出信号的平均值
				for (i = 0; i < 6; i++)
				{
					aveimu[i] = aveimu[i] - staimu[i];
				}
				UpdateQ[4] = a2qua(pose[1], pose[0], pose[2]);//pitch  roll  yaw
				upqnb[4] = a2qua(aveimu[1] * T, aveimu[0] * T, aveimu[2] * T);//角增量这里近似为：角速度*T
				UpdateQ[4] = qmul(&upqnb[4], &UpdateQ[4]);
				pose[3] = q2att(&UpdateQ[4]);
				tranqnb[4] = qconj(&UpdateQ[4]);
				float temp[3] = { aveimu[3] ,aveimu[4] ,aveimu[5] };
				updataFt[3] = qmulv(&tranqnb[4],&temp[3]);
				velo[3] = Integral(&updataFt[3], T * DYN, T * 2 * DYN);
				posi[3]= Integral(&velo[3], T * DYN, T * 2 * DYN);
			}
		}
	}
}
//
//*******************************//
//接受数据校验函数--ReceiveData
//输入：空
//输出：逻辑0/1
//*******************************//
unsigned int ReceiveData(void)
{
	if (receive_finish == 0x01)
	{
		DecodeData();
		return 1;
	}
	return 0;
}
//*******************************//
//数据接收函数--DecodeData
//输入：空
//输出：六轴传感器数据
//*******************************//
void DecodeData(void)
{
	imu[0] = Aaccx;//*0.01*180/PI;                                       //roll angle   横滚  x（弧度）gama  °/s
	imu[1] = Aaccy;//*0.01*180/PI;                                      //pitch angle   俯仰  y（弧度）theta
	imu[2] = Aaccz;//*0.01*180/PI;                                     //yaw angle      偏航  z（弧度）phi
	imu[3] = GYrox * 1000 * G;                                        //accel x  g
	imu[4] = GYroy * 1000 * G;                                       //accel y
	imu[5] = GYroz * 1000 * G;                                      //accel z
}
//*******************************//
//姿态角转为四元数函数--a2qua
//输入：三轴姿态角
//输出：姿态四元数
//*******************************//
float a2qua(float pitch, float roll, float yaw)
{
	pitch /= 2.0, roll /= 2.0, yaw /= 2.0;
	float	sp = sin(pitch), sr = sin(roll), sy = sin(yaw),
		    cp = cos(pitch), cr = cos(roll), cy = cos(yaw);
	float qnb[4] = { 0 };
	qnb[0] = cp * cr * cy - sp * sr * sy;
	qnb[1] = sp * cr * cy - cp * sr * sy;
	qnb[2] = cp * sr * cy + sp * cr * sy;
	qnb[3] = cp * cr * sy + sp * sr * cy;
	return qnb[4];
}
//*******************************//
//四元数相乘函数--qmul
//输入：q1,q2-输入四元数
//输出：四元数乘积
//*******************************//
float qmul(float q1[4], float q2[4])
{
	float q[4] = { 0 };
	q[0] = q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2] - q1[3] * q2[3];
	q[1] = q1[0] * q2[1] + q1[1] * q2[0] + q1[2] * q2[3] - q1[3] * q2[2];
	q[2] = q1[0] * q2[2] + q1[2] * q2[0] + q1[3] * q2[1] - q1[1] * q2[3];
	q[3] = q1[0] * q2[3] + q1[3] * q2[0] + q1[1] * q2[2] - q1[2] * q2[1];
	return q[4];
}
//*******************************//
//四元数转为姿态角函数--q2att
//输入：更新后的姿态四元数
//输出：更新后的姿态角
//*******************************//
float q2att(float qnb[4])
{
	float 	q11 = qnb[0] * qnb[0], q12 = qnb[0] * qnb[1], q13 = qnb[0] * qnb[2], q14 = qnb[0] * qnb[3],
		    q22 = qnb[1] * qnb[1], q23 = qnb[1] * qnb[2], q24 = qnb[1] * qnb[3],
		    q33 = qnb[2] * qnb[2], q34 = qnb[2] * qnb[3],
		    q44 = qnb[3] * qnb[3];
	float att[3];
	att[0] = asin(2 * (q34 + q12));
	att[1] = atan2(-2 * (q24 - q13), q11 - q22 - q33 + q44);
	att[2] = atan2(-2 * (q23 - q14), q11 - q22 + q33 - q44);
	return att[3];////pitch  roll  yaw
}
//*******************************//
//四元数共轭函数--qconj
//输入：四元数
//输出：共轭四元数
//*******************************//
float qconj(float q[4])
{
	q[0] =  q[0];
	q[1] = -q[1];
	q[2] = -q[2];
	q[3] = -q[3];
	return q[4];
}
//*******************************//
//四元数与3*1矢量相乘函数--qmulv
//输入：四元数,3*1矢量
//输出：输出矢量
//*******************************//
float qmulv(float q[4], float vi[3])
{
	float qo1 = -q[1] * vi[0] - q[2] * vi[1] - q[3] * vi[2],
		  qo2 =  q[0] * vi[0] + q[2] * vi[2] - q[3] * vi[1],
		  qo3 =  q[0] * vi[1] + q[3] * vi[0] - q[1] * vi[2],
	      qo4 =  q[0] * vi[2] + q[1] * vi[1] - q[2] * vi[0];
	float vo[3];
	vo[0] = -qo1 * q[1] + qo2 * q[0] - qo3 * q[3] + qo4 * q[2];
	vo[1] = -qo1 * q[2] + qo3 * q[0] - qo4 * q[1] + qo2 * q[3];
	vo[2] = -qo1 * q[3] + qo4 * q[0] - qo2 * q[2] + qo3 * q[1];
	return vo[3];
}
//*******************************//
//梯形-定积分函数--qmulv
//输入：积分变量，积分区间[a,b]
//输出：积分后的值
//*******************************//
float Integral(float x[3],float t1,float t2 )
{
	float s[3];
	int i = 0, j = 0;
	while (j<2)
	{
		j++;
		for (i = 0; i < 3; i++)
		{
			s[i] += x[i];
		}
	}
	for (i = 0; i < 3; i++)
	{
		s[i] =s[i]*(t2-t1)/2;
	}
	return s[3];
}