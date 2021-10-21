#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
//1.计算n的阶乘
//int main()
//{
//	int x,y,i;
//	y = 1;
//	scanf("%d", &x);
//	if (x == 0)
//		y = 0;
//	else if (x < 0)
//	{
//		printf("输入错误");
//	}
//	else
//	{
//		for (i = 1; i<=x; i++)
//	{
//			y = i * y;
//	}
//		printf("%d的阶乘为%d", x, y);
//	}
//	return 0;
//}

//2.计算1！+2！+3！+4！+5！+6！+7！+8！+9！+10！
//int main()
//{
//	int x, y, i,j;
//	y = 1;
//	x = 0;
//	for(j=1;j<=10;j++)
//	{ 
//		y = 1;
//		for (i = 1; i <= j; i++)
//		{
//			y = i * y;
//		}
//		 x = x + y;
//	}	
//	printf("%d",x);
//		return 0;
//}
//int main()
//{
//	int x, y, i, j;
//		y = 1;
//		x = 0;
//		for(j=1;j<=10;j++)
//		{ 
//			y = y * j;
//			x = x + y;
//		}	
//		printf("%d",x);
//	return 0;
//}


//3.折半查找法
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 17;
//	int se = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;//左下标
//	int right = se - 1;//右下标
//	while(left<=right)
//	{
//	int mid = (left + right) / 2;
//	if (arr[mid] > k)
//	{
//		right = mid - 1;
//	}
//	else if (arr[mid] < k)
//	{
//		left = mid + 1;
//	}
//	else
//	{
//		printf("找到%d", mid);
//		break;
//	}
//    }
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}

//4.
//int main()
//{
//	char arr1[] = "wlcome to bit!!!!!!";
//	char arr2[] = "###################";
//	int left = 0;
//	//int right = sizeof(arr1) / sizeof(arr1[0]) - 2;
//	int right = strlen(arr1) - 1;
//	while(left<=right)
//	{ 
//	arr2[left] = arr1[left];
//	arr2[right] = arr1[right];
//	printf("%s\n",arr2);
//	//休息一秒；
//	Sleep(1000);
//	system("cls");//执行系统命令的函数   -cls -清空屏幕
//	left++;
//	right--;
//	}
//	return 0;
//}


//5.
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", &password);
//		if (strcmp(password ,"123456")==0)//==不能 用来比较字符串是否相等，应该使用一个库函数-strcmp
//		{
//			printf("登陆成功");
//				break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码错误");
//	}
//	return 0;
//}