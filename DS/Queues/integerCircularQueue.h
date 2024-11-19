#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int items[MAX];
    int front;
    int rear;
} DEQUE;

DEQUE createQueue() {
    DEQUE queue;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

int isFull(DEQUE queue) {
    return (queue.rear + 1) % MAX == queue.front;
}

int isEmpty(DEQUE queue) {
    return queue.rear == queue.front;
}

void insert(DEQUE* queue, int x) {
    if (isFull(*queue)) {
        printf("Queue full");
        exit(0);
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = x;
}

int remove(DEQUE* queue) {
    if (isEmpty(*queue)) {
        printf("Queue empty");
        exit(0);
    }
    queue->front = (queue->front + 1) % MAX;
    return queue->items[queue->front];
}

void display(DEQUE queue) {
    for (int i = (queue.front + 1) % MAX; i <= queue.rear; i = (i + 1) % MAX) {
        printf("%d ", queue.items[i]);
    }
    printf("\n");
}