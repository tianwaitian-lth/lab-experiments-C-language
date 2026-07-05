#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct {
    int isBST;   // 1为真，0为假
    int sum;     // 当前和
    int minVal;  // 最小值
    int maxVal;  // 最大值
} NodeInfo;
int g_max_sum = 0; // 题目要求返回最大键值和，最小可以是0

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

NodeInfo solve(struct TreeNode* node)
{
    if (!node)
        return (NodeInfo){1, 0, INT_MAX, INT_MIN}; // 空树是BST，和为0，极值设置为INT_MAX和INT_MIN，方便比较
    NodeInfo leftInfo = solve(node->left);
    NodeInfo rightInfo = solve(node->right);
    if (leftInfo.isBST && rightInfo.isBST && node->val > leftInfo.maxVal && node->val < rightInfo.minVal) {
        // 当前节点满足BST条件
        int currSum = leftInfo.sum + rightInfo.sum + node->val;
        g_max_sum = MAX(g_max_sum, currSum); // 更新全局最大和
        return (NodeInfo){1, currSum, MIN(node->val, leftInfo.minVal), MAX(node->val, rightInfo.maxVal)};
    } else {
        // 不满足BST条件，返回非BST状态
        return (NodeInfo){0, 0, 0, 0}; // 和和极值不重要，因为这个子树不算数了
    }
}
// --- 字符串解析与建树逻辑 (适配 root = [...] 格式) ---
struct TreeNode* buildTree(char* input) {
    char* start = strchr(input, '[');
    char* end = strrchr(input, ']');
    if (!start || !end || start >= end) return NULL;

    int len = end - start - 1;
    char data[2048];
    strncpy(data, start + 1, len);
    data[len] = '\0';
    struct TreeNode* queue[30005];
    int head = 0, tail = 0;
    char* token = strtok(data, ",");
    if (!token || strcmp(token, "null") == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = atoi(token);
    root->left = root->right = NULL;
    queue[tail++] = root;
    while (head < tail) {
        struct TreeNode* curr = queue[head++];
        
        // Left
        token = strtok(NULL, ",");
        if (token) {
            if (strcmp(token, "null") != 0) {
                curr->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                curr->left->val = atoi(token);
                curr->left->left = curr->left->right = NULL;
                queue[tail++] = curr->left;
            }
        } else break;

        // Right
        token = strtok(NULL, ",");
        if (token) {
            if (strcmp(token, "null") != 0) {
                curr->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                curr->right->val = atoi(token);
                curr->right->left = curr->right->right = NULL;
                queue[tail++] = curr->right;
            }
        } else break;
    }
    return root;
}

int main() {
    char input[2048];
    if (fgets(input, sizeof(input), stdin)) {
        struct TreeNode* root = buildTree(input);
        g_max_sum = 0; // 重置全局变量
        solve(root);
        printf("%d\n", g_max_sum);
    }
    return 0;
}