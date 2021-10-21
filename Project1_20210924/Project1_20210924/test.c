#define _CRT_SECURE_NO_WARNINGS 1
//包含一个叫stdio.h的文件
//std-标准standard     i-input     o-output 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  int 是整型的意思
//main前面的int表示main函数调用返回一个整型值
//int main()//主函数-程序的入口-main函数有且只有一个
//{
//	//这里完成任务
//	//在屏幕上输出hellow world
//	//函数-printf - print function 打印函数
//	//库函数-C语言本身提供的函数
//	//别人的函数-打招呼
//	//#include
//	printf("hello world\n");
//	return 0;//返回0
//} 
//不常用：
//void main()
//{
//}

//int main()
//{
//	char ch = 'A';//内存
//	printf("%c\n", ch);
//	return 0;
//}

//int main()
//{
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//
//	return 0;
//}


//#define 定义的标识符常量
//#define MAX 10

	//const-常属性
	//const int num = 4;
	////const修饰的常变量；

      //字面常量
	//3;
	//5;

//枚举常量
//枚举关键字 - enum 

//enum Sex
//{
//MALE,
//FEMALE,
//SEGRET
//};

//int main()
//{
//	//ASCII编码
//	
//	//char arr[] = "abc";//数组
//	////"abc"--'a''b''  c''\0'   '\0' 字符串的结束标志
//	////'\0'=0
//	////'a'=97
//	//char arr2[] = { 'a','b','c',0 };
//	//printf("%s\n", arr);
//	//printf("%s\n", arr2);
//	return 0;
//} 
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = Add(10, 20);
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义一个存放10个整数数字的数组
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d\n", arr[i]);
//		i++;
//	}
//	return 0; 
//}

//int main()
//{
//	//移位(2进制)操作符
//	//<<左移
//	//>>右移
//	int a = 1;
//	int b=a << 3;
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}
//int main()
//{
//    // & 按位与   有0为0，全1为1
//	// | 按位或   有1为1，全0为0
//	// ^ 按位异或  相同为0，不同为1
//	int a = 5;
//	int b = 3;
//	int c = a & b;
//	printf("%d\n", c);
//		return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int arr[] = { 1,2,3,4,5,6 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof a);
//	return 0;
//}
//int main()
//{
//	int a = 0;    //  //00000000000000000000000000000000
//	int b = ~a;   //有符号的整型 //11111111111111111111111111111111
//	 //   原码、反码、补码；
//		//负数在内存中存储的时候，存储的是二进制补码；
//		//	补码：11111111111111111111111111111111
//		//	反码：11111111111111111111111111111110
//		//	原码：10000000000000000000000000000001
//	printf("%d\n", b);//b=-1
//		return 0;
//}
//int main()
//{
//	int a = (int)3.14;
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a = 100;
//	int b = 20;
//	int max = 0;
//	max = (a > b ? a : b);
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	arr[4];//[]-下标引用操作符；
//	int a = 10;
//	int b = 20;
//	int sum = add(a, b);//()-下标引用操作符；
//	return 0;
//}

//int main()
//{
//	register int a = 10;//register关键字--建议把a定义成寄存器变量
//	//signed int;定义有符号整型
//	//unsigned int;定义无符号整型
//	return 0;
//}
 //int main()
 //{
	// //typedef--类型重定义；
	// typedef unsigned int u_int;
	// unsigned int num = 20;
	// u_int num = 10;
	// return 0;
 //}
//void test()
//{
//	static int a = 1;//a为静态局部变量
//	a++;
//	printf("%d\n", a);
//}
//int main()
//{
//	int i = 0;
//	while (i<5)
//	{
//		test();
//		i++;
//	}
//		return 0;
//} 
//int main()
//{
//	//extern - 声明外部符号
//	extern int g_val;
//	printf("%d\n", g_val);
//	return 0;
//}
//声明外部函数
//extern int Add(int, int);
//int main()
//{
//	int a = 10;
//	int b =20;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
//#define 定义的标识符常量
//#define MAX 100
//#define 可以定义宏-带参数


//函数的实现
//int Max(int x, int y) 
//{
//	if (x > y)
//	{
//		return x;
//	else
//		return y;
//	}
//}
//
//
////宏的定义
//#define MAX(X,Y) (X>Y?X:Y)
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//函数
//	//int max = Max(a, b);
//	//printf("max=%d\n", max);
//	//宏
//	int max = MAX(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}
//int  main()
//{
//	int a = 10;//申请四个字节
//	int* p=&a;//取出地址
//	//一种存放地址的变量--指针变量
//	/*printf("%p\n", &a);*/
//	//printf("%p\n", &a);
//	//printf("%p\n", p);
//	*p=20;//*--解引用操作符；
//	printf("a=%d\n", a);
//		return 0;
//} 
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 'a';
//	printf("%c\n", ch);
//	return 0;
//}
 

//创建一个结构体类型
//struct Book
//{
//	char name[20];//C语言程序设计
//	short price;//55
//};
//int main()
//{
//	//利用结构体类型创建一个该类型的结构体变量
//	struct Book b1 = { "C语言程序设计",55 }; 
//	strcpy(b1.name,"C++" );//  strcpy`--string copy 字符串拷贝-库函数-string.h
//	printf("书名：%s\n", b1.name);
////	//printf("价格：%d\n", b1.price);
////	/*printf("书名：%s\n", (*pb).name);
////	printf("价格：%d\n", (*pb).price);*/
//	//printf("书名：%s\n", pb->name);
////	//printf("价格：%d\n", pb->price);
////
//		return 0;
//}


//*************************
//shutdown -s -t 60  电脑60s后关机
//shutdown -a       取消关机
//system()-执行系统命令  <stdlib.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	again:
//	printf("你的电脑将在1分钟内关机。如果输入：我是猪，取消关机\n请输入>:");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)//比较两个字符串-strcmp
//	{
//		system("shutdown -a ");
//    }
//	else
//	{
//		goto again;
//	}
//	return 0;
//}