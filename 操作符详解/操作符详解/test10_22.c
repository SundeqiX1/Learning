#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	//int a = 5 / 2;//��2��1���õ���
//	double a = 5 / 2.0;
//	int b = 5 % 2;//�õ�����
//	printf("%lf\n", a);
//	printf("%d\n", b);
//	return 0;
//}
//
//int main()
//{
//	int a = 16;
//	//>>���Ʋ��������ƶ����Ƕ�����λ
//	//00000000000000000000000000010000
//	//00000000000000000000000000001000
//	int b=a >> 1;
//	printf("%d\n", b);
//	return 0;
//}

//��λ���
//��ͬΪ0����Ϊ1 


//��������������ֵ����ʹ�õ���������
//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("  %d %d", a, b);
//	//�Ӽ���--���ܻ����
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	//���ķ���
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

//��һ�������洢�ڼ�����ж����Ƶġ�1���ĸ���
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
//	//num&1==1    -->���һλΪ1
//	//ͳ��num�Ĳ������м���1
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
//	a += 2;//���Ϸ�ֵ��
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
//	int* p = &a;//ȡ��ַ������    int*�Ǳ���������
//	*p=20;//�����ò�����
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	char c = 'r';
//	char* p = &c;
//	int arr[10] = { 0 };
//	//����ı�����ռ�ڴ�ռ�Ĵ�С����λ���ֽ�
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