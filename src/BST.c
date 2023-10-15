#include <stdlib.h>
#include "BST.h"

btreeNode_t *insertNode(void *element, btreeNode_t *root, int (*compare)(void *elementA, void *elementB)) //插入一個節點進BST內
{
    if(root == NULL)
        root = (btreeNode_t *)element;
    else
    {
        if(compare(element, root) == -1) // element < root, left
            root->left = insertNode(element, root->left, compare);
        else if(compare(element, root) == 1) // element > root , right
            root->right = insertNode(element, root->right, compare);
        else if(compare(element, root) == 0) {} // element == root, do nothing
    }
    return root;
}

btreeNode_t *deleteNode(void *element, btreeNode_t *root, int (*compare)(void *elementA, void *elementB)) //刪除BST一個節點
{
    btreeNode_t *temp;

    if(root == NULL) {} // 樹是空的
    else
    {
        if(compare(element, root) == -1) // 找左子
            root->left = deleteNode(element, root->left, compare);
        else if(compare(element, root) == 1) // 找右子
            root->right = deleteNode(element, root->right, compare);
        else if(compare(element, root) == 0) // 找到了
        {
            if(root->left && root->right) // 要刪的點同時有左子跟右子
            {
                temp = findMinNode(root->right); // 找右子中最小的值
                root = temp; // 使其取代他
                root->right = deleteNode(root, root->right, compare); // 刪掉要刪掉的值
            }
            else if(root->left == NULL) // 要刪的點只有右子
            {
                temp = root;
                root = root->right;
                free(temp);
            }
            else if(root->right == NULL) // 要刪的點只有左子
            {
                temp = root;
                root = root->left;
                free(temp);
            }
        }
    }
    return root;
}

btreeNode_t *findMinNode(btreeNode_t *root) //找出BST中鍵值最小的節點
{
    btreeNode_t *cur;
    while(root != NULL) // 第一圈：看root是否為空，第二圈：看root->left(此時為root)是否為空
    {
        cur = root;
        root = root->left;
    }
    return cur;
}

btreeNode_t *findMaxNode(btreeNode_t *root) //找出BST中鍵值最大的節點
{
    btreeNode_t *cur = root;
    while(root != NULL) // 邏輯同findMinNode
    {
        cur = root;
        root = root->right;
    }
    return cur;
}

btreeNode_t *findNode(void *element, btreeNode_t *root, int (*compare)(void *elementA, void *elementB)) //找出BST符合鍵值的節點
{
    if(root == NULL) {}
    else
    {
        if(compare(element, root) == -1) // 要找的比root小 => 在root左子
            return findNode(element, root->left, compare);
        else if(compare(element, root) == 1) // 要找的比root大 => 在root右子
            return findNode(element, root->right, compare);
        else if(compare(element, root) == 0) {} // 要找的就是root => do nothing
    }
    return root;
}

void inOrder(btreeNode_t *root, void (*print)(void *element)) //列印出BST根據中序追蹤法每個節點內容
{
    if(root)
    {
        inOrder(root->left, print);
        print(root);
        inOrder(root->right, print);
    }
}

void treeCopy(btreeNode_t *A, btreeNode_t *B, void (*copy)(void *elementA, void *elementB)) //把A複製到B
{
    if(A)
    {
        treeCopy(A->left, B->left, copy); // 複製左節點
        treeCopy(A->right, B->right, copy); // 複製右節點
        copy(A, B); // 把A的內容複製到B
    }
}

int treeEqual(btreeNode_t *A, btreeNode_t *B, int (*compare)(void *elementA, void *elementB)) //比較二個BST是否相同
{
    int flag = 1;
    if(A && B)
    {
        if(compare(A, B) != 0) // 比樹根
            flag = 0;
        else // 樹根一樣比下面的孩子
        {
            if(treeEqual(A->left, B->left, compare) == 0)
                flag = 0;
            if(treeEqual(A->right, B->right, compare) == 0)
                flag = 0;
        }
    }
    else if(!A && !B) {} // 都沒有東西
    else
        flag = 0;

    return flag;
}
