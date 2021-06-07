// Q1
#include<stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)
 
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
 
node* create(node *bnode,int x){
	if(bnode==NULL){
		bnode=(node*) malloc(sizeof(node));
		bnode->data=x;
		bnode->left=bnode->right=NULL;
	}
	else if(x>bnode->data)
		bnode->right=create(bnode->right,x);
	else if(x<bnode->data)
		bnode->left=create(bnode->left,x);
	else{
		printf("Duplicate node!");
	}
	return(bnode);
}

int height(node *p){
	if(p==NULL)
		return 0;
	int hL = height(p->left);
	int hR = height(p->right);
	int fac = hL - hR;
	printf("\nBalance Factor of Node %d: %d",p->data,fac);
	return MAX(hL,hR)+1;
}

void inorder(node *p){
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
}

 
int main(){
	int op, elem;
	node *root;
	root = NULL;
	do{
		printf("\nENTER OPTION:\n1.Insert\n2.Inorder Traversal\n3.Balance Factor\n4.Exit\nEnter Option: ");
		scanf("%d",&op);

		switch(op){
			case 1: printf("Enter data: ");
					scanf("%d",&elem);
					root = create(root,elem);
					break;
			case 2: inorder(root);
					break;
			case 3: height(root);
					break;
			case 4: break;
		}
	}while(op!=4);
}