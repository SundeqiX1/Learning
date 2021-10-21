#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _CACULATE_H_
#define _CACULATE_H_

#include "F2837xD_Device.h"     // DSP2833x 头文件
#include "F2837xD_Examples.h"   // DSP2833x 例子相关头文件


extern float Aaccx, Aaccy, Aaccz;
extern float GYrox, GYroy, GYroz;

extern unsigned int timeflag;
extern unsigned int receive_finish;

unsigned int ReceiveData(void);
void DecodeData(void);
float a2qua(float pitch, float roll, float yaw);
float qmul(float q1[4], float q2[4]);
float q2att(float qnb[4]);
float qconj(float q[4]);
float qmulv(float q[4], float vi[3]);
float Integral(float x[3], float t1, float t2);

#endif