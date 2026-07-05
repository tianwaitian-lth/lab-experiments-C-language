#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct EDGE
{
    int start,end,cost;
}edge;
int cmp(const void *a,const void *b)
{
    edge *e1=(edge *)a;
    edge *e2=(edge *)b;
    return e1->cost-e2->cost;
}
int parent[10005];
int find_set(int i)// 查找i所在集合的代表元素
{
    if (parent[i] == i)
        return i;
    parent[i] = find_set(parent[i]);
    return parent[i];
}
int union_sets(int i, int j)// 合并i所在集合和j所在集合
{
    int root_i = find_set(i);
    int root_j = find_set(j);
    if (root_i != root_j) {
        parent[root_i] = root_j; // 让一个老大认另一个做老大
        return 1; // 成功合并
    }
    return 0; // 本来就是同一个集合，不需要合并（说明会产生环）
}
void kruskal(edge edges[],int n,int m)
{
    for (int i=0;i<=n;i++)
        parent[i]=i;// 初始化每个元素所在集合的代表元素为自己
    int allcost=0,num=0;
    for (int i=0;i<m&&num<n-1;i++)
    {
        if (union_sets(edges[i].start,edges[i].end))
        {
            allcost+=edges[i].cost;
            num++;
        }
    }
    if (num==n-1)
        printf("%d\n",allcost);
    else
        printf("-1\n");
    return;
}
int main()
{
    edge edges[1000];
    //kruskal
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d",&edges[i].start,&edges[i].end,&edges[i].cost);
    }
    qsort(edges,m,sizeof(edge),cmp);
    kruskal(edges,n,m);
    return 0;
}