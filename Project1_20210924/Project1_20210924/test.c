#define _CRT_SECURE_NO_WARNINGS 1
//����һ����stdio.h���ļ�
//std-��׼standard     i-input     o-output 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  int �����͵���˼
//mainǰ���int��ʾmain�������÷���һ������ֵ
//int main()//������-��������-main��������ֻ��һ��
//{
//	//�����������
//	//����Ļ�����hellow world
//	//����-printf - print function ��ӡ����
//	//�⺯��-C���Ա����ṩ�ĺ���
//	//���˵ĺ���-���к�
//	//#include
//	printf("hello world\n");
//	return 0;//����0
//} 
//�����ã�
//void main()
//{
//}

//int main()
//{
//	char ch = 'A';//�ڴ�
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


//#define ����ı�ʶ������
//#define MAX 10

	//const-������
	//const int num = 4;
	////const���εĳ�������

      //���泣��
	//3;
	//5;

//ö�ٳ���
//ö�ٹؼ��� - enum 

//enum Sex
//{
//MALE,
//FEMALE,
//SEGRET
//};

//int main()
//{
//	//ASCII����
//	
//	//char arr[] = "abc";//����
//	////"abc"--'a''b''  c''\0'   '\0' �ַ����Ľ�����־
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
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//����һ�����10���������ֵ�����
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
//	//��λ(2����)������
//	//<<����
//	//>>����
//	int a = 1;
//	int b=a << 3;
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}
//int main()
//{
//    // & ��λ��   ��0Ϊ0��ȫ1Ϊ1
//	// | ��λ��   ��1Ϊ1��ȫ0Ϊ0
//	// ^ ��λ���  ��ͬΪ0����ͬΪ1
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
//	int b = ~a;   //�з��ŵ����� //11111111111111111111111111111111
//	 //   ԭ�롢���롢���룻
//		//�������ڴ��д洢��ʱ�򣬴洢���Ƕ����Ʋ��룻
//		//	���룺11111111111111111111111111111111
//		//	���룺11111111111111111111111111111110
//		//	ԭ�룺10000000000000000000000000000001
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
//	arr[4];//[]-�±����ò�������
//	int a = 10;
//	int b = 20;
//	int sum = add(a, b);//()-�±����ò�������
//	return 0;
//}

//int main()
//{
//	register int a = 10;//register�ؼ���--�����a����ɼĴ�������
//	//signed int;�����з�������
//	//unsigned int;�����޷�������
//	return 0;
//}
 //int main()
 //{
	// //typedef--�����ض��壻
	// typedef unsigned int u_int;
	// unsigned int num = 20;
	// u_int num = 10;
	// return 0;
 //}
//void test()
//{
//	static int a = 1;//aΪ��̬�ֲ�����
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
//	//extern - �����ⲿ����
//	extern int g_val;
//	printf("%d\n", g_val);
//	return 0;
//}
//�����ⲿ����
//extern int Add(int, int);
//int main()
//{
//	int a = 10;
//	int b =20;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}
//#define ����ı�ʶ������
//#define MAX 100
//#define ���Զ����-������


//������ʵ��
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
////��Ķ���
//#define MAX(X,Y) (X>Y?X:Y)
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//����
//	//int max = Max(a, b);
//	//printf("max=%d\n", max);
//	//��
//	int max = MAX(a, b);
//	printf("max=%d\n", max);
//	return 0;
//}
//int  main()
//{
//	int a = 10;//�����ĸ��ֽ�
//	int* p=&a;//ȡ����ַ
//	//һ�ִ�ŵ�ַ�ı���--ָ�����
//	/*printf("%p\n", &a);*/
//	//printf("%p\n", &a);
//	//printf("%p\n", p);
//	*p=20;//*--�����ò�������
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
 

//����һ���ṹ������
//struct Book
//{
//	char name[20];//C���Գ������
//	short price;//55
//};
//int main()
//{
//	//���ýṹ�����ʹ���һ�������͵Ľṹ�����
//	struct Book b1 = { "C���Գ������",55 }; 
//	strcpy(b1.name,"C++" );//  strcpy`--string copy �ַ�������-�⺯��-string.h
//	printf("������%s\n", b1.name);
////	//printf("�۸�%d\n", b1.price);
////	/*printf("������%s\n", (*pb).name);
////	printf("�۸�%d\n", (*pb).price);*/
//	//printf("������%s\n", pb->name);
////	//printf("�۸�%d\n", pb->price);
////
//		return 0;
//}


//*************************
//shutdown -s -t 60  ����60s��ػ�
//shutdown -a       ȡ���ػ�
//system()-ִ��ϵͳ����  <stdlib.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	again:
//	printf("��ĵ��Խ���1�����ڹػ���������룺������ȡ���ػ�\n������>:");
//	scanf("%s", input);
//	if (strcmp(input, "������") == 0)//�Ƚ������ַ���-strcmp
//	{
//		system("shutdown -a ");
//    }
//	else
//	{
//		goto again;
//	}
//	return 0;
//}