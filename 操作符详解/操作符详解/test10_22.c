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

//int main()
//{
//	short s = 0;
//	int a = 10;
//	printf("%d\n", sizeof(s = a + 5));
//	printf("%d\n", s); 
//	return 0;
//}

//int main()
//{
//	int a = 11;
//	a = a | (1 << 2);
//	printf("%d\n", a);
//	a =a &(~(1 << 2));
//	printf("%d\n", a);
//	//00000000000000000000000000001011
//	//
//	//int a = 0;
//	//~��λȡ��
//	//00000000000000000000000000000000
//	//11111111111111111111111111111111����
//	//11111111111111111111111111111110����
//	//10000000000000000000000000000001ԭ��
//	//-1
//	//printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//printf("%d", ++a);//ǰ��++����++��ʹ��
//	printf("%d", a++);//����++����ʹ�ú�++
//	return 0;
//}


//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//ָ��Ĵ�С
//}
//
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//ָ��Ĵ�С
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(ch));
//	test1(arr);
//	test2(ch);
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//	//i = a++&&++b&&d++;
//	i=a++||++b||d++;
//	printf("a=%d\nb=%d\nc=%d\nd=%d\n", a, b, c, d);
//	return 0;
//}

//ѧ��
//����һ���ṹ������--struct Stu
struct Stu
{
	char name[20];
	int age;
	char id[20];
};
//int main()
//{
//	//ʹ��struct Stu����ṹ�����ʹ�����һ��ѧ������s1������ʼ��
//	struct Stu s1 = { "�����",23,"20211101" };
//	struct Stu* ps = &s1;
//	printf("%s\n", ps->name);
//
//	//printf("%s\n", (*ps).name);
//	//printf("%d\n", (*ps).age);
//
//	//printf("%s\n", s1.name);
//	//printf("%d\n", s1.age);
//	//printf("%s\n", s1.id);
//	//�ṹ�����.��Ա��
//	return 0;
//}

//int main()
//{
//	char a = 3;
//	//00000000000000000000000000000011
//	//00000011--a
//	char b = 127;
//	//00000000000000000000000001111111
//	//01111111--b
//	//a+b
//	//��������
//	//00000000000000000000000000000011
//	//00000000000000000000000001111111
//	//00000000000000000000000010000010
//	//
//	char c = a + b;
//	//10000010--c
//	//��������
//	//11111111111111111111111110000010--����
//	//11111111111111111111111110000001--����
//	//10000000000000000000000001111110--ԭ��
//	//-126
//	printf("%d\n", c);
//	return 0;
//}

//��������ʵ����
//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//	if (c == 0xb6000000)
//		printf("c");
//	return 0;
//}

//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));
//	printf("%u\n", sizeof(+c));
//	printf("%u\n", sizeof(!c));
//	return 0;
//}
