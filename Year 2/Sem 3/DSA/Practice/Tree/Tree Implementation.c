#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
} BstNode;

struct BstNode* root = NULL;

struct BstNode* createNode(int num){
    struct BstNode* temp = (struct BstNode *) malloc(sizeof(struct BstNode));
    temp -> data = num;
    return temp;
}

struct BstNode* Insert(struct BstNode* base, int num){
    // empty tree condition
    if (base == NULL)
        return createNode(num);
    else if(num < base -> data)
        base -> left = Insert(base->left, num);
    else if(num > base -> data)
        base -> right = Insert(base->right, num);
    return base;
}

void preorder_display(struct BstNode* ptr){
    if (ptr != NULL){
        printf("%5d", ptr -> data);
        preorder_display(ptr -> left);
        preorder_display(ptr -> right);
    }
}

void inorder_display(struct BstNode* ptr){
    if(ptr != NULL){
        inorder_display(ptr -> left);
        printf("%5d", ptr->data);
        inorder_display(ptr -> right);
    }
}

void postorder_display(struct BstNode* ptr){
    if(ptr != NULL){
        postorder_display(ptr -> left);
        postorder_display(ptr -> right);
        printf("%5d", ptr->data);
    }
}

void main(){
    int ch, num;

    printf("########### MENU ###########\n\n");

    for(;;){
        printf("== Enter Option == \n");
        printf("(option - 1) Insert\n");
        printf("(option - 2) Display (in Pre-Order)\n");
        printf("(option - 3) Display (in In-Order)\n");
        printf("(option - 4) Display (in Post-Order)\n");
        printf("(option - 5) Display Root\n");
        printf("(option - 6) Exit\n");
        printf("Enter Option : ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter Number to Add to the Tree : ");
                scanf("%d", &num);
                root = Insert(root, num);
                break;
            case 2:
                printf("\nDisplaying in Pre-Order : ");
                preorder_display(root);
                break;
            case 3:
                printf("\nDisplaying in In-Order : ");
                inorder_display(root);
                break;
            case 4:
                printf("\nDisplaying in Post-Order : ");
                postorder_display(root);
                break;
            case 5:
                // printf("\nRoot is of Type : " + typeof(root) + "\n");
                // printf("\nRoot : %d\n", root);
                printf("\nRoot value : %d\n", root->data);
                postorder_display(root);
                break;
            case 6:
                printf("\nExiting...");
                break;
            default:
                printf("\n== Wrong Oprtion ==");
                break;
        }

        printf("\n\n");
    }
}