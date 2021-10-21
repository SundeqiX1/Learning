#include "math.h"
#include "string.h"
#include "caculate.h"
#include "uart_own.h"

////定义圆周率
#define PI 3.1415926f
////弧度转变角度的单位
#define RtA 57.324841f 
////角度转变弧度的单位 
#define AtR 0.0174533f 
////定义重力加速度的值
#define G 9.826f
////定义eps的值(很小很小)
#define eps 0.00000001


//定义静态全局变量用来存储6个有效数据
float data[6] = { 0,0,0,0,0,0 };
float t=0.01;//定义采样时间
float velo[3]={0,0,0};//初始的速度
float posi[3]={0,0,0};//初始的位置
float pose[3]={0,0,0};//初始的姿态 俯仰 (theta)  横滚(gama) 偏航(phi)  初始的偏航角150*PI/180
float UpdateQ[4];//先存储初始的四元数，再存储之后更新的四元数
float uppose[4][4];//4行4列的uppose四元数更新矩阵
float UpdateCtb[3][3];//先存储初始的姿态转换矩阵，再存储之后更新的姿态矩阵Ctb
float transM[3][3];//用来存储转置之后的矩阵Cbt
float updataFt[3];//导航坐标系中的比力ft  认为初始值就是0 0 0 
float ddtt[6]={0,0,0,0,0,0};

unsigned char udpstr[200];//__align(8)

unsigned int  timeflag=0;

unsigned int  First_initflag=0;

unsigned int  receive_finish=0;

unsigned int  test_numb=0;


// 接收 数据校验  时间更新问题1
unsigned int  ReceiveData(void)
{
//	if(Uartc_process())
//	{
//	  DecodeData();
//	  receive_finish=1;
//	  return 1;
//	}
	if(receive_finish == 0x01)
	{
	  DecodeData();
//      receive_finish=1;
      return 1;
	}
		return 0;
}
//
//读取正确的数据  时间更新问题2 
void DecodeData(void)
{
		data[0]=      Aaccx;//*0.01*180/PI;                                   //roll angle   横滚  x（弧度）gama  °/s
		data[1]=      Aaccy;//*0.01*180/PI;                                  //pitch angle   俯仰  y（弧度）theta
		data[2]=      Aaccz;//*0.01*180/PI;                                 //yaw angle   偏航  z（弧度）phi
	    data[3]=      GYrox*1000*G;                                        //accel x  g
	    data[4]=      GYroy*1000*G;                                       //accel y
	    data[5]=	  GYroz*1000*G;                                      //accel z
}
//
//
//
//计算初始四元数INITQ  形参就是初始的三个角度值INITPose[3]（单位为弧度）
void INIT_Q(float INITPose[3])

{
	//计算初始四元数
	//e0=cos(phi(1)/2)*cos(theta(1)/2)*cos(gama(1)/2)+sin(phi(1)/2)*sin(theta(1)/2)*sin(gama(1)/2);
		UpdateQ[0]=cos(0.5*INITPose[2])*cos(0.5*INITPose[1])*cos(0.5*INITPose[0])+sin(0.5*INITPose[2])*sin(0.5*INITPose[1])*sin(0.5*INITPose[0]);

	    //e1 =cos(phi(1)/2)*cos(theta(1)/2)*sin(gama(1)/2)-sin(phi(1)/2)*sin(theta(1)/2)*cos(gama(1)/2);
		UpdateQ[1]=cos(0.5*INITPose[2])*cos(0.5*INITPose[1])*sin(0.5*INITPose[0])-sin(0.5*INITPose[2])*sin(0.5*INITPose[1])*cos(0.5*INITPose[0]);

		//e2 =cos(phi(1)/2)*sin(theta(1)/2)*cos(gama(1)/2)+sin(phi(1)/2)*cos(theta(1)/2)*sin(gama(1)/2);
		UpdateQ[2]=cos(0.5*INITPose[2])*sin(0.5*INITPose[1])*cos(0.5*INITPose[0])+sin(0.5*INITPose[2])*cos(0.5*INITPose[1])*sin(0.5*INITPose[0]);

		//e3 = sin(phi(1)/2)*cos(theta(1)/2)*cos(gama(1)/2)-cos(phi(1)/2)*sin(theta(1)/2)*sin(gama(1)/2);
		UpdateQ[3]=sin(0.5*INITPose[2])*cos(0.5*INITPose[1])*cos(0.5*INITPose[0])-cos(0.5*INITPose[2])*sin(0.5*INITPose[1])*sin(0.5*INITPose[0]);
	
}

