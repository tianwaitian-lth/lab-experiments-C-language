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
        char week[7][14]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
        int n;
        scanf("%d",&n);
        printf("%s",week[n-1]);
    }
    else if (x==2)
    {
        const char *s[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
        int n;
        scanf("%d",&n);
        printf("%s",*(s+n-1));
    }
    else
    {
        printf("error");
    }
    return 0;
}