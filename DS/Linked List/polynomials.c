#include "polynomialLinkedList.h"

int main() {
    NODE* f = create(0, 0);
    NODE* g = create(0, 0);
    addTerm(&f, 1, 3);
    addTerm(&f, 1, 1);
    addTerm(&g, 1, 1);
    addTerm(&g, 1, 2);

    display(f);
    display(g);

    NODE* sum = create(0, 0);
    NODE* x = f->next;
    NODE* y = g->next;
    while (x && y) {
        if (x->expo < y->expo) {
            addTerm(&sum, x->coeff, x->expo);
            x = x->next;
        } else if (x->expo > y->expo) {
            addTerm(&sum, y->coeff, y->expo);
            y = y->next;
        } else {
            addTerm(&sum, x->coeff + y->coeff, x->expo);
            x = x->next;
            y = y->next;
        }
    }
    while (x) {
        addTerm(&sum, x->coeff, x->expo);
        x = x->next;
    }
    while (y) {
        addTerm(&sum, y->coeff, y->expo);
        y = y->next;
    }

    display(sum);

    return 0;
}