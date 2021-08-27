// Binary search tree example
// C99
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _BNode
{
    int data;
    struct _BNode *pLeft;
    struct _BNode *pRight;
} BNode;

BNode * addNode(int data)
{
    BNode *pNode = malloc(1*sizeof(BNode));
    pNode->data = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    return pNode;
}

void insertNode(BNode* pNode, int data)
{
    if (pNode != NULL)
    {
        // left (<)
        if (data < pNode->data)
        {
            if (pNode->pLeft == NULL)
            {
                pNode->pLeft = addNode(data);
            }
            else
            {
                insertNode(pNode->pLeft, data);
            }
        }
        // right (>=)
        else
        {
            if (pNode->pRight == NULL)
            {
                pNode->pRight = addNode(data);
            }
            else
            {
                insertNode(pNode->pRight, data);
            }
        }
    }
}

void deleteAllNodes(BNode *pNode)
{
    // using post-order transversal, delete the tree
    if (pNode != NULL)
    {
        deleteAllNodes(pNode->pLeft);
        deleteAllNodes(pNode->pRight);
        free(pNode);
    }
}

void printDataInOrder(BNode *pNode)
{
    if (pNode != NULL)
    {
        printDataInOrder(pNode->pLeft);
        printf("%d\n", pNode->data);
        printDataInOrder(pNode->pRight);
    }
}

void printDataPreOrder(BNode *pNode)
{
    if (pNode != NULL)
    {
        printf("%d\n", pNode->data);
        printDataPreOrder(pNode->pLeft);
        printDataPreOrder(pNode->pRight);
    }
}

void printDataPostOrder(BNode *pNode)
{
    if (pNode != NULL)
    {
        printDataPostOrder(pNode->pLeft);
        printDataPostOrder(pNode->pRight);
        printf("%d\n", pNode->data);
    }
}

int main(void)
{
    // Create root of tree
    BNode *pRoot = addNode(4);
    // Add nodes to tree
    /* insertNode(pRoot, 2);
    insertNode(pRoot, 6);
    insertNode(pRoot, 1);
    insertNode(pRoot, 3);
    insertNode(pRoot, 5);
    insertNode(pRoot, 7); */
    insertNode(pRoot, 2);
    insertNode(pRoot, 5);
    insertNode(pRoot, 9);
    insertNode(pRoot, 7);
    insertNode(pRoot, 6);
    insertNode(pRoot, 1);
    insertNode(pRoot, 3);
    printf("In-order transversal (prints in tree order)\n");
    printDataInOrder(pRoot);
    printf("Pre-order transversal\n");
    printDataPreOrder(pRoot);
    printf("Post-order transversal (same as delete)\n");
    printDataPostOrder(pRoot);
    deleteAllNodes(pRoot);
    return EXIT_SUCCESS;
}
