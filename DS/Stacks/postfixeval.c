//Program to evaluate postfix expression

#include "integerStack.h"

int main() {
    char* expr = "34+56+*";
    STACK stack = createStack();
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            push(&stack, (int) c - 48);
        } else {
            int y = pop(&stack);
            int x = pop(&stack);
            int r;
            switch(c) {
                case '+': r = x + y; break;
                case '-': r = x - y; break;
                case '*': r = x * y; break;
                case '/': r = x / y; break;
            }
            push(&stack, r);
        }
    }
    printf("%d\n", pop(&stack));
}