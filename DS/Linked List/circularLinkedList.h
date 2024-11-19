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
    newnode->next = newnode;
    return newnode;
}

void insertRear(NODE** head, int x) {
    NODE* newnode = create(x);
    NODE* t = *head;
    while (t->next != *head) {
        t = t->next;
    }
    t->next = newnode;
    newnode->next = *head;
}

int deleteRear(NODE** head) {
    NODE* t = *head;
    if (t->next == *head) {
        printf("Empty list");
        exit(0);
    }
    while (t->next->next != *head) {
        t = t->next;
    }
    int x = t->next->data;
    free(t->next);
    t->next = *head;
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