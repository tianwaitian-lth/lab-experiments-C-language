#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,k;
    scanf("%d", &n);
    int a[n+1],prefix[n+1],pre[n+1];
    memset(prefix,0,sizeof(prefix));
    memset(pre,0,sizeof(pre));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i]%2!=0)
            prefix[i]=1;
        else
            prefix[i]=0;
        pre[i]=prefix[i]+pre[i-1];
    }
    scanf("%d", &k);
    int ans = 0, num = 0, i = 1, j = 1;
    while (j <= n)
    {
        num = pre[j] - pre[i-1];
        // 情况 1：奇数不够，右指针继续往右拉
        if (num < k) 
        {
            j++;
        }
        // 情况 2：奇数超标了，左指针往右缩
        else if (num > k) 
        {
            i++;
        }
        // 情况 3：正好满足 k 个奇数
        else if (num == k) 
        {
            int temp = i;
            // 用 temp 往后探路，看看后面还有多少个连续的偶数
            // 只要满足 pre[temp-1] == pre[i-1]，说明从 i 到 temp-1 全是偶数，都可以作为合法的起点
            while (temp <= j && pre[temp-1] == pre[i-1]) 
            {
                temp++;
            }
            ans += (temp - i);
            // 右指针继续往后走，看看后面还有没有偶数能白嫖
            j++;
        }
    }
    printf("%d", ans);
    return 0;
}