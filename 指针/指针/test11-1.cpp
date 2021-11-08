#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	//printf("%d\n", sizeof(char*));
//	//printf("%d\n", sizeof(short*));
//	//printf("%d\n", sizeof(int*));
//	//printf("%d\n", sizeof(double*));
//	int a = 0x11223344;
//	int* pa = &a;
//	//char* pc = &a;
//	printf("%p\n", pa);
//	//printf("%p\n", pc);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int* p=arr;//数组名-首元素地址
//	int i = 0;
//	for (i = 0; i < 1; i++)
//	{
//		*(p + i) = 1;
//	}
//	return 0;
//}

//野指针--内存已经还给计算机
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf("%d\n",*p);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int * pa = &a;
//	int* p = NULL;//NULL--用来初始化指针 
//
//}

//指针+数字
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *p);
//		p = p + 1;
//	}
//	return 0;
//}

//指针-指针---得到指针之间的元素个数
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n",&arr[9] - &arr[0]);
//	return 0;
//}\

//int my_strlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++; 
//	}
//	return end - start;
//}
//int main()
//{
//	//strlenp--求字符串长度
//	//递归--模拟实现了strlen--计数器的方式1，递归的方式2
//	//
//	char arr[] = "bit";
//
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//指针的关系运算--c语言中。指针可以与其后面的指针进行比较，但是不能与其前面的指针进行比较


//int main()
//{
//	int arr[10] = { 0 };//数组名--首元素地址
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	//1.&arr--&数组名--数组名不是首地址，数组名表示整个数组-  &数组名  取出的是整个数组的地址
//	//2.sizeof(arr)--sizeof(数组名)--数组名代表整个数组----sizeof(数组名)计算的是整个数组的大小
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;//ppa为二级指针
//	int*** pppa = &ppa;//三级指针
//	//......
//	return 0;
//}

//指针数组----数组--存放指针的数组
//数组指针---指针

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* pa = &a;
//	int* pb = &b;
//	int* pc = &c;
//	//整型数组--存放整型
//	//字符数组--存放字符
//	//指针数组--存放指针
//	//int arr[10];
//	int* arr[3] = { &a,&b,&c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ",*(arr[i]));
//	}
//	return 0;
//}
