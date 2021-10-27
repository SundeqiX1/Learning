#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	//int a = 5 / 2;//商2余1，得到商
//	double a = 5 / 2.0;
//	int b = 5 % 2;//得到余数
//	printf("%lf\n", a);
//	printf("%d\n", b);
//	return 0;
//}
//
//int main()
//{
//	int a = 16;
//	//>>右移操作符，移动的是二进制位
//	//00000000000000000000000000010000
//	//00000000000000000000000000001000
//	int b=a >> 1;
//	printf("%d\n", b);
//	return 0;
//}

//按位异或
//相同为0相异为1 


//交换两个变量的值，不使用第三个变量
int main()
{
	int a = 3;
	int b = 5;
	printf("  %d %d", a, b);
	//加减法--可能会溢出
	a = a + b;
	b = a - b;
	a = a - b;
	//异或的方法
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d", a, b);
	return 0;
}