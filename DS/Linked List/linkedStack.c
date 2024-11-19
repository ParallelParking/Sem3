#include "singleLinkedList.h"

//insert rear == push
//delete rear == pop
int main() {
    NODE* head = create(INT_MAX);
    insertRear(&head, 10);
    insertRear(&head, 20);
    insertRear(&head, 30);
    insertRear(&head, 40);
    display(head);
    deleteRear(&head);
    display(head);
    deleteRear(&head);
    display(head);
    deleteRear(&head);
    display(head);
    return 0;
}