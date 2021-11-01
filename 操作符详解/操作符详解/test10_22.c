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
//	//~按位取反
//	//00000000000000000000000000000000
//	//11111111111111111111111111111111补码
//	//11111111111111111111111111111110反码
//	//10000000000000000000000000000001原码
//	//-1
//	//printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//printf("%d", ++a);//前置++，先++后使用
//	printf("%d", a++);//后置++，先使用后++
//	return 0;
//}


//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//指针的大小
//}
//
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//指针的大小
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

//学生
//创建一个结构体类型--struct Stu
struct Stu
{
	char name[20];
	int age;
	char id[20];
};
//int main()
//{
//	//使用struct Stu这个结构体类型创建了一个学生对象s1，并初始化
//	struct Stu s1 = { "孙德奇",23,"20211101" };
//	struct Stu* ps = &s1;
//	printf("%s\n", ps->name);
//
//	//printf("%s\n", (*ps).name);
//	//printf("%d\n", (*ps).age);
//
//	//printf("%s\n", s1.name);
//	//printf("%d\n", s1.age);
//	//printf("%s\n", s1.id);
//	//结构体变量.成员名
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
//	//整型提升
//	//00000000000000000000000000000011
//	//00000000000000000000000001111111
//	//00000000000000000000000010000010
//	//
//	char c = a + b;
//	//10000010--c
//	//整型提升
//	//11111111111111111111111110000010--补码
//	//11111111111111111111111110000001--反码
//	//10000000000000000000000001111110--原码
//	//-126
//	printf("%d\n", c);
//	return 0;
//}

//整型提升实例：
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
