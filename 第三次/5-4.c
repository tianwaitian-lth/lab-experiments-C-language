#include <stdio.h>
#define SIZE 4
int main()
{
     int gold = 10; //初始用户默认10金币
     char s[SIZE]; //字符数组用于存放用户名
     printf("输入用户名:\n");
     scanf("%s", s);
     printf("%s，你有%d金币\n", s, gold);
}