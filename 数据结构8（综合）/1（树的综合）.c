#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans[1001],ansnum=0;
int cmp(const void*a,const void*b)
{
    //升序排序
    int *p=(int*)a;
    int *q=(int*)b;
    return *p-*q;
}
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} treenode;

treenode *createNode(int data)
{
    treenode *newNode = (treenode *)malloc(sizeof(treenode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

treenode *buildtree(int *buff, int num)
{
    //层序建树
    if (num == 0||buff[1]==-1)
        return NULL;
    treenode *root = createNode(buff[1]);
    int i = 2;
    treenode *queue[1001];
    int  front = 0, rear = 0;
    queue[rear++] = root;
    while (i <= num&&front<rear)
    {
        treenode *current = queue[front++];
        if (i<=num&&buff[i] != -1)
        {
            current->left = createNode(buff[i]);
            current->left->parent = current;
            queue[rear++] = current->left;
        }
        else
        {
            current->left = NULL;
        }
        i++;
        if (i <= num && buff[i] != -1)
        {
            current->right = createNode(buff[i]);
            current->right->parent = current;
            queue[rear++] = current->right;
        }
        else
        {
            current->right = NULL;
        }
        i++;
    }
    return root;
}

treenode *findNode(treenode *root, int target)
{
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    treenode *leftResult = findNode(root->left, target);
    if (leftResult != NULL)
        return leftResult;
    return findNode(root->right, target);
}

void tardist(treenode *target,treenode *pre,int k)
{
    if (k==0)
    {
        ans[ansnum++]=target->data;
        return;
    }
    if (target->left != NULL&&target->left!=pre)
    {
        tardist(target->left, target, k - 1);
    }
    if (target->right != NULL&&target->right!=pre)
    {
        tardist(target->right, target, k - 1);
    }
    if (target->parent != NULL&&target->parent!=pre)
    {
        tardist(target->parent, target, k - 1);
    }
}
int main()
{
    char str[1001];
    int buff[1001];
    memset(buff, 0, sizeof(buff));
    scanf("%s", str);
    int len = strlen(str);
    int num = 1;
    int i = 1; 
    while (i < len - 1)
    {
        if (str[i] == ',')
        {
            i++;
            continue;
        }
        if (str[i] == 'n')
        {
            buff[num++] = -1;
            i += 4;
        }
        else
        {
            int data = 0;
            while (str[i] >= '0' && str[i] <= '9')
            {
                data = data * 10 + (str[i] - '0');
                i++;
            }
            buff[num++] = data;
        }
    }
    num--;
    treenode *root = buildtree(buff, num);

    int target,k;
    scanf("%d%d", &target, &k);
    treenode* tar =findNode(root, target);
    if(tar==NULL)
    {
        printf("-1\n");
        return 0;
    }
    tardist(tar,NULL,k);
    if (ansnum==0)
    {
        printf("[]");
        return 0;
    }
    qsort(ans,ansnum,sizeof(int),cmp);
    printf("[");
    for(int i=0;i<ansnum;i++)
    {
        printf("%d",ans[i]);
        printf(i==ansnum-1?"]":",");
    }
    return 0;
}