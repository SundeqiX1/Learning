#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//int main()
//{
//	//int arr[10] = {1,2,3};//����ȫ��ʼ����ʣ�µ�Ԫ�س�ʼ��Ϊ0�� 
//	char arr2[] = "abcdef";
//	printf("%d\n", sizeof(arr2));
//	//sizeof  ����arr2��ռ�ռ��С
//	//7��Ԫ��
//	printf("%d\n", strlen(arr2));
//	//strlen  ���ַ�������   '\0'֮ǰ���ַ�����
//	//[a b c d e f \0]
//	return 0;
//}
//**************************************************
//1.strlen �� sizeof  û��ʲô����
//2.strlen �����ַ������ȵ�--ֻ������ַ�����--�⺯��--ʹ��ʱ��Ҫ����ͷ�ļ�
//3.sizeof ������������顢���͵Ĵ�С--��λ���ֽ�--������--

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
	//ȷ��ð�����������
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;//������һ��Ҫ�ŵ������Ѿ�����
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//�����������ݲ���ȫ����
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
	//������������ų�����
	//������arr���д��Σ�ʵ���ϴ��ݵ�������arr��Ԫ�صĵ�ַ--&arr[0]
	bubble_sort(arr,sz);//ð��������
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}