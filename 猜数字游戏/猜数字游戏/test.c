#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//��������Ϸ
//1.���Ի�����һ�������
//2.������
void menu()
{
	printf("******************************\n");
	printf("****   1.play   0.exit   *****\n");
	printf("******************************\n");
}
//RAND_MAX:  0--->32767
void game()
{
	int ret = 0;
	int guess = 0;
	//1.�����������
	//��ʱ���������������
	//time_t time(time_t *timer)
	//ʱ���
	ret=rand()%100+1;//����1-100�����
	//printf("%d\n", ret);
	//2.�����֣�
	while (1)
	{
		printf("�������:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("�¶���\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸʵ��
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}