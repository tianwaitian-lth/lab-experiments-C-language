#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
typedef long long ll;
int main()
{
	int n,x=1,ans=0;
    scanf("%d",&n);
    while (n/x!=0)
    {
        x*=2;
    }
    x/=2;
    while (n!=0)
    {
        if (n/x!=0)
            ans++;
        n%=x;
        x/=2;
    }
    // while (x/2!=0)
    // {
    //     printf("0");
    //     x/=2;
    // }
    printf("%d\n",ans);
    system("pause");
    return 0;
}