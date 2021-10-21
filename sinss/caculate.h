/*
 * led.h
 *
 *  Created on: 2018-1-20
 *      Author: Administrator
 */

#ifndef _CACULATE_H_
#define _CACULATE_H_

#include "F2837xD_Device.h"     // DSP2833x 头文件
#include "F2837xD_Examples.h"   // DSP2833x 例子相关头文件


extern float Aaccx,Aaccy,Aaccz;
extern float GYrox,GYroy,GYroz;

extern unsigned int  timeflag;
extern unsigned int  receive_finish;

unsigned int ReceiveData(void);
void DecodeData(void);
void INIT_Q(float INITPose[3]);
void updataPose(float data[3]);
void updataQ(float a[4][4],float b[4]);
void updataC(float Q[4]);
void trans_MATRIX(float a[3][3]);
void convance(float a[3][3],float b[]);
void calcvelo(float ft[3]);
void calcposi(float velo[3]);
void calczitai(float T[3][3]);
void sins_process(void);

#endif /* LED_H_ */
