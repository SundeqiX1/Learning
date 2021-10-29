#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
//void qconj(float *q, float *q1)
//{
//	*(q) = *(q1);
//	*(q + 1) = -*(q1 + 1);
//	*(q + 2) = -*(q1 + 2);
//	*(q + 3) = -*(q1 + 3);
//}
int main()
{
	float tranqnb[4] = { 0.0 };
	float UpdateQ[4] = { 1.2,2.2,3.5,4.3 };
	tranqnb[0] = 4.0*UpdateQ[0];
	//qconj(tranqnb, UpdateQ);
	printf("%f %f %f %f\n", UpdateQ[0], UpdateQ[1], UpdateQ[2], UpdateQ[3]);
	printf("%f %f %f %f", tranqnb[0], tranqnb[1], tranqnb[2], tranqnb[3]);
	return 0;
}
