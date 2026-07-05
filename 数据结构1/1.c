#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;
void Merge(int a[],int b[], int** c,int x,int y)
{
    int i=0,j=0,k=0;
    *c=(int *)malloc((x+y+1)*sizeof(int));
    while (i<x&&j<y)
    {
        if (a[i]<=b[j])
        {
            (*c)[k++]=a[i++];
        }
        else
        {
            (*c)[k++]=b[j++];
        }
    }
    while (i<x)
    {
        (*c)[k++]=a[i++];
    }
    while (j<y)
    {
        (*c)[k++]=b[j++];

    }
}
int main()
{
    int x,y;
    scanf("%d", &x);
    int a[x];
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &y);
    int b[y];
    for (int i = 0; i < y; i++)
    {
        scanf("%d", &b[i]);
    }
    int *c=NULL;
    Merge (a,b,&c,x,y);
    for (int i = 0; i < x+y; i++)
    {
        printf("%d ", c[i]);
    }
    free(c);
    return 0;
}