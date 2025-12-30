#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
typedef long long ll;
int main()
{
    srand(time(0));
	int *a,*b;
    int cnt=0;
    a=malloc(6*sizeof(int));
    b=malloc(6*sizeof(int));
    for (int i=0;i<6;i++)
    {
        a[i]=rand()%10;
        scanf("%d",b+i);
    }
    for (int i=0;i<6;i++)
        if (*(a+i)==*(b+i))
            cnt++;
    printf("%d",cnt);
    return 0;
}
