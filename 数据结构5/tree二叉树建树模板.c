#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
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