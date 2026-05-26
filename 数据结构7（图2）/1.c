#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int v;
    struct Node *next;     
} Node;

#define MAX_N 1005

int dfs(Node **graph, int curr, int target, int *visited) {
    if (curr == target) return 1;
    
    visited[curr] = 1;
    
    Node *p = graph[curr];
    while (p != NULL) {
        if (!visited[p->v]) {
            if (dfs(graph, p->v, target, visited)) {
                return 1;
            }
        }
        p = p->next;
    }
    return 0;
}

int iscircle(Node **graph, int u, int v) {
    int visited[MAX_N] = {0}; // 每次查找前，初始化访问标记数组
    return dfs(graph, u, v, visited);
}

void add_edge(Node **graph, int u, int v) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->v = v;
    new_node->next = graph[u];
    graph[u] = new_node;
}

int main() {
    Node *graph[MAX_N] = {NULL}; 
    int edges[1000][2];
    int n = 0;
    char c;
    
    // 读走最开始的 '['
    scanf(" %c", &c);
    while (1) {
        int u, v;
        if (scanf(" [%d,%d]", &u, &v) == 2) {
            edges[n][0] = u;
            edges[n][1] = v;
            n++;
        }
        scanf(" %c", &c);
        if (c == ']')
            break;
    }
    int ans_u = 0, ans_v = 0;
    // 遍历所有边，边读边建图
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        // 如果在加边之前，u 和 v 已经连通了，说明这条边就是冗余边！
        if (iscircle(graph, u, v)) {
            ans_u = u;
            ans_v = v;
        } else {
            // 如果不连通，把这条无向边加入到图中（双向都要加）
            add_edge(graph, u, v);
            add_edge(graph, v, u);
        }
    }
    printf("[%d,%d]\n", ans_u, ans_v);
    for (int i = 1; i <= n; i++) {
        Node *p = graph[i];
        while (p != NULL) {
            Node *temp = p;
            p = p->next;
            free(temp);
        }
    }
    
    return 0;
}