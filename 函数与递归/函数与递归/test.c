#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1.��������֮�����ֵ����
//int get_max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = get_max(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}

//��ʵ�δ����β�ʱ���β�ʵ����ʵ�ε�һ����ʱ����
//���βε��޸��ǲ���ı�ʵ�εģ�
//void swap1(int x, int y)//void   �����޷���ֵ
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//void swap2(int* pa, int* pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a=%d b=%d\n", a, b);
//	//swap1(a, b);
//	swap2(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}


//2.������������λ�ú���
//int main()
//{
//	int a = 10;
//	int* pa = &a;//paָ�����
//	*pa = 20;//�����ò�����
//	printf("%d\n", a);
//	return 0;
//}
//#include <math.h>
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//		return 0;
//		}
//		 
//	}
//		return 1;
//	}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d\n", i);
//	}
//	return 0;
//}


//3.�ж��Ƿ�Ϊ���꺯��
//int is_leap_year(int y)
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (1 == is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//	return 0;
//}



//4.ʵ�ֶ��ֲ��ҵĺ���
      //������arr��һ��ָ��
//int binary_search(int arr[],int k,int sz)
//{
//	//�㷨��ʵ��
//
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	//���ֲ���
//	//��һ�����������в��Ҿ����ĳ����
//	//����ҵ��ˣ�������������±꣬�Ҳ�������-1
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret=binary_search(arr,k,sz);//���ݵ�������arr��Ԫ�صĵ�ַ
//	if (ret == -1)
//	{
//		printf("�Ҳ���ָ������\n");
//	}
//	else
//	{
//		printf("�ҵ��±��ǣ�%d\n", ret);
//	}
//	return 0;
//}


//5.ÿ����һ�κ�������num��һ��
//void Add(int* p)
//{
//	(*p)++;  //++�����ȼ��ϸߣ����Ҫ��*p������
//}
//
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("num=%d\n", num);
//	Add(&num);
//	printf("num=%d\n", num);
//	Add(&num);
//	printf("num=%d\n", num);
//	return 0;
//}

//**************************************************��ѧ**************************************
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 4355899)));
//	return 0;
//}
//#include "Add.h"
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//	sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//} 


