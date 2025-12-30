#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
typedef long long ll;
int main()
{
	/*25列，13行的等腰杨辉三角*/
    int a[13][25] = {0};
    for(int i = 0;i < 13;i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for(int i = 2;i < 13;i++)
    {
        for(int j = 1;j < i;j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for(int i = 0;i < 13;i++)
    {
        for (int k=0;k<(13-i);k++)
                printf("   ");
        for(int j = 0;j <= i;j++)
        {
            if (a[i][j]>=100)
                printf("   ");
            else if (a[i][j]>=10)
                printf("    ");
            else
                printf("     ");
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}