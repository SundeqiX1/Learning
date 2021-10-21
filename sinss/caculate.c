#include "math.h"
#include "string.h"
#include "caculate.h"
#include "uart_own.h"

////����Բ����
#define PI 3.1415926f
////����ת��Ƕȵĵ�λ
#define RtA 57.324841f 
////�Ƕ�ת�仡�ȵĵ�λ 
#define AtR 0.0174533f 
////�����������ٶȵ�ֵ
#define G 9.826f
////����eps��ֵ(��С��С)
#define eps 0.00000001


//���徲̬ȫ�ֱ��������洢6����Ч����
float data[6] = { 0,0,0,0,0,0 };
float t=0.01;//�������ʱ��
float velo[3]={0,0,0};//��ʼ���ٶ�
float posi[3]={0,0,0};//��ʼ��λ��
float pose[3]={0,0,0};//��ʼ����̬ ���� (theta)  ���(gama) ƫ��(phi)  ��ʼ��ƫ����150*PI/180
float UpdateQ[4];//�ȴ洢��ʼ����Ԫ�����ٴ洢֮����µ���Ԫ��
float uppose[4][4];//4��4�е�uppose��Ԫ�����¾���
float UpdateCtb[3][3];//�ȴ洢��ʼ����̬ת�������ٴ洢֮����µ���̬����Ctb
float transM[3][3];//�����洢ת��֮��ľ���Cbt
float updataFt[3];//��������ϵ�еı���ft  ��Ϊ��ʼֵ����0 0 0 
float ddtt[6]={0,0,0,0,0,0};

unsigned char udpstr[200];//__align(8)

unsigned int  timeflag=0;

unsigned int  First_initflag=0;

unsigned int  receive_finish=0;

unsigned int  test_numb=0;


// ���� ����У��  ʱ���������1
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
//��ȡ��ȷ������  ʱ���������2 
void DecodeData(void)
{
		data[0]=      Aaccx;//*0.01*180/PI;                                   //roll angle   ���  x�����ȣ�gama  ��/s
		data[1]=      Aaccy;//*0.01*180/PI;                                  //pitch angle   ����  y�����ȣ�theta
		data[2]=      Aaccz;//*0.01*180/PI;                                 //yaw angle   ƫ��  z�����ȣ�phi
	    data[3]=      GYrox*1000*G;                                        //accel x  g
	    data[4]=      GYroy*1000*G;                                       //accel y
	    data[5]=	  GYroz*1000*G;                                      //accel z
}
//
//
//
//�����ʼ��Ԫ��INITQ  �βξ��ǳ�ʼ�������Ƕ�ֵINITPose[3]����λΪ���ȣ�
void INIT_Q(float INITPose[3])

{
	//�����ʼ��Ԫ��
	//e0=cos(phi(1)/2)*cos(theta(1)/2)*cos(gama(1)/2)+sin(phi(1)/2)*sin(theta(1)/2)*sin(gama(1)/2);
		UpdateQ[0]=cos(0.5*INITPose[2])*cos(0.5*INITPose[1])*cos(0.5*INITPose[0])+sin(0.5*INITPose[2])*sin(0.5*INITPose[1])*sin(0.5*INITPose[0]);

	    //e1 =cos(phi(1)/2)*cos(theta(1)/2)*sin(gama(1)/2)-sin(phi(1)/2)*sin(theta(1)/2)*cos(gama(1)/2);
		UpdateQ[1]=cos(0.5*INITPose[2])*cos(0.5*INITPose[1])*sin(0.5*INITPose[0])-sin(0.5*INITPose[2])*sin(0.5*INITPose[1])*cos(0.5*INITPose[0]);

		//e2 =cos(phi(1)/2)*sin(theta(1)/2)*cos(gama(1)/2)+sin(phi(1)/2)*cos(theta(1)/2)*sin(gama(1)/2);
		UpdateQ[2]=cos(0.5*INITPose[2])*sin(0.5*INITPose[1])*cos(0.5*INITPose[0])+sin(0.5*INITPose[2])*cos(0.5*INITPose[1])*sin(0.5*INITPose[0]);

		//e3 = sin(phi(1)/2)*cos(theta(1)/2)*cos(gama(1)/2)-cos(phi(1)/2)*sin(theta(1)/2)*sin(gama(1)/2);
		UpdateQ[3]=sin(0.5*INITPose[2])*cos(0.5*INITPose[1])*cos(0.5*INITPose[0])-cos(0.5*INITPose[2])*sin(0.5*INITPose[1])*sin(0.5*INITPose[0]);
	
}

