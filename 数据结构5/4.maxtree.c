#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// --- 二叉树节点结构 ---
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 全局最大路径和
int g_max_sum;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// --- 核心算法：DFS 递归 ---
int calculateGain(struct TreeNode* node) {
    if (node == NULL) return 0;

    // 递归计算左右子树的贡献值，负数则贡献为 0
    int left_gain = MAX(calculateGain(node->left), 0);
    int right_gain = MAX(calculateGain(node->right), 0);

    // 路径经过当前节点并在此“转弯”的总和
    int current_path_sum = node->val + left_gain + right_gain;

    // 更新全局最大值
    if (current_path_sum > g_max_sum) {
        g_max_sum = current_path_sum;
    }

    // 返回给父节点：当前节点只能选择左或右一条路径向上延伸
    return node->val + MAX(left_gain, right_gain);
}

int maxPathSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    g_max_sum = INT_MIN;
    calculateGain(root);
    return g_max_sum;
}

// --- 辅助函数：解析 root = [...] 格式并构建树 ---
struct TreeNode* buildTreeFromInput(char* input) {
    // 1. 寻找 '[' 的位置，跳过 "root =" 等前缀
    char* start = strchr(input, '[');
    char* end = strrchr(input, ']');
    if (!start || !end || start >= end) return NULL;

    // 2. 提取括号内的内容
    int len = end - start - 1;
    if (len <= 0) return NULL; // 处理 root = []

    char data[1024];
    strncpy(data, start + 1, len);
    data[len] = '\0';

    // 3. 使用队列进行层序构建
    struct TreeNode* queue[20000];
    int head = 0, tail = 0;

    char* token = strtok(data, ", ");
    if (!token || strcmp(token, "null") == 0) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = atoi(token);
    root->left = root->right = NULL;
    queue[tail++] = root;

    while (head < tail) {
        struct TreeNode* curr = queue[head++];

        // 处理左子节点
        token = strtok(NULL, ", ");
        if (token) {
            if (strcmp(token, "null") != 0) {
                curr->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                curr->left->val = atoi(token);
                curr->left->left = curr->left->right = NULL;
                queue[tail++] = curr->left;
            }
        } else break;

        // 处理右子节点
        token = strtok(NULL, ", ");
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

// --- 主函数 ---
int main() {
    char input[2048];
    // 使用 fgets 以支持包含空格的输入
    if (fgets(input, sizeof(input), stdin)) {
        struct TreeNode* root = buildTreeFromInput(input);
        
        if (root) {
            int result = maxPathSum(root);
            printf("%d\n", result);
        } else {
            printf("The tree is empty or input format is incorrect.\n");
        }
    }

    return 0;
}