//四元数更新矩阵的计算  (使用三个角速度的值) 求出4行4列的uppose矩阵
  void updataPose(float udata[3])
  {  
	float aa,bb,cc,dd,ee;
	aa=udata[0]*udata[0]*t*t + udata[1]*udata[1]*t*t + udata[2]*udata[2]*t*t - 16;
	bb=udata[0]*udata[0]*t*t + udata[1]*udata[1]*t*t + udata[2]*udata[2]*t*t + 16;
	cc=8*udata[0]*t;
	dd=8*udata[1]*t;
	ee=8*udata[2]*t;
	//矩阵满足特殊性
	uppose[0][0]= -aa/bb;
	uppose[0][1]= -cc/bb;
	uppose[0][2]= -dd/bb;
	uppose[0][3]= -ee/bb;
	  
	uppose[1][0]=  -uppose[0][1];
	uppose[1][1]=   uppose[0][0];
	uppose[1][2]=  -uppose[0][3];
	uppose[1][3]=   uppose[0][2];
	  
	uppose[2][0]=  -uppose[0][2];
	uppose[2][1]=   uppose[0][3];
	uppose[2][2]=   uppose[0][0];
	uppose[2][3]=  -uppose[0][1];
	  
	uppose[3][0]=  -uppose[0][3];
	uppose[3][1]=  -uppose[0][2];
	uppose[3][2]=   uppose[0][1];
	uppose[3][3]=   uppose[0][0];
	
}	

//四元数的更新 Q(i+1)=uppose*Q(i)  实际上是4行4列的矩阵乘以4行一列的矩阵 
void updataQ(float a[4][4],float b[4])
{	
	int i,j;
    float update[4]={0,0,0,0};
      for(i=0;i<4;i++)
       {
       	for(j=0;j<4;j++)
       	    {                  
             update[i]+=a[i][j]*b[j];
            }
		UpdateQ[i]=update[i];
       }
	   
}
//姿态转换矩阵的更新Ctb
void updataC(float Q[4])
{
// 	float C[3][3];
	UpdateCtb[0][0]=Q[0]*Q[0]+Q[1]*Q[1]-Q[2]*Q[2]-Q[3]*Q[3];
	UpdateCtb[0][1]=2*(Q[1]*Q[2]+Q[0]*Q[3]);
	UpdateCtb[0][2]=2*(Q[1]*Q[3]-Q[0]*Q[2]);
	      	
	UpdateCtb[1][0]=2*(Q[1]*Q[2]-Q[0]*Q[3]);
	UpdateCtb[1][1]=Q[0]*Q[0]-Q[1]*Q[1]+Q[2]*Q[2]-Q[3]*Q[3];
	UpdateCtb[1][2]=2*(Q[2]*Q[3]+Q[0]*Q[1]);
	      	
	UpdateCtb[2][0]=2*Q[1]*Q[3]+Q[0]*Q[2]; //2*(q1*q3)+q0*q2
	UpdateCtb[2][1]=2*(Q[2]*Q[3]-Q[0]*Q[1]);
	UpdateCtb[2][2]=Q[0]*Q[0]-Q[1]*Q[1]-Q[2]*Q[2]+Q[3]*Q[3];
// 	return  C[3][3];
}

//矩阵转置3*3矩阵  这个未进行全局变量的定义   
 void trans_MATRIX(float a[3][3])
   {
    int i,j;
    for (i=0;i<3;i++)
       {
       	for(j=0;j<3;j++)
       	   {
       	   	transM[j][i]=a[i][j];
       	   }
       	}
    }

//加速度的坐标转换由b到t    实际上是3行3列的矩阵乘以3行一列的矩阵  这个未进行全局变量的定义
 void convance(float a[3][3],float b[])
{
    int i,j;
	float mulit[3];
      for (i=0;i<3;i++)
       {
       	mulit[i]=0;
       	for(j=0;j<3;j++)
       	    {                  
             mulit[i]+=a[i][j]*b[j+3];
            }
			updataFt[i]=mulit[i];
       }
 }


//速度计算 velo(:,i+1) = f_t*T+velo(:,i)
void calcvelo(float ft[3])
    {
		int j;
		for(j=0;j<3;j++)
       	   {
			velo[j] +=ft[j]*t;

       	    }
     }


//位置计算 posi(:,i+1) = velo(:,i)*T+ posi(:,i)
  void calcposi(float velo[3])
    {
		int j;
		for(j=0;j<3;j++)
       	   {
			posi[j] +=velo[j]*t;
			 }
     }
	 

