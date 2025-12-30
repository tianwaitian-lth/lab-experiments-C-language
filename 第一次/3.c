#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef long long ll;
int main()
{ 
    ll a, b;
    ll c;
    printf("请输入两个整数a和b: ");
    scanf("%d %d", &a, &b);
    //基础
    c = (a * b) % 65536;
    printf("乘积取模结果: %u\n", c);
    //优化1
    c = (a * b) & 0xFFFF;
    printf("位运算优化结果: %u\n", c);
    //优化2
    c=((a& 0xFFFF)*(b& 0xFFFF))& 0xFFFF;
    printf("分解取模优化结果: %u\n", c);
    system("pause");
    return 0;
}