#include <stdio.h>
#include <math.h>
#include <string.h>
#include "caculate.h"
#include "uart_own.h"
//
//����ȫ�ֱ���
#define PI 3.1415926f    //Բ����
#define RtA 57.295779f   //����תΪ�Ƕ�--180/pi
#define AtR 0.0174533f   //�Ƕ�ת�仡��--pi/180
#define G 9.780326f      //�������ٶ�
#define T 0.01           //�ߵ�����ʱ��  f=100Hz
#define STA 200          //��̬���������������
#define DYN 25           //��̬ȡֵ��������
float imu[6] = { 0.0f }; //���ᴫ��������[���ٶ�x ���ٶ�y ���ٶ�z ���ٶ�x ���ٶ�y ���ٶ�z]
//���ݶ�ȡ��ر�־��������
unsigned int timeflag = 0;
unsigned int First_initflag = 0;
unsigned int receive_finish = 0;
unsigned int test_numb = 0;
//*******************************//
//�����ߵ���̬��λ��ʵʱ���㺯��--sins_process
//���룺IMU��������[���ٶ�x ���ٶ�y ���ٶ�z ���ٶ�x ���ٶ�y ���ٶ�z]
//�����AVP������̬��λ�ø�������[����� ������ ����� �ٶ�x �ٶ�y �ٶ�z λ��x λ��y λ��z]
//*******************************//
float sins_process(void)
{   
	//������ز�������
	float t = 0.01;//�������ʱ��
	float pose[3] = { 0.0f };     //��ʼ����̬  ����(phi)����(theta)���(gama)
	float velo[3] = { 0.0f };     //��ʼ���ٶ�
	float posi[3] = { 0.0f };     //��ʼ��λ��
	float updataFt[3] = { 0.0f };   //��������ϵ�еı���ft
	float UpdateQ[4];              //�ȴ洢��ʼ����Ԫ�����ٴ洢���º����Ԫ��
	//float Anginc[3];             //������
	float upqnb[4];                //��̬������Ԫ��
	float tranqnb[4];              //�����洢����ĸ��º����Ԫ��
	float aveimu[6] = { 0.0f };    //ÿs�ζ�̬��imu����ƽ��ֵ
	float staimu[6] = { 0.0f };    //ǰm�ξ�ֹʱ��imu����ƽ��ֵ
	//float avp[9] = { 0.0f };       //AVP������̬��λ�ø�������[����� ������ ����� �ٶ�x �ٶ�y �ٶ�z λ��x λ��y λ��z]
	//
	unsigned int m = 0, n = 0,s=0, i = 0, j = 0, flag = 0;
	if (First_initflag == 0)
	{
		//���о�ֹ��������������ߵ��������Ư
		while (m < STA)  //�ɼ�m������ Ȼ����ƽ��ֵ ��Ϊ��ֹʱ��Ĳ���ֵ
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
			Uartc_process();//���չߵ�������
			receive_finish = 0;
			m++;
			for (j = 0; j < 6; j++)
			{
				staimu[j] += imu[j];
			}
		}
		//��������ߵ�ÿһ������źŵ�ƽ��ֵ
		for (j = 0; j < 6; j++)
		{
			staimu[j] = staimu[j] / m;
		}

		First_initflag = 1;
	}
	else
	{
		while (s < DYN)//�ɼ�s������ Ȼ����ƽ��ֵ ��Ϊ��̬ʱ��Ĳ���ֵ
		{
			Uartc_process();//���չߵ�������
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
		//�ж����ݷ����Ƿ�����
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
				//��ȥ�����ߵ�ÿһ������źŵ�ƽ��ֵ
				for (i = 0; i < 6; i++)
				{
					aveimu[i] = aveimu[i] - staimu[i];
				}
				UpdateQ[4] = a2qua(pose[1], pose[0], pose[2]);//pitch  roll  yaw
				upqnb[4] = a2qua(aveimu[1] * T, aveimu[0] * T, aveimu[2] * T);//�������������Ϊ�����ٶ�*T
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
//��������У�麯��--ReceiveData
//���룺��
//������߼�0/1
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
//���ݽ��պ���--DecodeData
//���룺��
//��������ᴫ��������
//*******************************//
void DecodeData(void)
{
	imu[0] = Aaccx;//*0.01*180/PI;                                       //roll angle   ���  x�����ȣ�gama  ��/s
	imu[1] = Aaccy;//*0.01*180/PI;                                      //pitch angle   ����  y�����ȣ�theta
	imu[2] = Aaccz;//*0.01*180/PI;                                     //yaw angle      ƫ��  z�����ȣ�phi
	imu[3] = GYrox * 1000 * G;                                        //accel x  g
	imu[4] = GYroy * 1000 * G;                                       //accel y
	imu[5] = GYroz * 1000 * G;                                      //accel z
}
//*******************************//
//��̬��תΪ��Ԫ������--a2qua
//���룺������̬��
//�������̬��Ԫ��
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
//��Ԫ����˺���--qmul
//���룺q1,q2-������Ԫ��
//�������Ԫ���˻�
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
//��Ԫ��תΪ��̬�Ǻ���--q2att
//���룺���º����̬��Ԫ��
//��������º����̬��
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
//��Ԫ�������--qconj
//���룺��Ԫ��
//�����������Ԫ��
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
//��Ԫ����3*1ʸ����˺���--qmulv
//���룺��Ԫ��,3*1ʸ��
//��������ʸ��
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
//����-�����ֺ���--qmulv
//���룺���ֱ�������������[a,b]
//��������ֺ��ֵ
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