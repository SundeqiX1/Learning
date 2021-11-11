#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//描述一个学生：
//姓名、年龄、电话、性别

//struct  结构体关键字    Stu  结构体标签    struct Stu--结构体标签
//struct Stu
//{
//	//成员变量
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//};//s1,s2,s3;//三个全局的结构体变量

//typedef struct Stu
//{
//	//成员变量
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}Stu;//Stu--为类型
//
//int main()
//{
//	Stu s1 = {"张三",20,11111111111,"男"};//局部结构体变量
//	Stu s2={ "李四",20,11111111111,"男" };
//
//	return 0;
//}
//****************************************************************************
//typedef struct Stu
//{
//	//成员变量
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}Stu;
//void print1(Stu tmp)
//{
//	printf("name:  %s\n", tmp.name);
//	printf("age:   %d\n", tmp.age);
//	printf("tele:  %s\n", tmp.tele);
//	printf("name:  %s\n", tmp.sex);
//}
//void print2(Stu* ps)
//{
//	printf("name:  %s\n", ps->name);
//	printf("age:   %d\n", ps->age);
//	printf("tele:  %s\n", ps->tele);
//	printf("name:  %s\n", ps->sex);
//}
//int main()
//{
//	Stu s1 = {"张三",20,"15751125221","男"};
//	Stu s2={ "李四",20,"11111111111","男" };
//	//打印结构体数据
//	//print1与print2哪个更好？？？
//	//推荐使用print2--传地址
//	print1(s1);
//	print2(&s2);
//	return 0;
//}
//****************************************************************************

int add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}
int main()
{
	int a = 12;
	int b = 22;
	int ret = 0;
	ret = add(a,b);
	return 0;
}