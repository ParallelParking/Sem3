#include <stdlib.h>
#include <stdio.h>
#define MAX 9
#define STACKS 3

int a[MAX];
int b[STACKS];
int t[STACKS];

int isFull(int n) {
    if (n == STACKS - 1)
        return t[n] == MAX - 1;
    return t[n] + 1 == b[n + 1];
}

void push(int x, int n) {
    if (isFull(n)) {
        exit(0);
    }
    a[++t[n]] = x;
}

int isEmpty(int n) {
    return t[n] == b[n] - 1;
}

int pop(int n) {
    if (isEmpty(n)) {
        exit(0);
    }
    return a[t[n]--];
}

int main() {
    for (int i = 0; i < STACKS; i++) {
        b[i] = (MAX / STACKS) * i;
        t[i] = b[i] - 1;
    }

    push(10, 0);
    push(20, 0);
    printf("%d\n", pop(0)); 

    push(30, 1);
    printf("%d\n", pop(1)); 

    return 0;
}