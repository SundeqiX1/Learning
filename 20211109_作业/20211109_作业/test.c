#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void Init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//void Reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while(left<right)
//	{
//	int temp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = temp;
//	left++;
//	right--;
//    }
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//Init(arr,sz);//初始化数组为0
//	Print(arr, sz);
//	Reverse(arr, sz);
//	Print(arr, sz);
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,10 };
//	int temp = 0;
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//		return 0;
//}

//***************************************************
//写一个函数求a的二进制表示中有几个1
//int count_bit_one(unsigned int n)
//{
//	int count = 0;
//	while(n)
//	{
//	  if(n%2==1)
//	  { 
//		count++;
//	  }
//	   n=n / 2;
//	}
//	return count;
//}


//int count_bit_one(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n >> i) & 1 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//***************************************************
////写一个函数求a的二进制表示中有几个1
//最优算法
//int count_bit_one(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//******************************************************

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	//写一个函数求a的二进制表示中有几个1
//	int count=count_bit_one(a);
//
//	printf("%d\n", count);
//	return 0;
//}

//******************************************************
//求两个整数的二进制中有多少位不同
//int get_diff_bit(int m, int n)
//{
//	int tmp = m ^ n;
//	return count_bit_one(tmp);
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d%d", &m,&n);
//	int count=get_diff_bit(m, n);
//
//	printf("%d\n", count);
//
//	return 0;
//}

//********************************************
//获取一个整数二进制序列中原有的偶数位和奇数位，分别打印出二进制序列
//void print(int m)
//{
//	int i = 0;
//	printf("奇数位");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d",m >> i&1);
//	}
//	printf("\n");
//	printf("偶数位");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", m >> i & 1);
//	}
//	printf("\n");
//}
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	print(m);
//	return 0;
//}

//********************************************
//写一个子函数打印数组--用指针的方式
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//int main()
//{
//	int arr[9] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	return 0;
//}


//********************************************
//实现输出乘法口诀表，输入9即打印9*9乘法口诀表
//void print_table(int n)
//{
//	int i = 0;
//	for (i = 0; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d*%d=%-5d", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_table(n);
//	return 0;
//}

#include <string.h>
//********************************************
//编写函数，把字符串逆序排列后打印（递归实现）
//1.普通实现
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
//void reverse_string(char arr[])
//{
//	int left = 0;
//	int right = my_strlen(arr) - 1;
//	while (left < right)
//	{
//	int tmp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = tmp;
//	left++;
//	right--;
//     }
//}
//2.递归实现
//void reverse_string(char arr[])
//{
//	char tmp = arr[0];
//	int len = my_strlen(arr);
//	arr[0]=arr[len - 1];
//	arr[len - 1] = '\0';
//	if(my_strlen(arr)>=2)
//	reverse_string(arr+1);
//	arr[len - 1] = tmp;
//}
//int main()
//{
//	char arr[] = "abcdefghijklmn";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//***************************************************
//输入一个非负整数，计算其每位数字之和--递归
//int DigitSum(unsigned int num)
//{
//	if (num > 9)
//	{
//		return DigitSum(num / 10) + num % 10;
//	}
//	else
//	{
//		return num;
//	}
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);//1729
//	int ret = DigitSum(num);
//	printf("%d\n", ret);
//	return 0;
//}

//***************************************************
//求n的k次方--递归
double Pow(int n, int k)
{
	//n^k=n*n^(k-1)
	if (k < 0)
		return(1 / (Pow(n, -k)));
	else if (k == 0)
		return 1;
	else
		return n * Pow(n, k - 1);
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d%d", &n,&k);
	double ret = Pow(n,k);
	printf("%lf\n", ret);
	return 0;
}