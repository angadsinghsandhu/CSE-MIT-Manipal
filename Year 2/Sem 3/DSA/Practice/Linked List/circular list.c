#include <stdio.h>
#include <stdlib.h>

// define structure
typedef struct Node {
    int data;
    struct Node* left, right;
} Node;

Node* createNode(int x){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> data = x;
    temp -> left = temp -> right = NULL;
    return temp;
}

Node Insert(Node* base, int x){
    // null condition
}

Node readlong(){

}

Node* addLong(Node A, Node B){
    
}


void main(){
    Node* A, B, sum;
    A = readlong();
    B = readlong();
    sum = addLong(A, B);

    printf("Sum : ");
    display(&sum);
}
