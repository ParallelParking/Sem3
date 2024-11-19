#include "binarytree.h"

int main() {
    NODE* root = NULL;
    iterativeCreateBST(&root, 20);
    iterativeCreateBST(&root, 10);
    iterativeCreateBST(&root, 30);
    iterativeCreateBST(&root, 5);
    iterativeCreateBST(&root, 15);
    iterativeCreateBST(&root, 25);
    iterativeCreateBST(&root, 35);
    inorder(root);
    printf("\n");
    ancestors(root, 5);

    return 0;   
}