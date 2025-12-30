#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef long long ll;
int main()
{ 
    printf("请输入两个整数a和b，用空格隔开：");
	int a,b;
    scanf("%d %d",&a,&b);
    if (b==0)
        printf("除数不能为0");
    else if ((a>65535||a<-65536)||(b>65535||b<-65536))
        printf("结果超出范围");
    else
    {
    printf("%d\n",a+b);
    printf("%d\n",a*b);
    printf("%d\n",a-b);
    printf("%d\n",a/b);
    printf("%d\n",a%b);
    }
    system("pause");
    return 0;
}