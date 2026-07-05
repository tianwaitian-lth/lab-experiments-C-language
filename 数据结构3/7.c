#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int nums[100005];
    int n = 0, k;

    // 更加健壮的输入读取方式：读取一行数字
    char ch;
    while (scanf("%d%c", &nums[n++], &ch) == 2) {
        if (ch == '\n') break;
    }
    scanf("%d", &k);

    if (n == 0 || k == 0) return 0;

    Deque *q = createDeque(n);
    int *result = (int *)malloc((n - k + 1) * sizeof(int));
    int resIdx = 0;

    for (int i = 0; i < n; i++) {
        // 1. 移除不在窗口内的下标
        if (!isEmpty(q) && getFront(q) <= i - k) {
            popFront(q);
        }

        // 2. 维护单调递减：如果新数比队尾的大，队尾就没用了，踢掉
        while (!isEmpty(q) && nums[getRear(q)] < nums[i]) {
            popRear(q);
        }

        pushRear(q, i);

        // 3. 当窗口形成后，队头就是当前窗口最大值的索引
        if (i >= k - 1) {
            result[resIdx++] = nums[getFront(q)];
        }
    }
    for (int i = 0; i < resIdx; i++) {
        printf("%d%c", result[i], (i == resIdx - 1 ? '\n' : ' '));
    }
    freeDeque(q);
    free(result);
    return 0;
}