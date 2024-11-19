#include <string.h>
#include "integerStack.h" //calls integer stack header file
#define MAX 1000

int main() {
    char* expr = "*1*+234";

    STACK stack = createStack();

    for (int j = strlen(expr) - 1; j >= 0; j--) {
        char c = expr[j];

        if (c >= '0' && c <= '9')
            push(&stack, c - 48);
        else {
            int x = pop(&stack);
            int y = pop(&stack);
            int r;
            switch(c) {
                case '+': r = x + y; break;
                case '-': r = x - y; break;
                case '*': r = x * y; break;
                case '/': r = x / y; break;
                default: exit(0);
            }
            push(&stack, r);
        }
    }
    printf("%d", pop(&stack));
}