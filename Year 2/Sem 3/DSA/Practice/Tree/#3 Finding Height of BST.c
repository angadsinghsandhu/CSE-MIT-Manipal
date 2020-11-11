/******************************************************************************

                        #3 : Finding Height of BST

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// defining max() and min() functions
#define max(x,y) (((x) >= (y)) ? (x) : (y))
#define min(x,y) (((x) <= (y)) ? (x) : (y))

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

// function to find height of BST
int FindHeight(struct BstNode* base){
    if(base==NULL){
        return -1;
    }
    
    // recursive call
    return max(FindHeight(base->left), FindHeight(base->right)) + 1;
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
    
    printf("\nEntering values for tree\n");
    for(i=0; i<n; i++){
        printf("Enter value of Node %d : ", i+1);
        scanf("%d", &temp);
        
        // assigning to tree and adding to array
        arr[i] = temp;
        root = Insert(root, temp);
    }
    
    printf("\nHeight of tree is : %d", FindHeight(root));

    return 0;
}
