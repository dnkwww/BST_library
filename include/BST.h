#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct node {
    struct node *left;
    struct node *right;
} btreeNode_t;

btreeNode_t *insertNode(void *element, btreeNode_t *root, int (*compare)(void *elementA, void *elementB));

btreeNode_t *deleteNode(void *element, btreeNode_t *root, int (*compare)(void *elementA, void *elementB));

btreeNode_t *findMinNode(btreeNode_t *root);

btreeNode_t *findMaxNode(btreeNode_t *root);

btreeNode_t *findNode(void *element, btreeNode_t *root, int (*compare)(void *elementA, void *elementB));

void inOrder(btreeNode_t *root, void (*print)(void *element));

void treeCopy(btreeNode_t *A, btreeNode_t *B, void (*copy)(void *elementA, void *elementB));

int treeEqual(btreeNode_t *A, btreeNode_t *B, int (*compare)(void *elementA, void *elementB));

#endif // BST_H_INCLUDED
