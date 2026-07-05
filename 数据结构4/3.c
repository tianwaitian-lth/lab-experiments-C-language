#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
    int len;
    int priority;
    char name[20];
    struct Node *next;
} Node;

int isEmpty(Node *head)
{
    return head == NULL;
}

Node *inserttail(int len, int priority, char *name, Node *head)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->len = len;
    newnode->priority = priority;
    strcpy(newnode->name, name); 
    newnode->next = NULL;
    if (head == NULL)
    {
        return newnode; // 直接返回新节点作为 head
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = newnode;
        return head;
    }
}

void printh(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        printf("%s", p->name);
        printf(p->next!=NULL ? " ":"");
        p = p->next;
    }
    printf("\n");
}

Node *inserthead(int len, int priority, char *name, Node *head)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->len = len;
    newnode->priority = priority;
    strcpy(newnode->name, name); 
    if (head == NULL)
    {
        newnode->next = NULL;
        return newnode; // 直接返回新节点作为 head
    }
    else
    {
        newnode->next = head;
        return newnode; // 新节点成为新的 head
    }
}

int main()
{
    Node *headA=NULL;
    Node *headB=NULL;
    int des,num,tmp,cishu=0;
    char *str[100];
    for (int i=0;i<100;i++)
        str[i] = (char*)malloc(sizeof(char)*20);
    scanf("%d", &des);
    for (int i=0;i<des;i++)
        scanf("%s%d", str[i], &tmp);
    scanf("%d", &num);
    for (int i=0;i<num;i++)
    {
        char na[20];
        char rename[20];
        scanf("%s", na);
        scanf("%s", rename);
        for (int j=0;j<des;j++)
        {
            if (strcmp(na, str[j]) == 0)
            {
                headA=inserttail(strlen(rename), j+1, rename, headA);
                break;
            }
        }
    }
    while (headA != NULL)
    {
        Node *temp = headA;
        headB = inserttail(temp->len, temp->priority, temp->name, headB);
        headA = headA->next;
        free(temp);
        cishu++;
    }
    while (!isEmpty(headB))
    {
        Node *temp = headB;
        int primax=0,notmatch=0;
        while (temp!=NULL)
        {
            primax = temp->priority > primax ? temp->priority : primax;
            temp = temp->next;
        }
        temp = headB;
        while (temp->priority != primax)
        {
            temp = temp->next;
            notmatch++;
        }
        headA=inserttail(temp->len, temp->priority, temp->name, headA);
        Node *temp2 = headB;
        for (int i=0;i<notmatch-1;i++)
        {
            temp2 = temp2->next;
        }
        if (notmatch == 0)
        {
            headB = temp->next;
        }
        else
            temp2->next=temp->next;
        cishu+=notmatch;
        free (temp);
    }
    printh(headA);
    printf("%d\n",cishu);
    return 0;
}