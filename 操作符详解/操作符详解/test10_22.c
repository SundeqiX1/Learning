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
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("  %d %d", a, b);
//	//加减法--可能会溢出
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	//异或的方法
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

//求一个整数存储在计算机中二进制的“1”的个数
//int main()
//{
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);
//
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (1 == ((num >> i) & 1))
//			count++;
//	}
//	//32bit
//	//num&1==1    -->最后一位为1
//	//统计num的补码中有几个1
//	//while (num )
//	//{
//	//	if (num % 2 == 1)
//	//	{
//	//		count++;
//	//	}
//	//	num = num / 2;
//	//}
//
//	printf("%d\n", count);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	a = a + 2;
//	a += 2;//复合幅值符
//
//	a = a >> 1;
//	a >>= 1;
//
//	a = a & 1;
//	a &= 1;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;//取地址操作符    int*是变量的类型
//	*p=20;//解引用操作符
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	char c = 'r';
//	char* p = &c;
//	int arr[10] = { 0 };
//	//计算的变量所占内存空间的大小，单位是字节
//	printf("%d\n", sizeof(a));//4
//	printf("%d\n", sizeof(int));//4
//
//	printf("%d\n", sizeof(c));//1
//	printf("%d\n", sizeof(char));//4
//
//	printf("%d\n", sizeof(p));//4
//	printf("%d\n", sizeof(char*));//4
//
//	printf("%d\n", sizeof(arr));//40
//	printf("%d\n", sizeof(int [10]));//4
//	return 0;
//}

int main()
{
	short s = 0;
	int a = 10;
	printf("%d\n", sizeof(s = a + 5));
	printf("%d\n", s); 
	return 0;
}