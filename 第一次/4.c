#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef long long ll;
int main()
{ 
    ll a, b;
    ll c;
    clock_t start, end;
    printf("请输入两个整数a和b: ");
    scanf("%d %d", &a, &b);
    //基础
    start = clock();
    c = (a * b) % 65537;
    printf("乘积取模结果: %lld\n", c);
    end = clock();
    printf("基础取模耗时: %f 秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    //优化
    start = clock();
    ll d=a*b;
    ll d1=d&0xFFFF,d2=(d>>16)&0xFFFF;
    ll result = d1 - d2;
    if (d1 < d2) {
        result += 65537;
    }
    printf("优化结果: %lld\n", result);
    end = clock();
    printf("优化耗时: %f 秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    system("pause");
    return 0;
}