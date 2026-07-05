#include <stdio.h>
#include <stdlib.h>

#define MAXN 105
#define INF 0x3f3f3f3f

int map[MAXN][MAXN];
int dist[MAXN][MAXN];

int main()
{
    FILE *fp;
    fp = fopen("in.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open in.txt\n");
        return 1;
    }
    int n, m;
    fscanf(fp, "%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        fscanf(fp, "%d%d%d", &u, &v, &w);
        if (w < map[u][v]) { // 如果有多条边，保留权重较小的那条
            map[u][v] = w;
            map[v][u] = w;
        }
    }

    //initial dist
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = map[i][j];

    //Floyd

    int mincyl = INF;
    for (int k = 1; k <= n; k++)
    {
        //1.先找包含点k的最小环是否存在
        //当我们刚进入外层第 k 轮循环时，dist[i][j] 里记录的最短路径,
        //里面允许拐弯路过的所有中间景区,
        //但是这些中间景区的编号都必须严格小于 k（因为编号大于等于 k的景区还没来得及放进 dist 
        //的更新名单里呢
        for (int i=1;i<k;i++)
        {
            for (int j =i+1;j<k;j++)
            {
                if (dist[i][j]!=INF&&map[j][k]!=INF&&map[k][i]!=INF)
                {
                    int cyl = dist[i][j]+map[j][k]+map[k][i];
                    if (cyl<mincyl)
                        mincyl = cyl;
                }
            }
        }
        //2.更新dist,使得编号k的景区也能加入到最短路径的计算中来
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (dist[i][k]!=INF&&dist[k][j]!=INF)
                    if (dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    if (mincyl == INF) {
        printf("It's impossible.\n");
    } else {
        printf("%d\n", mincyl);
    }
    fclose(fp);
    return 0;
}