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
int main()
{
	int a = 3;
	int b = 5;
	printf("  %d %d", a, b);
	//�Ӽ���--���ܻ����
	a = a + b;
	b = a - b;
	a = a - b;
	//���ķ���
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d", a, b);
	return 0;
}