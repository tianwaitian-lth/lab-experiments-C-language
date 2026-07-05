#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000];
    if (scanf("%s", s) != 1) return 0;
    
    int a[1000], len = strlen(s), k = 0;
    for (int i = 0; i < len && k < 1000; )
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int tmp = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9')
            {
                tmp = tmp * 10 + (s[i] - '0');
                i++;
            }
            a[k++] = tmp;
        }
        else
        {
            i++;
        }
    }
    
    //double pointer sort,only 0 1 2 three nums
    int ter1=0,ter2=k-1;
    for (int i=0;i<k;i++)
    {
        if (a[i]==0)
            ter1++;
        else if (a[i]==2)
            ter2--;
    }

    printf("[");
    for (int i=0;i<k;i++)
    {
        if (i<ter1)
            printf("0");
        else if (i>=ter1 && i<=ter2)
            printf("1");
        else
            printf("2");
        printf(i==k-1?"]\n":",");
    }
    return 0;
}