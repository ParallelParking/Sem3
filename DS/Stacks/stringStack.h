#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct {
    char items[MAX][MAX];
    int top;
} STACK;

STACK createStack() {
    STACK stack;
    stack.top = -1;
    return stack;
}

int isFull(STACK stack) {
    return stack.top == MAX - 1;
}

void push(STACK* stack, char x[]) {
    if (isFull(*stack)) {
        printf("Stack overflow!");
        exit(0);
    }
    strcpy(stack->items[++stack->top], x);
}

int isEmpty(STACK stack) {
    return stack.top == -1;
}

char* pop(STACK* stack) {
    if (isEmpty(*stack)) {
        printf("Empty stack!\n");
        exit(0);
    }
    return stack->items[stack->top--];
}

char* peek(STACK* stack) {
    if (isEmpty(*stack)) {
        printf("Empty stack!\n");
        exit(0);
    }
    return stack->items[stack->top--];
}
