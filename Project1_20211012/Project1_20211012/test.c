#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;
//		printf("%d\n", i);
//		i++;
//	}
//	while (i<= 10);
//	return 0;
//}
//int main()
//{
//	int x, y;
//	for (x = 0,y = 0; x < 2 && y < 5; ++x, y++)
//	{
//		printf("hh\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 10; i++)
//	{
//		for (j=0; j < 10; j++)
//		{
//			printf("hh\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	for (;;)
//	{ 
//		printf("hheh\n");
//	}
//		return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d\n", i);
//	}
//	return 0;
//} 

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch<'0' || ch>'9')
//			continue;
//		putchar(ch);
//    }
//	return 0;
//}

//int main()
//{
//	int ret = 0;
//	int ch = 0;
//	char password[20] = {0};
//	printf("����������>");
//	scanf("%s", password);//�������룬�������password������
//	//��������ʣ'\n'
//	//��ȡһ��'\n'
//	while(ch=getchar()!='\n');
//	{
//		; 
//	}
//	printf("��ȷ�ϣ�Y/N��:>");
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ��\n");
//	}
//	return 0;
//}

//int ch = 0;
////ctrl+z
////EOF-end of file-->-1    �ļ�������־
//while ((ch = getchar()) != EOF)
//{
//	putchar(ch);
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d \n", i);
//		i++;
//	}
	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		break;
	//	printf("%d \n", i);
	//	i++;
	//}
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n)
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//		break;
//	default:
//		break;
//	}
//	printf("m=%d\nn=%d\n", m,n);
//	return 0;
//}

//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//		case 1:
//        case 2:
//        case 3:
//        case 4:
//        case 5:
//	printf("������\n");
//	break;
//        case 6:
//        case 7:
//	printf("��Ϣ��\n");
//	break;
//		default:
//			printf("�������\n");
//			break;
	//case 1:
	//	printf("����һ\n");
	//	break;
	//case 2:
	//	printf("���ڶ�\n");
	//	break;
	//case 3:
	//	printf("������\n");
	//	break;
	//case 4:
	//	printf("������\n");
	//	break;
	//case 5:
	//	printf("������\n");
	//	break;
	//case 6:
	//	printf("������\n");
	//	break;
	//case 7:
	//	printf("������\n");
	//	break;
//	}
//
//	return 0;
//}



//int main()
//{
//	int x = 0;
//	while (x<=100)
//	{
//		if (1 == x % 2)
//		{
//			printf("x=%d\n", x);
//		}
//		x++;
//	}
//		return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 0)
//		if (b == 2)
//			printf("hehe\n");
//	    else
//			printf("haha\n");
//	return 0;
//}
//int main()
//{
//	int age = 100;
//	if (age < 18)
//	{
//		printf("δ����\n");
//		printf("����̸����\n");
//	}
//	else
//	{
//		if (age < 28 && age >= 18)
//			printf("����\n");
//		else if (age < 50 && age >= 28)
//			printf("����\n");
//		else if (age < 90 && age >= 50)
//			printf("����\n");
//		else
//	        printf("����\n");
//	}
	//int age = 100;
	//if (age < 18)
	//	printf("δ����\n");
	//else if(age<28&&age>=18)
	//	printf("����\n");
	//else if (age <50&& age >= 28)
	//	printf("����\n");
	//else if (age < 90 && age >= 50)
	//	printf("����\n");
	//else
	//	printf("����\n");
	//if (age < 18)
	//printf("δ����\n");
	//else
	//	printf("����\n");
	//if (age < 18)
	//	printf("δ����\n");
//		return 0;
//}