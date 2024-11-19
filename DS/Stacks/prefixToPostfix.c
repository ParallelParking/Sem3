#include "stringstack.h"

int main() {
    char expr[] = "/*123";

    STACK stack = createStack();

    for (int x = strlen(expr) - 1; x >= 0; x--) {
        char c = expr[x];
        char a[2] = {c, '\0'};
        if (c >= '0' && c <= '9') {
            push(&stack, a);
        }
        else {
            char* x = pop(&stack);
            char* y = pop(&stack);
            strcat(x, strcat(y, a));
            push(&stack, x);
        }
    }
    printf("%s", pop(&stack));
}