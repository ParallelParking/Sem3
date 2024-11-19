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
    return queue.rear == MAX - 1;
}

void insert(DEQUE* queue, int x) {
    if (isFull(*queue)) {
        printf("Queue full");
        exit(0);
    }
    queue->items[++queue->rear] = x;
}

int isEmpty(DEQUE queue) {
    return queue.front == queue.rear;
}

int remove(DEQUE* queue) {
    if (isEmpty(*queue)) {
        printf("Queue empty");
        exit(0);
    }
    return queue->items[++queue->front];
}

void display(DEQUE queue)  {
    for (int i = queue.front + 1; i <= queue.rear; i++) {
        printf("%d ", queue.items[i]);
    }
    printf("\n");
}