#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
//1.����n�Ľ׳�
//int main()
//{
//	int x,y,i;
//	y = 1;
//	scanf("%d", &x);
//	if (x == 0)
//		y = 0;
//	else if (x < 0)
//	{
//		printf("�������");
//	}
//	else
//	{
//		for (i = 1; i<=x; i++)
//	{
//			y = i * y;
//	}
//		printf("%d�Ľ׳�Ϊ%d", x, y);
//	}
//	return 0;
//}

//2.����1��+2��+3��+4��+5��+6��+7��+8��+9��+10��
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


//3.�۰���ҷ�
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int k = 17;
//	int se = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;//���±�
//	int right = se - 1;//���±�
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
//		printf("�ҵ�%d", mid);
//		break;
//	}
//    }
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
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
//	//��Ϣһ�룻
//	Sleep(1000);
//	system("cls");//ִ��ϵͳ����ĺ���   -cls -�����Ļ
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
//		printf("���������룺>");
//		scanf("%s", &password);
//		if (strcmp(password ,"123456")==0)//==���� �����Ƚ��ַ����Ƿ���ȣ�Ӧ��ʹ��һ���⺯��-strcmp
//		{
//			printf("��½�ɹ�");
//				break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("�����������");
//	}
//	return 0;
//}