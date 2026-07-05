#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *pre;
    struct Node *next;
    int data;
}tree;
tree *last = NULL;
tree *listHead = NULL;
//经典将二叉树转为中序遍历的循环链表，last指向刚刚处理完的节点
void middle(tree *cur)
{
    if (cur==NULL)
        return;
    middle (cur->pre);
    if (last != NULL) {
        last->next = cur;
        cur->pre = last;
    } else {
        listHead = cur;
    }
    last = cur;
    middle(cur->next); // 递归右
}
int main()
{
    //输入
    char* buffer = (char *)malloc(1000*sizeof(char));
    fgets(buffer,1000,stdin);
    int len = strlen(buffer),a[1000],cnt=0,tmp=0;
    for (int i = 0;i<len;i++)
    {
        if (buffer[i]==' ')
        {
            tmp=0;
            continue;
        }
        if (buffer[i]=='#')
        {
            a[cnt++]=-100;
        }
        else
        {
            tmp=tmp*10+buffer[i]-'0';
            if (buffer[i+1]==' ')
            {
                a[cnt++]=tmp;
            }
        }
    }
    //构建树
    tree* nodes[1000];
    for (int i = 0;i<cnt;i++)
    {
        if (a[i]==-100)
        {
            nodes[i]=NULL;
            continue;
        }
        nodes[i] = (tree*)malloc(sizeof(tree));
        nodes[i]->data = a[i];
        nodes[i]->pre = nodes[i]->next = NULL;
    }
    //非常经典的层序遍历输入构建出树，parent就是当前构建的节点，通过i的变化找到孩子
    int parent = 0;
    for (int i = 1; i < cnt; )
    {
        if (nodes[parent] != NULL)
        {
            nodes[parent]->pre = nodes[i++];
            if (i < cnt) 
                nodes[parent]->next = nodes[i++];
        }
        parent++;
    }
    if (cnt > 0 && nodes[0] != NULL)
    {
        middle(nodes[0]);
    //  形成循环 (首尾相连)
        listHead->pre = last;
        last->next = listHead;
    //  按照格式输出
    tree* temp = listHead;
    do {
            printf("%d%s", temp->data, (temp->next == listHead ? "" : " <-> "));
            temp = temp->next;
        } while (temp != listHead);
        printf("\n");
    }
    return 0;
}