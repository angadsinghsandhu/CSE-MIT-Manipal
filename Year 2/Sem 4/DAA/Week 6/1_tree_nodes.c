#include<stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
 
node *create(){
	node *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	p=(node*)malloc(sizeof(node));
	p->data=x;
	printf("Enter left child of %d:\n",x);
	p->left=create();
 	printf("Enter right child of %d:\n",x);
	p->right=create();
	return p;
}
 
int cnt = 0;

int num_nodes(node *p){
	if(!p){
		cnt++;
		return 0;
	}
	cnt++;

	return 1 + num_nodes(p->left) + num_nodes(p->right);
}

 
int main(){
	node *root;
	root=create();
	int n_nodes = 0;
	n_nodes = num_nodes(root);
	printf("Number of Nodes: %d",n_nodes);
	printf("\nCount: %d",cnt);

}