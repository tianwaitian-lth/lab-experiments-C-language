#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
typedef long long ll;
int main()
{
    printf("version:1/2\n");
    int x;
    scanf("%d",&x);
    if (x==1)
    {
        char a[5][1145],b[6]={0};
		scanf("%s %s %s %s %s",a[0],a[1],a[2],a[3],a[4]);
		for (int i=0;i<4;i++)
		{
			for (int j=i+1;j<=4;j++)
			{
				if (strlen(a[j])<strlen(a[i]))
				{
					char t[1145];
					strcpy(t,a[j]);
					strcpy(a[j],a[i]);
					strcpy(a[i],t);
				}
			}
		}
		for (int i=0;i<5;i++)
		{
			if (strlen(a[i])<3)
			{
				b[i]=' ';
			}
			else
			{
				b[i]=a[i][2];
			}
		}
		printf("%s",b);
    }
    else if (x==2)
    {
        char *a[5],*b;
		b=malloc(6*sizeof(char));
		a[0]=malloc(1145*sizeof(char));
		a[1]=malloc(1145*sizeof(char));
		a[2]=malloc(1145*sizeof(char));
		a[3]=malloc(1145*sizeof(char));
		a[4]=malloc(1145*sizeof(char));
		scanf("%s %s %s %s %s",a[0],a[1],a[2],a[3],a[4]);
		for (int i=0;i<4;i++)
		{
			for (int j=i+1;j<=4;j++)
			{
				if (strlen(*(a+j))<strlen(*(a+i)))
				{
					char t[1145];
					strcpy(t,*(a+j));
					strcpy(*(a+j),*(a+i));
					strcpy(*(a+i),t);
				}
			}
		}
		for (int i=0;i<5;i++)
		{
			if (strlen(a[i])<3)
			{
				b[i]=' ';
			}
			else
			{
				b[i]=a[i][2];
			}
		}
		printf("%s",b);
		for (int i=0;i<5;i++)
		{
			free(a[i]);
		}
		free(b);
    }
    else
    {
        printf("error");
    }
    return 0;
}