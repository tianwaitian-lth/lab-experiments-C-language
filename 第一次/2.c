#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef long long ll;
int main()
{ 
    int a,b;
    printf("输入范围：0~65535\n"); 
    scanf("%d %d",&a,&b);
    if (a>65535||b>65535||a<0||b<0)
    {    
        printf("输入超出范围\n");
        system("pause");
        return 1;
    }
    unsigned short int c=a,d=b;
    if ((ll)c*d>4294836225)
    {
        printf("输出超出范围\n");
        system("pause");
        return 1;
    }
    printf("%lld\n",c*d);
    printf("输出范围：0~4294836225\n");
    system("pause");
    return 0;
}