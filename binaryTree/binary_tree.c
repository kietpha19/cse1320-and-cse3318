#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _BNode
{
    int data;
    struct _BNode *pLeft;
    struct _BNode *pRight;
} BNode;

BNode *newBNode(int data)
{
    BNode *pNode = malloc(1 * sizeof(BNode));
    pNode->data = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    return pNode;
}

void insertNode(BNode *pRoot, int data)
{
    if (pRoot == NULL || pRoot->data == data)
    {
        if (pRoot == NULL)
        {
            pRoot = newBNode(data);
        }
        return;
    }
    if (data < pRoot->data)
    {
        if (pRoot->pLeft == NULL)
        {
            pRoot->pLeft = newBNode(data);
            return;
        }
        insertNode(pRoot->pLeft, data);
    }
    else
    {
        if (pRoot->pRight == NULL)
        {
            pRoot->pRight = newBNode(data);
            return;
        }
        insertNode(pRoot->pRight, data);
    }
}

typedef struct _TD
{
    int value[10];
    int depth[10];
    int count;
    int level;
} TD;

void buildTreeDatabase(BNode *pNode, TD *pTD)
{
    if (pNode != NULL)
    {
        pTD->level++;
        buildTreeDatabase(pNode->pLeft, pTD);
        pTD->value[pTD->count] = pNode->data;
        pTD->depth[pTD->count++] = pTD->level;
        buildTreeDatabase(pNode->pRight, pTD);
        pTD->level--;
    }
}

void printTree(BNode *pRoot)
{
    char data[10][10];
    int i, j;
    TD treeData;
    if (pRoot != NULL)
    {
        treeData.count = 0;
        treeData.level = -1;
        buildTreeDatabase(pRoot, &treeData);
        for (i = 0; i < 10; i++)
            for (j = 0; j < 10; j++)
                data[i][j] = ' ';
        for (i = 0; i < treeData.count; i++)
            data[treeData.depth[i]][i] = '0' + treeData.value[i];
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                printf("%c ", data[i][j]);
            }
            printf("\n");
        }
    }
}

void deleteTree(BNode *pRoot)
{
    if (pRoot == NULL)
        return;
    deleteTree(pRoot->pLeft);
    deleteTree(pRoot->pRight);
    free(pRoot);
}

void printDataInOrder(BNode *pRoot)
{
    if (pRoot == NULL)
        return;
    printDataInOrder(pRoot->pLeft);
    printf("%d\t", pRoot->data);
    printDataInOrder(pRoot->pRight);
}

void printDataPreOrder(BNode *pRoot)
{
    if (pRoot == NULL)
        return;
    printf("%d\t", pRoot->data);
    printDataPreOrder(pRoot->pLeft);
    printDataPreOrder(pRoot->pRight);
}

void printDataPostOrder(BNode *pRoot)
{
    if (pRoot == NULL)
        return;
    printDataPostOrder(pRoot->pLeft);
    printDataPostOrder(pRoot->pRight);
     printf("%d\t", pRoot->data);
}

bool isDataPresentBt(BNode *pRoot, int data)
{
    //be carefull the position of different if statement
    //make sure to check whether the root is null first
    //otherwise, when the function travel to null node, pRoot->data causes segmentation fault.
    if (pRoot == NULL)
    {
        return false;
    }
    if (pRoot->data == data)
    {
        return true;
    }
    return (isDataPresentBt(pRoot->pLeft, data) || isDataPresentBt(pRoot->pRight, data));
}

bool isDataPresentBst(BNode *pRoot, int data)
{
    if (pRoot == NULL)
    {
        return false;
    }
    if (pRoot->data == data)
    {
        return true;
    }
    if (data < pRoot->data)
    {
        return isDataPresentBst(pRoot->pLeft, data);
    }
    else //(data > pRoot->data)
    {
        return isDataPresentBst(pRoot->pRight, data);
    }
}

