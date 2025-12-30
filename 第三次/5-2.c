#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
typedef long long ll;
int is_prime(int n)
{
    if(n<=1) return 0;
    int i; 
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0) return 0;
    return 1;
}
int main()
{
	printf("Input n(n<=500):");
    int n,cnt=0,ans=0,base[11];
    scanf("%d",&n);
    int i;
    for (i=n;i>=2;i--)
    {
        if(is_prime(i)&&cnt<10)
        {
            printf("%d\t",i);
            base[cnt]=i;
            cnt++;
        }
        if (cnt==10) break;
    }
    printf("\ninput a prime:");
    int x,mid=5,left=0,right=9;
    scanf("%d",&x);
    while (base[mid]!=x)
    {
        if (base[mid]>x)
			left=mid+1;
        else
			right=mid-1;
        mid=(left+right)/2;
    }
    printf("%d\n",mid);
    system("pause");
    return 0;
}