//姿态计算  通过Ctb计算姿态
void calczitai(float T[3][3])
{

    float theta,gama,phi;

    theta=asin(T[1][2]);
    gama=atan(-T[0][2]/T[2][2]);//pose[1] 横滚角
    phi=atan(T[1][0]/T[1][1]);//pose[2]  偏航角
    pose[0]=theta;//俯仰角
    //计算横滚角
    if (fabs(T[2][2])>=eps)//计算精度问题
    {
        pose[1]=gama;//可写可不写
        if(T[2][2]>0)
        {
            pose[1]=pose[1];
        }
        else if(T[0][2]<0)
        {
            pose[1]=pose[1]+PI;
        }
        else
            pose[1]=pose[1]-PI;
    }
    else if (T[0][2]<0)
        pose[1]=PI/2;
    else
        pose[1]=-PI/2;
    //计算偏航角
    if (fabs(T[1][1])>=eps)
    {
        pose[2]=phi;//可写可不写
        if(T[1][1]>0)
        {
            pose[2]=pose[2];
        }
        else if(T[1][0]>0)
        {
            pose[2]=pose[2]+PI;
        }
        else
            pose[2]=pose[2]-PI;
    }
    else if (T[1][0]>0)
        pose[2]=PI/2;
    else
        pose[2]=-PI/2;
}
 //调用子函数读取数据
void sins_process(void)
{
	unsigned int  m=0,n=0,i=0,j=0,flag=0;
    if(First_initflag ==0)
    {
        //进行静止采样，消除本身惯导自身的零漂
        while(m<=200)  //采集m次数据 然后求平均值 作为静止时候的采样值
        {
           for(n=0;n<10;n++)
            {
                if(!receive_finish)
                {
                    DELAY_US(20*1000);
                }
                else
                    break;
            }
            Uartc_process();//接收惯导的数据
            receive_finish = 0;
            m++;
            for(j=0;j<=6;j++)
            {
                ddtt[j]+=data[j];
            }
        }
    //求出捷联惯导每一个输出信号的平均值
        for(j=0;j<=6;j++)
        {
            ddtt[j]=ddtt[j]/m;
        }

        First_initflag=1;
    }
    else
    {
    //
    //
    //
		unsigned int  s=0;
    	 while(s<=25)  //采集m次数据 然后求平均值 作为动态时候的采样值
    	        {
    	           for(n=0;n<10;n++)
    	            {
    	                if(!receive_finish)
    	                {
    	                    DELAY_US(20*1000);
    	                }
    	                else
    	                    break;
    	            }
    	            Uartc_process();//接收惯导的数据
    	            receive_finish = 0;
    	            s++;
    	            for(j=0;j<=6;j++)
    	            {
    	                data[j]+=data[j];
    	            }
    	            for(i=0;i<=6;i++)
                    {
                        data[i]=data[i]/s;
                    }

    	        }
//        timeflag=0;//定时器标志位
//
        for(n=0;n<10;n++)
        {
//            ReceiveData();

            if(!receive_finish)
            {
                DELAY_US(20*1000);
            }
            else
            {
                flag=1;
                break;
            }
        }


        if(flag)
        {
            flag=0;
//            t=timeflag*0.0005;//通过定时器确定采样的时间
//            if(ReceiveData())
            if(Uartc_process())
            {
                receive_finish = 0;
                test_numb++;
                //减去捷联惯导每一个输出信号的平均值
                for(i=0;i<=5;i++)
                {
                    data[i]=data[i]-ddtt[i];
                }
            //角度单位的变换
                for(i=0;i<=2;i++)
                {
                    pose[i]=pose[i]*RtA;
                    if(i<2)
                    {
                        pose[i]=-pose[i];
                    }
                }

                INIT_Q(pose);//初始化四元数 UpdateQ[4]
                updataPose(data);//计算四元数更新矩阵uppose[4][4]
                updataQ(uppose,UpdateQ);//计算更新四元数UpdateQ[4]
                updataC(UpdateQ);//计算姿态更新矩阵Ctb  UpdateCtb[3][3]
                trans_MATRIX(UpdateCtb);//计算转置矩阵  transM[3][3]
                convance(transM,data);//updataFt[3]
                calczitai(UpdateCtb);//计算姿态pose[3]
                calcvelo(updataFt);//计算速度velo[3]
                calcposi(velo);//计算位置posi[3]
//                int j;
//                		for(j=0;j<3;j++)
//                       	 {
//                			updataFt[j] -=velo[j]*t;
//                	        }
                timeflag=0;
            //
                Uartd_process();
            }
        }
    }
}