//��Ԫ�����¾���ļ���  (ʹ���������ٶȵ�ֵ) ���4��4�е�uppose����
  void updataPose(float udata[3])
  {  
	float aa,bb,cc,dd,ee;
	aa=udata[0]*udata[0]*t*t + udata[1]*udata[1]*t*t + udata[2]*udata[2]*t*t - 16;
	bb=udata[0]*udata[0]*t*t + udata[1]*udata[1]*t*t + udata[2]*udata[2]*t*t + 16;
	cc=8*udata[0]*t;
	dd=8*udata[1]*t;
	ee=8*udata[2]*t;
	//��������������
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

//��Ԫ���ĸ��� Q(i+1)=uppose*Q(i)  ʵ������4��4�еľ������4��һ�еľ��� 
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
//��̬ת������ĸ���Ctb
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

//����ת��3*3����  ���δ����ȫ�ֱ����Ķ���   
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

//���ٶȵ�����ת����b��t    ʵ������3��3�еľ������3��һ�еľ���  ���δ����ȫ�ֱ����Ķ���
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


//�ٶȼ��� velo(:,i+1) = f_t*T+velo(:,i)
void calcvelo(float ft[3])
    {
		int j;
		for(j=0;j<3;j++)
       	   {
			velo[j] +=ft[j]*t;

       	    }
     }


//λ�ü��� posi(:,i+1) = velo(:,i)*T+ posi(:,i)
  void calcposi(float velo[3])
    {
		int j;
		for(j=0;j<3;j++)
       	   {
			posi[j] +=velo[j]*t;
			 }
     }
	 

//��̬����  ͨ��Ctb������̬
void calczitai(float T[3][3])
{

    float theta,gama,phi;

    theta=asin(T[1][2]);
    gama=atan(-T[0][2]/T[2][2]);//pose[1] �����
    phi=atan(T[1][0]/T[1][1]);//pose[2]  ƫ����
    pose[0]=theta;//������
    //��������
    if (fabs(T[2][2])>=eps)//���㾫������
    {
        pose[1]=gama;//��д�ɲ�д
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
    //����ƫ����
    if (fabs(T[1][1])>=eps)
    {
        pose[2]=phi;//��д�ɲ�д
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
 //�����Ӻ�����ȡ����
void sins_process(void)
{
	unsigned int  m=0,n=0,i=0,j=0,flag=0;
    if(First_initflag ==0)
    {
        //���о�ֹ��������������ߵ��������Ư
        while(m<=200)  //�ɼ�m������ Ȼ����ƽ��ֵ ��Ϊ��ֹʱ��Ĳ���ֵ
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
            Uartc_process();//���չߵ�������
            receive_finish = 0;
            m++;
            for(j=0;j<=6;j++)
            {
                ddtt[j]+=data[j];
            }
        }
    //��������ߵ�ÿһ������źŵ�ƽ��ֵ
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
    	 while(s<=25)  //�ɼ�m������ Ȼ����ƽ��ֵ ��Ϊ��̬ʱ��Ĳ���ֵ
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
    	            Uartc_process();//���չߵ�������
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
//        timeflag=0;//��ʱ����־λ
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
//            t=timeflag*0.0005;//ͨ����ʱ��ȷ��������ʱ��
//            if(ReceiveData())
            if(Uartc_process())
            {
                receive_finish = 0;
                test_numb++;
                //��ȥ�����ߵ�ÿһ������źŵ�ƽ��ֵ
                for(i=0;i<=5;i++)
                {
                    data[i]=data[i]-ddtt[i];
                }
            //�Ƕȵ�λ�ı任
                for(i=0;i<=2;i++)
                {
                    pose[i]=pose[i]*RtA;
                    if(i<2)
                    {
                        pose[i]=-pose[i];
                    }
                }

                INIT_Q(pose);//��ʼ����Ԫ�� UpdateQ[4]
                updataPose(data);//������Ԫ�����¾���uppose[4][4]
                updataQ(uppose,UpdateQ);//���������Ԫ��UpdateQ[4]
                updataC(UpdateQ);//������̬���¾���Ctb  UpdateCtb[3][3]
                trans_MATRIX(UpdateCtb);//����ת�þ���  transM[3][3]
                convance(transM,data);//updataFt[3]
                calczitai(UpdateCtb);//������̬pose[3]
                calcvelo(updataFt);//�����ٶ�velo[3]
                calcposi(velo);//����λ��posi[3]
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
