//IMPLEMENTATION HERE ASSUMES A HEADER NODE
//LACK OF HEADER NODE MEANS CONSTANT CHECKING FOR EMPTY LIST, CRINGE

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE* create(int x) {
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
    if(!newnode) {
        printf("Heap overflow!");
        exit(0);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void insertPos(NODE** head, int x, int pos) { //inserts node x at given pos (list is 1-indexed)
    NODE* newnode = create(x);
    NODE* t = (*head);
    for (int i = 1; i < pos; t = t->next, i++) {
        if (!t) {
            printf("Invalid pos");
            exit(0);
        }
    }
    newnode->next = t->next;
    t->next = newnode;
}

void deletePos(NODE** head, int pos) { //deletes node at given pos
    NODE* t = *head;
    for (int i = 1; i < pos; t = t->next, i++) {
        if (!(t->next)) {
            printf("Invalid pos");
            exit(0);
        }
    }
    NODE* del = t->next;
    t->next = del->next;
    free(del);
}

void insertRear(NODE** head, int x) {
    NODE* newnode = create(x);
    NODE* t = *head;
    while (t->next) {
        t = t->next;
    }
    t->next = newnode;
}

int deleteRear(NODE** head) {
    NODE* t = *head;
    if (!t->next) {
        printf("Empty list");
        exit(0);
    }
    while (t->next->next) {
        t = t->next;
    }
    int x = t->next->data;
    free(t->next);
    t->next = NULL;
    return x;
}

void insertFront(NODE** head, int x) {
    NODE* newnode = create(x);
    newnode->next = (*head)->next;
    (*head)->next = newnode;
}

int deleteFront(NODE** head) {
    NODE* del = (*head)->next;
    if (!del) {
        printf("Empty list");
        exit(0);
    }
    (*head)->next = del->next;
    int x = del->data;
    free(del);
    return x;
}

void display(NODE* head) {
    for (NODE* t = head->next; t; t = t->next) {
        printf("%d ", t->data);
    }
    printf("\n");
}

void invert(NODE** head) {
    NODE* t = (*head)->next;
    NODE* p = NULL;
    NODE* n;
    while (t) {
        n = t->next;
        t->next = p;
        p = t;
        t = n;
    }
    (*head)->next = p;
}