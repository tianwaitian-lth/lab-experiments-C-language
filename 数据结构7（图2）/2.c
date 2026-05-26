#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10002

int adj[N][3];         // 静态邻接表，存邻居
int adj_size[N] = {0}; // 记录每个花园现在的邻居数
int color[N] = {0};    // 存最终每个花园种的花（1~4）

int main()
{
    int n, m;
    // 直接用标准 scanf，安稳等人输入，绝不跑飞
    if (scanf("%d%d", &n, &m) != 2) return 0;
    
    // 1. 构建邻接表
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a][adj_size[a]++] = b;
        adj[b][adj_size[b]++] = a;
    }
    
    // 2. 核心染色逻辑（位运算状态压缩版）
    for (int i = 1; i <= n; i++)
    {
        int mask = 0; // 用一个整数的二进制位当“黑名单开关”
        
        // 把所有邻居的颜色在 mask 中标记为 1
        for (int j = 0; j < adj_size[i]; j++)
        {
            int neighbor = adj[i][j];
            mask |= (1 << color[neighbor]); 
        }
        
        // 从颜色 1 到 4 挨个查，哪一位还是 0 就可以用
        for (int j = 1; j <= 4; j++)
        {
            if (!(mask & (1 << j))) 
            {
                color[i] = j;
                break;
            }
        }
    }
    
    // 3. 严格按要求输出
    for (int i = 1; i <= n; i++)
    {
        printf("%d", color[i]);
        if (i < n) 
        {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}