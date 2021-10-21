#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//int main()
//{
//	//int arr[10] = {1,2,3};//不完全初始化，剩下的元素初始化为0； 
//	char arr2[] = "abcdef";
//	printf("%d\n", sizeof(arr2));
//	//sizeof  计算arr2所占空间大小
//	//7个元素
//	printf("%d\n", strlen(arr2));
//	//strlen  求字符串长度   '\0'之前的字符个数
//	//[a b c d e f \0]
//	return 0;
//}
//**************************************************
//1.strlen 和 sizeof  没有什么关联
//2.strlen 是求字符串长度的--只能针对字符串求--库函数--使用时需要引用头文件
//3.sizeof 计算变量、数组、类型的大小--单位是字节--操作符--

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));
//	printf("%d\n", sizeof(arr2));
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	return 0;
//}

//int main()
//{
//	//char arr[] = "abcdef";
//	////printf("%d\n", arr[3]);
//	//int i = 0;
//	//int len = strlen(arr);
//	//for (i = 0; i <len; i++)
//	//{
//	//	printf("%c\n", arr[i]);
//	//}
//	return 0;
//}

//**************************
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int se = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < se; i++)
//	{
//		printf("&arr[%d]%p\n",i, &arr[i]);
//	}
//	return 0;
//}

//**************
//int main()
//{
//	int arr[3][4] = {{1,2,3},{4,5}};
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d]=%p\n",i,j,&arr[i][j]);
//		}
//	}
//	//char ch[5][6];
//	//int arr[][4] = { {1,2,3,4},{5,6,7,8} };
//	return 0;
//}

//***********************************************
void bubble_sort(int arr[],int sz)
{
	//确定冒泡排序的趟数
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//假设这一趟要排的数据已经有序
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//本趟排序数据不完全有序
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

}
int main() 
{
	int arr[] = {9,1,2,3,4,5,6,7,8};
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//对其进行排序，排成升序
	//对数组arr进行传参，实际上传递的是数组arr首元素的地址--&arr[0]
	bubble_sort(arr,sz);//冒泡排序函数
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}