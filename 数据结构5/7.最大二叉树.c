#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 辅助函数：创建一个新节点
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// 核心递归函数：构造最大二叉树
struct TreeNode* build(int* nums, int left, int right) {
    if (left > right) return NULL;

    // 找到当前范围内的最大值及其索引
    int maxIdx = left;
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] > nums[maxIdx]) {
            maxIdx = i;
        }
    }

    struct TreeNode* root = newNode(nums[maxIdx]);
    
    // 递归构造左右子树
    root->left = build(nums, left, maxIdx - 1);
    root->right = build(nums, maxIdx + 1, right);
    
    return root;
}

// 层序遍历输出结果
void printLevelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[2000]; // 简单的队列实现
    int head = 0, tail = 0;
    queue[tail++] = root;

    // 用于存储输出字符串的临时数组
    char* results[2000];
    int resCount = 0;
    int lastNonNull = -1;

    while (head < tail) {
        struct TreeNode* curr = queue[head++];
        
        if (curr) {
            results[resCount] = (char*)malloc(20);
            sprintf(results[resCount], "%d", curr->val);
            lastNonNull = resCount;
            
            queue[tail++] = curr->left;
            queue[tail++] = curr->right;
        } else {
            results[resCount] = "null";
        }
        resCount++;
        
        // 优化：如果队列里全是NULL，可以提前结束
        int remains = 0;
        for(int i = head; i < tail; i++) {
            if(queue[i] != NULL) remains = 1;
        }
        if(!remains && !curr) break; 
    }

    // 按照格式输出 [val, val, null...]
    printf("[");
    for (int i = 0; i <= lastNonNull; i++) {
        printf("%s", results[i]);
        if (i < lastNonNull) printf(",");
    }
    printf("]\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    struct TreeNode* root = build(nums, 0, n - 1);

    printLevelOrder(root);

    return 0;
}
