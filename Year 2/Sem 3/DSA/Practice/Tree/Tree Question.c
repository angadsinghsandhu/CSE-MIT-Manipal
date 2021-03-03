#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
} BstNode;

BstNode* root = NULL;

BstNode* createNode(int data){
    BstNode* temp = (BstNode *) malloc(sizeof(BstNode));
    temp -> data = data;
    return temp;
}

BstNode* Insert (BstNode* base, int data){
    // check for null
    if (base == NULL)
        return createNode(data);
    else if(data < base -> data)
        base -> left = Insert(base->left, data);
    else if(base -> data < data)
        base -> right = Insert(base->right, data);
    return base;
}

BstNode* Delete(BstNode* base, int data){
    // null condition
    if (base == NULL)
        return base;
    else if (data > base->data)
        base -> right = Delete(base->right, data);
    else if (data < base->data)
        base -> left = Delete(base->left, data);
    else {
        if (base -> left == NULL && base -> right == NULL){
            free(base);
            printf("\n...\n");
            return NULL;
        } else if (base -> left == NULL){
            BstNode* temp = base -> right;
            free(base);
            return temp;
        } else if (base -> right == NULL) {
            BstNode* temp = base -> left;
            free(base);
            return temp;
        }
    }

    return base;
}



void inorder(BstNode* base){
    // checking null condition
    if (base != NULL) {
        inorder(base -> left);
        printf("%5d", base -> data);
        inorder(base -> right);
    }
}

void main() {
    int ch, data;

    printf("################### MENU ###################\n\n");
    for( ;; ) {
        printf("== CHOOSE OPTION ==\n");
        printf("(option-1) Insert\n");
        printf("(option-2) Delete\n");
        printf("(option-3) Display\n");
        printf("(option-4) Exit\n");
        printf("Enter Option : ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1: 
                printf("Enter Integer to Insert : ");
                scanf("%d", &data);
                root = Insert(root, data);
                break;
            case 2: 
                printf("Enter Integer to Delete : ");
                scanf("%d", &data);
                Delete(root, data);
                break;
            case 3: 
                printf("The Tree is : ");
                inorder(root);
                break;
            case 4: 
                printf("Exiting...");
                break;
            default: 
                printf("Wrong Entry\n");
                break;
        }
        
        printf("\n\n");

    }
}






