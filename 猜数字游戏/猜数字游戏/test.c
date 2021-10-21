#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//猜数字游戏
//1.电脑会生成一个随机数
//2.猜数字
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
	//1.生成随机数；
	//用时间戳设置随机数起点
	//time_t time(time_t *timer)
	//时间戳
	ret=rand()%100+1;//生成1-100随机数
	//printf("%d\n", ret);
	//2.猜数字；
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
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
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏实现
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}