int getGreatestDepth(BNode *pRoot){
    // cant use the condition pRoot->pleft and pright == null
    // because there is the case when one side of the tree is null and the other is not
    // then, when the else statement execute, it causes segmentation fault
    if(pRoot == NULL){
        return -1;
    }
    else{
        if(getGreatestDepth(pRoot->pLeft) >= getGreatestDepth(pRoot->pRight)){
            return (1+getGreatestDepth(pRoot->pLeft));
        }else{
            return (1+getGreatestDepth(pRoot->pRight));
        }
    }
}

int getDepth(BNode *pRoot, int data, int d){
    if(pRoot == NULL)
        return -1;
    if(pRoot->data == data)
        return d;

    
    int checkLeft = getDepth(pRoot->pLeft, data, d+1);
    if(checkLeft != -1){
        return checkLeft;
    }

    return getDepth(pRoot->pRight, data, d+1);

}

int getDepthOfData(BNode *pRoot, int data){
    return getDepth(pRoot, data, 0);

    // this doesn't work because there is no way to check whether the subtree has included the data. 
    // we also have to keep track of the depth that we traverse the tree by increment the depth by 1 each time we call reverusive
    //therefore, the easiest way is to pass the depth to another function and keep it as a variable. 
    /* if(pRoot == NULL)
        return -1;
    if(pRoot->data == data)
        return 0;
    int checkLeft = 1 + getDepthOfData() */

}

int countNodes(BNode *pRoot){
    if(pRoot == NULL)
        return 0;
    return 1 + countNodes(pRoot->pLeft) + countNodes(pRoot->pRight);
}

int countNodesAtDepth_f(BNode *pRoot, int depth, int d){
    if(pRoot == NULL)
        return 0;
    if(d<depth){
        return countNodesAtDepth_f(pRoot->pLeft, depth, d+1) + countNodesAtDepth_f(pRoot->pRight, depth, d+1);
    }
    return 1;
}

int countNodesAtDepth(BNode *pRoot, int depth){
    return countNodesAtDepth_f(pRoot, depth, 0);
}

int main(void)
{
    BNode *pRoot1 = newBNode(4);
    insertNode(pRoot1, 2);
    insertNode(pRoot1, 6);
    insertNode(pRoot1, 1);
    insertNode(pRoot1, 3);
    insertNode(pRoot1, 5);
    insertNode(pRoot1, 7);

    printf("%d\n", pRoot1->data);
    printf("%d\n", pRoot1->pLeft->data);
    printf("%d\n", pRoot1->pRight->data);

    printf("preorder\n");
    printDataPreOrder(pRoot1);
    printf("\n");

    printf("inorder\n");
    printDataInOrder(pRoot1);
    printf("\n");

    printf("postorder\n");
    printDataPostOrder(pRoot1);
    printf("\n");

    printTree(pRoot1);

    bool check = isDataPresentBt(pRoot1, 5);
    printf("%d\n", check);

    check = isDataPresentBst(pRoot1, 9);
    printf("%d\n", check);
    printf("\n");

    BNode *pRoot2 = newBNode(6);
    insertNode(pRoot2, 2);
    insertNode(pRoot2, 7);
    insertNode(pRoot2, 9);
    insertNode(pRoot2, 3);
    insertNode(pRoot2, 8);
    insertNode(pRoot2, 1);
    insertNode(pRoot2, 4);


    printTree(pRoot2);
    check = isDataPresentBst(pRoot2, 8);
    printf("%d\n", check);

    int gd = getGreatestDepth(pRoot1);
    printf("greatest depth of tree 1: %d\n", gd);

    gd = getGreatestDepth(pRoot2);
    printf("greatest depth of tree 2: %d\n", gd);

    int d = getDepthOfData(pRoot2, 3);
    printf("depth of 3: %d\n", d);

    int c1 = countNodes(pRoot1);
    printf("nodes in tree 1: %d\n", c1);
    int c2 = countNodes(pRoot2);
    printf("nodes in tree 2: %d\n", c2);

    int nodeAtDepth = countNodesAtDepth(pRoot1, 2);
    printf("%d\n", nodeAtDepth);

    
    return EXIT_SUCCESS;
}