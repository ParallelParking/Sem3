//PRETTY MUCH EVERYTHING IS HERE SORRY!!! GOT LAZY!!
//STUFF IS NAMED NICELY, SO CTRL+F IF YOU STRUGGLE TO FIND STUFF

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} NODE;

NODE* createNode(int x) {
    NODE* newnode = (NODE*) malloc(sizeof(NODE));
    if (!newnode) {
        printf("Heap overflow!");
        exit(0);
    }
    newnode->data = x;
    newnode->right = newnode->left = NULL;
    return newnode;
}

//different from what's in the slides but I prefer this so
NODE* createTree() {
    printf("Enter num. (-1 to exit): ");
    int n;
    scanf("%d", &n);
    
    if (n == -1) return NULL;

    NODE* root = createNode(n);
    printf("Enter left child\n");
    root->left = createTree();
    printf("Enter right child\n");
    root->right = createTree();
    
    return root;
}

void inorder(NODE* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(NODE* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

void iterativeInorder(NODE* root) {
    if (!root) return;

    NODE* stack[MAX];
    int top = -1;

    NODE* curr = root;
    while (curr || top != -1) {
        if (curr) {
            stack[++top] = curr;
            curr = curr->left;
        } else {
            if (top != -1) {
                NODE* temp = stack[top--];
                printf("%d ", temp->data);
                curr = temp->right;
            }
        }
    }
}

void iterativePostorder(NODE* root) {
    if (!root) return;
    NODE* stack[MAX];
    int top = -1;
    NODE* curr = root;
    while (curr || top != -1) {
        if (curr) {
            stack[++top] = curr;
            curr = curr->left;
        } else {
            NODE* temp = NULL;
            if (top != -1) {
                temp = stack[top]->right;
            }
            if (!temp) {
                temp = stack[top--];
                printf("%d ", temp->data);
                while (top != -1 && temp == stack[top]->right) {
                    temp = stack[top--];
                    printf("%d ", temp->data);
                }
            } else {
                curr = temp;
            }
        }
    }
}

void iterativePreorder(NODE* root) {
    if (!root) return;
    NODE* stack[MAX];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        NODE* curr = stack[top--];
        printf("%d ", curr->data);
        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
}

void levelorder(NODE* root) {
    if (!root) return;
    NODE* queue[MAX];
    int rear = -1;
    int front = -1;
    queue[++rear] = root;
    while (front != rear) {
        NODE* curr = queue[++front];
        printf("%d ", curr->data);
        if (curr->left) queue[++rear] = curr->left;
        if (curr->right) queue[++rear] = curr->right;
    }
}

//NO SAFETY. ASSUMES VALID PATH.
void insert(NODE** root, int x, char path[]) {
    if (strcmp(path, "") == 0) {
        *root = createNode(x);
        return;
    }
    
    NODE* trav = *root;
    int i = 0;
    for (; path[i+1] != '\0'; i++) {
        char c = path[i];
        if (c == 'L') {
            trav = trav->left;
        } else {
            trav = trav->right;
        }
    }
    NODE* newnode = createNode(x);
    if (path[i] == 'L') {
        trav->left = newnode;
    } else {
        trav->right = newnode;
    }
}

NODE* findNode(NODE* root, int x) {
    if (!root) return NULL;
    if (root->data == x) return root;
    NODE* node;
    node = findNode(root->left, x);
    if (node) return node;
    node = findNode(root->right, x);
    return node;
}

NODE* copyTree(NODE* root) {
    if (!root) return NULL;
    NODE* tree = createNode(root->data);
    if (root->left) tree->left = copyTree(root->left);
    if (root->right) tree->right = copyTree(root->right);
    return tree;
}

int getHeight(NODE* root) {
    if (!root) return 0;
    int a = getHeight(root->left);
    int b = getHeight(root->right);
    return 1 + (a > b ? a : b);
}

int nodeCount(NODE* root) {
    static int n = 0;
    if (!root) return n;
    nodeCount(root->left);
    n += 1;
    nodeCount(root->right);
    return n;
}

int leafNodeCount(NODE* root) {
    static int n = 0;
    if (!root) return n;
    leafNodeCount(root->left);
    if (!root->left && !root->right) n += 1;
    leafNodeCount(root->right);
    return n;
}

int isEqual(NODE* r, NODE* s) {
    if (!r && !s) return 1;
    if (!r || !s) return 0;
    return (r->data == s->data) && isEqual(r->left, s->left) && isEqual(r->right, s->right);
}

NODE* createPostfixTree(char expr[]) {
    NODE* stack[MAX];
    int top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            stack[++top] = createNode(c);
        } else {
            NODE* y = stack[top--];
            NODE* x = stack[top--];
            NODE* e = createNode(c);
            e->left = x;
            e->right = y;
            stack[++top] = e;
        }
    }
    return stack[top--];
}

