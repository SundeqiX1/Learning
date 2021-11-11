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


//F9--添加断点
//F5--跳转到断点处--执行逻辑上的断点处

//******************************************************
//模拟实现库函数strcpy--字符串拷贝 
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
//优化后1：
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
//优化后2：
//#include <assert.h>
//void my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);//断言
//	assert(src != NULL);//断言
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
//	assert(dest != NULL);//断言
//	assert(src != NULL);//断言
//	//把src指向的字符串内容拷贝到dest指向的空间，包含‘\0’
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
//	//*p = 20;//   error    const放在指针变量*左边时，修饰的是*p，不能通过p来改变*p（num）的值
//	int n = 100;
//	p = &n;//      error     const放在指针变量*右边时，修饰的是指针变量p，p不能被改变
//	printf("%d\n", num);
//	return 0;
//}


//****************************************************
//模拟实现strlen--优化
//#include <assert.h>
//int my_strlen(const char* str)
//{
//	int count;
//	assert(str != NULL);//保证指针的有效性
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