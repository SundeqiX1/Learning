#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����һ��ѧ����
//���������䡢�绰���Ա�

//struct  �ṹ��ؼ���    Stu  �ṹ���ǩ    struct Stu--�ṹ���ǩ
//struct Stu
//{
//	//��Ա����
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//};//s1,s2,s3;//����ȫ�ֵĽṹ�����

//typedef struct Stu
//{
//	//��Ա����
//	char name[20];
//	short age;
//	char tele[12];
//	char sex[5];
//}Stu;//Stu--Ϊ����
//
//int main()
//{
//	Stu s1 = {"����",20,11111111111,"��"};//�ֲ��ṹ�����
//	Stu s2={ "����",20,11111111111,"��" };
//
//	return 0;
//}
//****************************************************************************
//typedef struct Stu
//{
//	//��Ա����
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
//	Stu s1 = {"����",20,"15751125221","��"};
//	Stu s2={ "����",20,"11111111111","��" };
//	//��ӡ�ṹ������
//	//print1��print2�ĸ����ã�����
//	//�Ƽ�ʹ��print2--����ַ
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