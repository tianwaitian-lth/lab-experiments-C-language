#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* createDeque(int size) {
    Deque *q = (Deque *)malloc(sizeof(Deque));
    q->data = (int *)malloc((size + 1) * sizeof(int));
    q->front = 0;
    q->rear = 0;
    q->capacity = size + 1;
    return q;
}

int isEmpty(Deque *q) {
    return q->front == q->rear;
}

// 入队尾
void pushRear(Deque *q, int val) {
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
}

// 出队头
void popFront(Deque *q) {
    q->front = (q->front + 1) % q->capacity;
}

// 出队尾
void popRear(Deque *q) {
    q->rear = (q->rear - 1 + q->capacity) % q->capacity;
}

int getFront(Deque *q) {
    return q->data[q->front];
}

int getRear(Deque *q) {
    return q->data[(q->rear - 1 + q->capacity) % q->capacity];
}

void freeDeque(Deque *q) {
    free(q->data);
    free(q);
}
int nums[100005]; // 题目要求 10^5，稍微开大一点

int main() {
    int k = 0, num_target;
    char ch;
    while (scanf("%d%c",&nums[k++],&ch) == 2 && ch != '\n');
    scanf("%d",&num_target);
    int *P = (int *)malloc((k + 1) * sizeof(int));
    P[0] = 0;
    for (int i = 0; i < k; i++) {
        P[i + 1] = P[i] + nums[i];
    }
    Deque *q = createDeque(k + 1);
    //维护的q队列是开头的节点可能值
    //它维护的是“所有可能成为【最短】子数组起点的【最优】候选值”
    //它是单调递增的
    int min_len = k + 1;
    for (int i = 0; i <=k; i++)
    {
        //满足条件就提出队头
        while(!isEmpty(q)&&P[i]-P[getFront(q)]>=num_target)
        {
            int current_len=i-getFront(q);
            if (current_len<min_len)
            {
                min_len=current_len;
                popFront(q);
            }
        }
        //如果后面的前缀和比前面的小，则以后再减去他的时候，更容易满足，故踢出当前队尾。
        while (!isEmpty(q) && P[i] <= P[getRear(q)]) {
            popRear(q);
        }
        pushRear(q, i);
    }
    if (min_len > k) {
        printf("-1\n");
    } else {
        printf("%d\n", min_len);
    }

    // 5. 释放内存
    freeDeque(q);
    free(P);
    return 0;
}