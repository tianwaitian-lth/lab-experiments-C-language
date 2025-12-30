#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
typedef long long ll;
void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
	srand(time(0));
    int* p=malloc(101*sizeof(int));
    for(int i=0;i<100;i++)
        p[i]=rand();
    for (int i=0;i<100;i++)
    {
        for (int j=0;j<100;j++)
        {
            if (p[i]<p[j])
            {
                swap(&p[i],&p[j]);
            }
        }
    }
    for (int i=0;i<100;i++)
    {
        printf("%d ",p[i]);
    }
    free(p);
    getchar();
    return 0;
}
