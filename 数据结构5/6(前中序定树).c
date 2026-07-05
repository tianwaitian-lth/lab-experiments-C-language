#include <stdio.h>
#include <stdlib.h>

// 二叉树节点结构
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 递归构建二叉树
struct TreeNode* buildTree(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    struct TreeNode* root = createNode(preorder[preStart]);

    int k = inStart;
    while (k <= inEnd && inorder[k] != preorder[preStart]) {
        k++;
    }
    int leftNodesCount = k - inStart;
    root->left = buildTree(preorder, preStart + 1, preStart + leftNodesCount, inorder, inStart, k - 1);
    root->right = buildTree(preorder, preStart + leftNodesCount + 1, preEnd, inorder, k + 1, inEnd);
    return root;
}

// 层序遍历输出：格式为 [val1,val2,null,val3]
void printLevelOrder(struct TreeNode* root) {
    if (!root) {
        printf("[]\n");
        return;
    }
    // 使用一个较大的数组模拟队列来存储层序遍历节点
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 5000);
    int head = 0, tail = 0;
    struct TreeNode** resultList = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 5000);
    int resCount = 0;
    int lastNonNullIdx = -1;
    //依旧是层序遍历，记录每个节点的子节点
    queue[tail++] = root;
    while (head < tail) {
        struct TreeNode* curr = queue[head++];
        resultList[resCount++] = curr;
        if (curr) {
            lastNonNullIdx = resCount - 1; // 记录最后一个非空节点的位置
            queue[tail++] = curr->left;
            queue[tail++] = curr->right;
        }
    }
    // 打印结果
    printf("[");
    for (int i = 0; i <= lastNonNullIdx; i++) {
        if (resultList[i]) {
            printf("%d", resultList[i]->val);
        } else {
            printf("null");
        }
        
        // 只要不是最后一个要打印的元素，就加逗号
        if (i < lastNonNullIdx) {
            printf(",");
        }
    }
    printf("]\n");
    free(queue);
    free(resultList);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        // 如果 n 为 0，输出空数组
        if (n == 0) printf("[]\n");
        return 0;
    }
    int* preorder = (int*)malloc(sizeof(int) * n);
    int* inorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    struct TreeNode* root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1);

    printLevelOrder(root);

    // 清理
    free(preorder);
    free(inorder);

    return 0;
}