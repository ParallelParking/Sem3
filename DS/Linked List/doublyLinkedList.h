#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* right;
    struct node* left;
} NODE;

NODE* create(int x) {
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
    if(!newnode) {
        printf("Heap overflow!");
        exit(0);
    }
    newnode->data = x;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

void insertRear(NODE** head, int x) {
    NODE* newnode = create(x);
    newnode->left = (*head)->left;
    newnode->right = *head;
    (*head)->left->right = newnode;
    (*head)->left = newnode;
}

int deleteRear(NODE** head) {
    NODE* d = (*head)->left;
    d->left->right = *head;
    (*head)->left = d->left;
    int x = d->data;
    free(d);
    return x;
}

void insertFront(NODE** head, int x) {
    NODE* newnode = create(x);
    newnode->left = *head;
    newnode->right = (*head)->right;
    (*head)->right->left = newnode;
    (*head)->right = newnode;
}

int deleteFront(NODE** head) {
    NODE* d = (*head)->right;
    (*head)->right = d->right;
    d->right->left = *head;
    int x = d->data;
    free(d);
    return x;
}