#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    q->items[++q->rear] = value;
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return q->items[q->front++];
}
int peek(Queue *q) {
    if (isEmpty(q)) return -1;
    return q->items[q->front];
}

// Merge two sorted queues into one sorted queue
Queue mergeQueues(Queue *q1, Queue *q2) {
    Queue merged;
    initQueue(&merged);

    while (!isEmpty(q1) && !isEmpty(q2)) {
        if (peek(q1) <= peek(q2))
            enqueue(&merged, dequeue(q1));
        else
            enqueue(&merged, dequeue(q2));
    }

    while (!isEmpty(q1))
        enqueue(&merged, dequeue(q1));

    while (!isEmpty(q2))
        enqueue(&merged, dequeue(q2));

    return merged;
}

void displayQueue(Queue *q) {
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    Queue q1, q2, merged;
    initQueue(&q1);
    initQueue(&q2);

    int n1, n2, val;

    printf("Enter number of elements in Queue 1: ");
    scanf("%d", &n1);
    printf("Enter %d sorted integers for Queue 1:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        enqueue(&q1, val);
    }

    printf("Enter number of elements in Queue 2: ");
    scanf("%d", &n2);
    printf("Enter %d sorted integers for Queue 2:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        enqueue(&q2, val);
    }

    merged = mergeQueues(&q1, &q2);

    printf("\nMerged Sorted Queue:\n");
    displayQueue(&merged);

    return 0;
}
