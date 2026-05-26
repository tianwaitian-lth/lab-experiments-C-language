#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 有向图的拓扑排序
typedef struct node
{
    int v;
    struct node *next;
}Edge;
int result [2002];
int inpool[2002];
Edge *head[2002];
int indegree[2002];
int res=0;
void Topsort(int num)
{
    for (int i = 0; i < num; i++)
    {
        if (indegree[i] == 0)
        {
            inpool[i] = 1;
        }
    }
    for (int step = 0; step < num; step++)
    {
        int choice = -1;
        for (int i = 0; i < num; i++)
        {
            if (inpool[i] == 1)
            {
                choice = i;
                break; 
            }
        }
        if (choice == -1)
        {
            printf("0\n");
            return;
        }
        result[res++] = choice;
        inpool[choice] = 0;
        Edge *p = head[choice];
        while (p != NULL)
        {
            indegree[p->v]--;
            if (indegree[p->v] == 0)
            {
                inpool[p->v] = 1;
            }
            p = p->next;
        }
    }
    printf("%d\n", num);
    for (int i = 0; i < num; i++)
    {
        printf("%d", result[i]);
        if (i < num - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void addedge(int a,int b)
{
    Edge *p=(Edge *)malloc(sizeof(Edge));
    p->next=head[b];
    p->v=a;
    head[b]=p;
    indegree[a]++;
}
int main()
{
    int num,m;
    scanf("%d %d",&num,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        addedge(x,y);
    }
    Topsort(num);
    return 0;
}