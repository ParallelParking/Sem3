//converts an infix expression to postfix

//THIS CONTAINS NO ERROR CHECKING! ENSURE THE EXPRESSION IS VALID!

#include "characterStack.h"

int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

int main() {
    char* infix = "(3+4)*(5+6)";
    STACK stack = createStack();
    char postfix[MAX];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (peek(stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } else if (c >= '0' && c <= '9') {
            postfix[j++] = c;
        } else {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(c)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
    printf("%s", postfix);
    return 0;
}