int postfixTreeEval(NODE* root) {
    if (!root) return 0;

    int x = postfixTreeEval(root->left);
    int y = postfixTreeEval(root->right);

    switch(root->data) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        default: return root->data - 48;
    }
}

void createBST(NODE** root, int x) {
    if (!*root) {
        *root = createNode(x);
        return;
    }

    if ((*root)->data > x) createBST(&((*root)->left), x);
    if ((*root)->data < x) createBST(&((*root)->right), x);
}

void iterativeCreateBST(NODE** root, int x) {
    NODE* newnode = createNode(x);
    if (!*root) {
        *root = newnode;
        return;
    }
    NODE* trav = *root;
    while (trav) {
        if (trav->data > x) {
            if (trav->left) {
                trav = trav->left;
            } else {
                trav->left = newnode;
                return;
            }
        } else if (trav->data < x) {
            if (trav->right) {
                trav = trav->right;
            } else {
                trav->right = newnode;
                return;
            }
        }
    }
}

NODE* searchBST(NODE* root, int x) {
    if (!root) return NULL;
    if (root->data == x) return root;
    if (x < root->data) return searchBST(root->left, x);
    if (x > root->data) return searchBST(root->right, x);
}

NODE* iterativeSearchBST(NODE* root, int x) {
    while (root) {
        if (x < root->data) {
            root = root->left;
        } else if (x > root->data) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

NODE* maxBST(NODE* root) {
    if (!root) return NULL;
    NODE* trav = root;
    while (trav->right) {
        trav = trav->right;
    }
    return trav;
}

NODE* minBST(NODE* root) {
    if (!root) return NULL;
    NODE* trav = root;
    while (trav->left) {
        trav = trav->left;
    }
    return trav;
}

//This one's a fucking mess. Almost as bad as the slides code. Probably skip it if time pressed.
void deleteNodeBST(NODE** root, int x) {
    NODE* trav = *root;
    NODE* prev = NULL;
    while (trav) {
        if (x < trav->data) {
            prev = trav;
            trav = trav->left;
        } else if (x > trav->data) {
            prev = trav;
            trav = trav->right;
        } else {
            break; //Node found.
        }
    }
    if (!trav->left && !trav->right) {
        if (prev->left == trav) {
            prev->left = NULL;
        } else {
            prev->right = NULL;
        }
        free(trav); //THIS WORKS!
    } else if (!trav->right) {
        if (prev->left == trav) {
            prev->left = trav->left;
        } else {
            prev->right = trav->left;
        }
        free(trav); //WORKS!
    } else if (!trav->left) {
        if (prev->left == trav) {
            prev->left = trav->right;
        } else {
            prev->right = trav->right;
        }
        free(trav); //WORKS!
    } else {
        NODE* max = trav->left;
        NODE* par = trav;
        while (max->right) {
            par = max;
            max = max->right;
        }
        trav->data = max->data;
        if (par->left == max) {
            par->left = NULL;
        } else {
            par->right = NULL;
        }
        free(max); //finally, also works
    }
}

int ancestors(NODE* root, int x) {
    if (!root) return 0;
    if (root->data == x) return 1;
    if (ancestors(root->left, x) || ancestors(root->left, x)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}