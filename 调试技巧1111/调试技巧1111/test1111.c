#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		printf("%d ", i);
//	}
//	system("pause");
//	return 0;
//}


//F9--��Ӷϵ�
//F5--��ת���ϵ㴦--ִ���߼��ϵĶϵ㴦

//******************************************************
//ģ��ʵ�ֿ⺯��strcpy--�ַ������� 
//void my_strcpy(char* dest,char* src)
//{
//	while (*src!='\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;//'0'
//}
//�Ż���1��
//void my_strcpy(char* dest, char* src)
//{
//	if (dest != NULL && src != NULL)
//	{
//		while (*dest++ = *src++)
//		{
//			;
//		}
//	}
//}
//�Ż���2��
//#include <assert.h>
//void my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);//����
//	assert(src != NULL);//����
//		while (*dest++ = *src++)
//		{
//			;
//		}
//
//}
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);//����
//	assert(src != NULL);//����
//	//��srcָ����ַ������ݿ�����destָ��Ŀռ䣬������\0��
//		while (*dest++ = *src++)
//		{
//			;
//		}
//		return ret;
//}
//int main()
//{
//	char arr1[] = "####################";
//	char arr2[] = "bit";
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}
//****************************************************
//int main()
//{
//	const int num = 10;
//	//const int* p = &num;
//	 int* const p = &num;
//	//*p = 20;//   error    const����ָ�����*���ʱ�����ε���*p������ͨ��p���ı�*p��num����ֵ
//	int n = 100;
//	p = &n;//      error     const����ָ�����*�ұ�ʱ�����ε���ָ�����p��p���ܱ��ı�
//	printf("%d\n", num);
//	return 0;
//}


//****************************************************
//ģ��ʵ��strlen--�Ż�
//#include <assert.h>
//int my_strlen(const char* str)
//{
//	int count;
//	assert(str != NULL);//��ָ֤�����Ч��
//	while (*str != '\0')
//	{
//		count++;
//		str ++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}