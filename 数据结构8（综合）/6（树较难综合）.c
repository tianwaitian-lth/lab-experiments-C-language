#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} tree;

tree *createnode(int val)
{
    tree *new_node = malloc(sizeof(tree));
    new_node->left = new_node->right = NULL;
    new_node->val = val;
    return new_node;
}

tree *buildtree(int *arr, int num)
{
    if (num == 0 || arr[0] == -1)
        return NULL;
        
    tree *root = createnode(arr[0]);
    tree *queue[1005];
    int front = 0, rear = 0, i = 1;
    queue[rear++] = root;
    while (front < rear && i < num)
    {
        tree *cur = queue[front++];
        
        // 左子树
        if (i < num) {
            if (arr[i] != -1) {
                cur->left = createnode(arr[i]);
                queue[rear++] = cur->left;
            } else {
                cur->left = NULL;
            }
            i++;
        }
        
        // 右子树
        if (i < num) {
            if (arr[i] != -1) {
                cur->right = createnode(arr[i]);
                queue[rear++] = cur->right;
            } else {
                cur->right = NULL;
            }
            i++;
        }
    }
    return root;
}

int ansnum = 0, result[1001][1001], pathsize = 0, path[1001], resultsize[1001];

void findsum(tree *node, int target, int cursum)
{
    if (node == NULL)
        return;
        
    cursum += node->val;
    path[pathsize++] = node->val;
    
    if (cursum == target && node->left == NULL && node->right == NULL)
    {
        memcpy(result[ansnum], path, pathsize * sizeof(int));
        resultsize[ansnum] = pathsize;
        ansnum++;
    }
    
    findsum(node->left, target, cursum);
    findsum(node->right, target, cursum);
    pathsize--;
}

int main()
{
    char buff[1001];
    if (fgets(buff, 1001, stdin) == NULL) return 0;
    
    int len = strlen(buff), i = 0, arr[1001], num = 0;
    memset(arr, 0, sizeof(arr));
    
    while (buff[i] != '[' && i < len)
    {
        i++;
    }
    
    // 开始解析数组
    while (i < len && buff[i] != '\n')
    {
        if (buff[i] == 'n')
        {
            i += 4; // 跳过 "null"
            arr[num++] = -1;
            continue;
        }
        
        int temp = 0, flag = 0, sign = 1;
        // 修正2：处理负数节点值
        if (buff[i] == '-') {
            sign = -1;
            i++;
        }
        
        while (buff[i] >= '0' && buff[i] <= '9')
        {
            flag = 1;
            temp = temp * 10 + (buff[i] - '0');
            i++;
        }
        
        if (flag)
        {
            arr[num++] = temp * sign;
            i--; // 让外层循环自然推进
        }
        
        if (buff[i] == ']')
        {
            break;
        }
        i++;
    }
    while (i < len && buff[i] != '=')
    {
        i++;
    }
    i++;
    
    // 修正3：处理 targetSum 为负数的情况
    int targetsum = 0, t_sign = 1;
    while (i < len && buff[i] != '\n')
    {
        if (buff[i] == '-') {
            t_sign = -1;
        }
        if (buff[i] >= '0' && buff[i] <= '9')
        {
            targetsum = targetsum * 10 + (buff[i] - '0');
        }
        i++;
    }
    targetsum *= t_sign;
    
    // 构建与搜索
    tree *root = buildtree(arr, num);
    findsum(root, targetsum, 0);
    
    // 完美输出格式
    printf("[");
    for (i = 0; i < ansnum; i++)
    {
        printf("[");
        for (int j = 0; j < resultsize[i]; j++)
        {
            printf("%d", result[i][j]);
            if (j < resultsize[i] - 1) printf(",");
        }
        printf("]");
        if (i < ansnum - 1) printf(",");
    }
    printf("]\n");
    
    return 0;
}