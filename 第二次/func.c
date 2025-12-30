#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
typedef long long ll;
int main()
{
	double x;
    scanf("%lf",&x);
    if (x<-1)
        printf("%.2f",x*(-1));
    else if (x>1)
        printf("%.2f",x*x);
    else
        printf("%.2f",2*x+1);
    system("pause");
    return 0;
}