/******************************************************************************

                    #2 : Min and Max  element in BST

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining NODE Structure
struct BstNode
{
    struct BstNode *left;
    struct BstNode *right;
    int data;
};

// creating empty tree with NULL root Node
struct BstNode *root = NULL;

// function to create new Node
struct BstNode *CreateNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
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

// function to find an element
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

// function to find smallest element
int FindMin(struct BstNode *base)
{
    
    // special case : (Empty Tree)
    if (base == NULL)
    {
        printf("Empty Tree!!");
        return -1;
    } 
    
    // special case : (Left Tree Empty)
    else if (base->left == NULL){
        return base->data;
    }
    
    // iterative method
    while(base->left != NULL){
        base = base->left;
    }
    
    return base->data;
}

// function to find largest element
int FindMax(struct BstNode *base)
{
    // special case : (Empty Tree)
    if (base == NULL)
    {
        printf("Empty Tree!!");
        return -1;
    } 
    
    // special case : (Left Tree Empty)
    else if (base->right == NULL){
        return base->data;
    }
    
    // recursive method
    return FindMax(base->right);
}

// Main Driver Function
int main()
{
    // variables
    int n = 0, i, j = 2, temp;
    
    // querying user
    printf("\nEnter the number of nodes tree : ");
    scanf("%d", &n);
    
    // creating array to store elements of tree
    int arr[n];
    
    printf("\nEntering values for tree");
    for(i=0; i<n; i++){
        printf("Enter value of Node %d : ", i+1);
        scanf("%d", &temp);
        
        // assigning to tree and adding to array
        arr[i] = temp;
        root = Insert(root, temp);
    }

    printf("\n\nEntering Number to be Searched\nin the tree of ");
    for(i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }
    printf(": ", arr[i]);
    scanf("%d", &i);
    
    // searching
    j = Search(root, i);

    if (j == 1)
    {
        printf("\nNumber Found!!!");
    }
    else
    {
        printf("\nNumber NOT Found :(");
    }
    
    printf("\n\nLargest Number in tree is : %d", FindMax(root));
    printf("\nSmallest Number in tree is : %d", FindMin(root));

    return 0;
}
