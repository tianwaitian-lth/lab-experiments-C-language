#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
typedef long long ll;
int is_prime(int n)
{
    if(n<=1) return 0;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0) return 0;
    return 1;
}
int main()
{
	printf("Input n(n<=500):");
    int n,cnt=0,ans=0;
    scanf("%d",&n);
    for (int i=n;i>=2;i--)
    {
        if(is_prime(i)&&cnt<10)
        {
            printf("%d\t",i);
            cnt++;
            ans+=i;
        }
        if (cnt==10) break;
    }
    printf("\nsum=%d\n",ans);
    system("pause");
    return 0;
}