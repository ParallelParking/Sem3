#include "singleLinkedList.h"

int main() {
    NODE* head = create(INT_MAX);
    insertRear(&head, 10);
    insertRear(&head, 20);
    insertRear(&head, 30);
    insertRear(&head, 40);
    display(head);
    deleteFront(&head);
    display(head);
    deleteFront(&head);
    display(head);
    deleteFront(&head);
    display(head);
    return 0;
}