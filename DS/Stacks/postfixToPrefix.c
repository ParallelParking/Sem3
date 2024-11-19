#include "stringstack.h"

int main() {
    char expr[] = "12*3/";

    STACK stack = createStack();

    for (int x = 0; expr[x] != '\0'; x++) {
        char c = expr[x];
        char a[MAX] = {c, '\0'};
        if (c >= '0' && c <= '9') {
            push(&stack, a);
        }
        else {
            char* x = pop(&stack);
            char* y = pop(&stack);
            strcat(a, strcat(y,x));
            push(&stack, a);
        }
    }
    printf("%s", pop(&stack));
}