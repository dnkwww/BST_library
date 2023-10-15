#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

// 資料節點
typedef struct myBST {
    btreeNode_t treeNode;
    char ID[10];
    int math;
    int eng;
} student_t;

// 用來比較節點的function
int compareID(void *elementA, void *elementB) {
    int i;
    char *aid = ((student_t *)elementA)->ID;
    char *bid = ((student_t *)elementB)->ID;
    for (i=0;i<10;i++) {
        if(aid[i]>bid[i]) {
            return 1;
        }else if(aid[i]<bid[i]){
            return -1;
        }
    }
    return 0;
}

// 用來將結點印出的function
void print(void *element)
{
    student_t *cur = (student_t *)element;
    printf("ID[%s]: math=%d, eng=%d\n", cur->ID, cur->math, cur->eng);
}

int main()
{
    // 使用範例：

    // 初始化BST(樹A)
    btreeNode_t *treeRoot = NULL;

    // 宣告資料節點1
    student_t *node1 = (student_t *)malloc(sizeof(student_t));
    strcpy(node1->ID, "A4");
    node1->math = rand() % 100;
    node1->eng = rand() % 100;
    node1->treeNode.left = NULL;
    node1->treeNode.right = NULL;
    treeRoot = insertNode(node1, treeRoot, compareID); // 插入進去樹裡

    // 資料節點2
    student_t *node2 = (student_t *)malloc(sizeof(student_t));
    strcpy(node2->ID, "A2");
    node2->math = rand() % 100;
    node2->eng = rand() % 100;
    node2->treeNode.left = NULL;
    node2->treeNode.right = NULL;
    treeRoot = insertNode(node2, treeRoot, compareID);

    // 資料節點3
    student_t *node3 = (student_t *)malloc(sizeof(student_t));
    strcpy(node3->ID, "A6");
    node3->math = rand() % 100;
    node3->eng = rand() % 100;
    node3->treeNode.left = NULL;
    node3->treeNode.right = NULL;
    treeRoot = insertNode(node3, treeRoot, compareID);

    // 資料節點4
    student_t *node4 = (student_t *)malloc(sizeof(student_t));
    strcpy(node4->ID, "A1");
    node4->math = rand() % 100;
    node4->eng = rand() % 100;
    node4->treeNode.left = NULL;
    node4->treeNode.right = NULL;
    treeRoot = insertNode(node4, treeRoot, compareID);

    // 資料節點5
    student_t *node5 = (student_t *)malloc(sizeof(student_t));
    strcpy(node5->ID, "A3");
    node5->math = rand() % 100;
    node5->eng = rand() % 100;
    node5->treeNode.left = NULL;
    node5->treeNode.right = NULL;
    treeRoot = insertNode(node5, treeRoot, compareID);

    // 資料節點6
    student_t *node6 = (student_t *)malloc(sizeof(student_t));
    strcpy(node6->ID, "A5");
    node6->math = rand() % 100;
    node6->eng = rand() % 100;
    node6->treeNode.left = NULL;
    node6->treeNode.right = NULL;
    treeRoot = insertNode(node6, treeRoot, compareID);

    // 資料節點7
    student_t *node7 = (student_t *)malloc(sizeof(student_t));
    strcpy(node7->ID, "A7");
    node7->math = rand() % 100;
    node7->eng = rand() % 100;
    node7->treeNode.left = NULL;
    node7->treeNode.right = NULL;
    treeRoot = insertNode(node7, treeRoot, compareID);

    // 找節點
    printf("\nmin:");
    print(findMinNode(treeRoot));

    // 找最大節點
    printf("\nmax:");
    print(findMaxNode(treeRoot));

    // 找最小節點
    printf("\nnode6:");
    print(findNode(node6, treeRoot, compareID));

    // 中序遍歷
    printf("\ninorder:\n");
    inOrder(treeRoot, print);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);

    return 0;
}
