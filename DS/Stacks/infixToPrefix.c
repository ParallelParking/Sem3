//converts an infix expression to prefix

//THIS CONTAINS NO ERROR CHECKING! ENSURE THE EXPRESSION IS VALID!

#include "characterStack.h"
#include <string.h>

int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

//PLEASE NOTE: this code is written this way to recycle code from the postfix file.
//strrev is a messy function with odd behaviour. It is FAR easier to just traverse the string in reverse
int main() {
    char infix[] = "(3+4)*(5+6)";
    strrev(infix);
    STACK stack = createStack();
    char prefix[MAX];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == ')') {
            push(&stack, c);
        } else if (c == '(') {
            while (peek(stack) != ')') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack);
        } else if (c >= '0' && c <= '9') {
            prefix[j++] = c;
        } else {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(c)) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }
    while (!isEmpty(stack)) {
        prefix[j++] = pop(&stack);
    }
    prefix[j] = '\0';
    strrev(prefix);
    printf("%s", prefix);
    return 0;
}