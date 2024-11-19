//defines an array integer stack and its operations

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct {
    int items[MAX];
    int top;
} STACK;

STACK createStack() {
    STACK stack;
    stack.top = -1;
    return stack;
}

int isEmpty(STACK stack) {
    return stack.top == -1;
}

int isFull(STACK stack) {
    return stack.top == MAX - 1;
}

//written below is a realloc function to accomodate for when the stack becomes full.
//it sits unused in this file because for simplicity, my stack sits in the static memory
//this implementation assumes a heap stack.
void extend(STACK* stack, int* n) { //n is current size of stack
    if (isFull(*stack)) {
        stack = (STACK*) realloc(stack, *n * 2);
        *n *= 2;
    }
}

void push(STACK* stack, int x) {
    if (isFull(*stack)) {
        printf("Stack overflow!");
        exit(0);
    }
    stack->items[++stack->top] = x;
}

int pop(STACK* stack) {
    if (isEmpty(*stack)) {
        printf("Stack underflow!");
        exit(0);
    }
    return stack->items[stack->top--];
}

int peek(STACK stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!");
        exit(0);
    }
    return stack.items[stack.top];
}

void display(STACK stack) {
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.items[i]);
    }
    printf("\n");
}