#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;  
    int expo;   
    struct node* next;
} NODE;

NODE* create(int coeff, int expo) {
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
    if (!newnode) {
        printf("Heap overflow!");
        exit(0);
    }
    newnode->coeff = coeff;
    newnode->expo = expo;
    newnode->next = NULL;
    return newnode;
}

void addTerm(NODE** head, int coeff, int expo) {
    NODE* newnode = create(coeff, expo);
    NODE* t = *head;
    while (t->next && t->next->expo < expo) {
        t = t->next;
    }
    newnode->next = t->next;
    t->next = newnode;
}

void display(NODE* head) {
    NODE* t = head->next;
    while (t) {
        if (t->coeff > 0 && t != head->next) {
            printf("+ ");
        }
        printf("%dx^%d ", t->coeff, t->expo);
        t = t->next;
    }
    printf("\n");
}