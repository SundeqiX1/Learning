#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//1.�������Ӵ�С����
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c =0 ;
//	scanf("%d%d%d", &a, &b, &c );
//	a���b��֮��c��С
//	if (a < b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//2.��ӡ1-100��3�ı���
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//3.�������������������������Լ��     շת�����
//int main()
//{
//	int m = 24;
//	int n = 18;
//	int r = 0;
//	while (m%n)
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//	return 0;
//}

//4.��ӡ1000-2000��֮�������
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		//�ж����꣺1.�ܱ�4�����Ҳ��ܱ�100����   ����    2.�ܱ�400������
//		//if (year % 4 == 0 && year % 100 != 0)
//		//{
//		//	printf("%d ", year);
//		//	count++;
//		//}
//		//else if (year % 400 == 0)
//		//{
//		//	printf("%d ", year);
//		//	count++;
//		//}
//		if ((year % 4 == 0) && (year % 100 != 0)||(year % 400 == 0))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}

//#include <math.h>
////5.��ӡ100-200֮�������
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		//�ж�i�Ƿ�Ϊ����
//		//�����жϹ���
//		//1.�Գ���
//		//����2->i-1������
//		for (j = 2; j <=sqrt(i); j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j >sqrt(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}

//***********************************************
//1.����1-100��9�ĸ���
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i < 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		 if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//2.����1/1-1/2+1/3-.....1/100��ֵ �����
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag=1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

//3.��10������������ֵ
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int max =arr[0];//���ֵ
//	int i = 0;
//	int se = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < se; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return 0;
//}

//4.��Ļ�����9*9�˷��ھ���
//1*1=1
//2*1=2 2*2=4
//...
//9*1=9 ...
//int main()
//{
//	int i = 0;
//	//ȷ����ӡ9��
//	for (i = 1; i <= 9; i++)
//	{
//		//��ӡ9��
//		int j = 1;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}