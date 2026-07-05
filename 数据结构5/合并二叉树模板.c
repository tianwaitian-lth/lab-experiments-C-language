#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(char* str) {
    char* token = strtok(str, " ,[]\n\r");
    if (token == NULL || strcmp(token, "null") == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = atoi(token);
    root->left = root->right = NULL;
    struct TreeNode* queue[10000];
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        struct TreeNode* curr = queue[head++];
        token = strtok(NULL, " ,[]\n\r");
        if (token && strcmp(token, "null") != 0) {
            curr->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            curr->left->val = atoi(token);
            curr->left->left = curr->left->right = NULL;
            queue[tail++] = curr->left;
        }
        token = strtok(NULL, " ,[]\n\r");
        if (token && strcmp(token, "null") != 0) {
            curr->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            curr->right->val = atoi(token);
            curr->right->left = curr->right->right = NULL;
            queue[tail++] = curr->right;
        }
    }
    return root;
}

void printTree(struct TreeNode* root) {
    if (!root) { printf("[]\n"); return; }
    struct TreeNode* queue[10000];
    int head = 0, tail = 0;
    queue[tail++] = root;
    char buffer[50000] = "[";
    int pos = 1;
    int nullCount = 0;
    while (head < tail) {
        struct TreeNode* curr = queue[head++];
        if (curr != NULL) {
            while (nullCount > 0) { pos += sprintf(buffer + pos, "null,"); nullCount--; }
            pos += sprintf(buffer + pos, "%d,", curr->val);
            queue[tail++] = curr->left;
            queue[tail++] = curr->right;
        } else {
            nullCount++;
        }
    }
    if (pos > 1) buffer[pos-1] = ']';
    else buffer[1] = ']';
    buffer[pos] = '\0';
    printf("%s\n", buffer);
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

int main() {
    char buf1[20000], buf2[20000];
    while (fgets(buf1, sizeof(buf1), stdin) != NULL) {
        if (strlen(buf1) <= 1) continue;
        if (fgets(buf2, sizeof(buf2), stdin) == NULL) break;
        struct TreeNode* root1 = buildTree(buf1);
        struct TreeNode* root2 = buildTree(buf2);
        struct TreeNode* res = mergeTrees(root1, root2);
        printTree(res);
    }
    return 0;
}

