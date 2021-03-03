/******************************************************************************

                    #1 : Tree Data Structure Implementation

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining NODE Structure
struct BstNode
{
    struct BstNode *left;
    int data;
    struct BstNode *right;
};

// creating root Node and setting it as NULL
struct BstNode *root = NULL;

// function to create new Node
struct BstNode *CreateNode(int data)
{
    struct BstNode *newNode = (struct BstNode *) malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// insert function for creating new Node
struct BstNode *Insert(struct BstNode *base, int data)
{

    // special case : (Empty Tree)
    if (base == NULL)
    {
        base = CreateNode(data);

        return base;
    }

    // as tree is not empty, now we check
    // if data is greater or lesser than root
    else if (data < base->data)
    {
        // recursive call to add to left
        base->left = Insert(base->left, data);
    }
    else
    {
        // recursive call to add to right
        base->right = Insert(base->right, data);
    }

    return base;
}

// function to fing an element
int Search(struct BstNode *base, int data)
{
    if (base == NULL)
        return 0;
    else if ((base->data) == data)
        return 1;
    else if (data > (base->data))
        return Search(base->right, data);
    else
        return Search(base->left, data);
}

// Main Driver Function
int main()
{
    int i, j = 2;
    // root = NULL;
    printf("\nEntering 10, 15, 20 into tree\n");

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);

    printf("Entering Number to be Searched : ");
    scanf("%d", &i);

    j = Search(root, i);

    if (j == 1)
    {
        printf("\nNumber Found!!!");
    }
    else
    {
        printf("\nNumber NOT Found :(");
    }

    return 0;
}
