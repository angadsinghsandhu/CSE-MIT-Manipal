#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head;

void Insert(int x) {
    // printf("...0");
    
    // create node
    Node* temp = (Node*) malloc(sizeof(Node*));
    temp -> data = x;
    temp -> next = NULL;
    
    // printf("...1");

    if (head == NULL) {
        temp -> next = head;
        head = temp;
        return;
    }

    // creating temp variable
    Node* temp1 = head;

    // looping
    while (temp1 -> next != NULL)
        temp1 = temp1 -> next;

    temp1 -> next = temp;
    return;
}

int Pop(){
    int num;
    
    // empty condition 
    if(head==NULL){
        printf("\n[ Empty Stack ]\n");
        return -1;
    }

    // looping to the end
    Node* temp1 = head;
    Node* temp2 = head -> next;

    while(temp2 -> next != NULL){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }

    num = temp2 -> data;

    temp1 -> next = NULL;
    free(temp2)

    return num;

}

void PrintList(){
    printf("The List is : ");
    
    // empty condition
    if (head == NULL){
        printf("[EMPTY]");
        return;
    }
    
    Node* temp = head;


    // looping
    while(temp != NULL){
        printf("%5d", temp->data);
        temp = temp -> next;
    }

    printf("\n");
}

void main(){
    int ch, x, flag=0;

    printf("################ MENU ################\n\n");

    for ( ;; ){
        printf("== Enter Choice ==\n");
        printf("(option - 1) Insert (PUSH)\n");
        printf("(option - 2) Print\n");
        printf("(option - 3) Remove Last (POP)\n");
        printf("(option - 4) Exit\n");
        printf("Your Choice : ");
        scanf(" %d", &ch);
        
        switch(ch){
            case 1:
                printf("\nEnter Integer : ");
                // printf("...4\n");
                scanf("%d", &x);
                // printf("%d", x);
                Insert(x);
                break;
            case 2:
                printf("\n");
                PrintList();
                break;
            case 3:
                x = Pop();
                if (x == -1){
                    printf("Error Occured\n");
                } else {
                    printf("poped element is : %d", x);
                }
                break;
            case 4:
                printf("\nExiting...");
                flag = 1;
                break;
            default:
                printf("Incorrect Choice :: Try Again...\n");
                break;
        }

        printf("\n");

        if (flag == 1)
            break;
    }
}