#include <stdio.h>
#include <stdlib.h>

struct node {
 int key;
 struct node *left, *right;
};

struct node* newNode(int item)
{
 struct node* temp = (struct node*)malloc(sizeof(struct node));
 temp->key = item;
 temp->left = temp->right = NULL;
 return temp;
}

struct node* insert(struct node* node, int key)
{
 if (node == NULL)
 return newNode(key);
 if (key < node->key)
 node->left = insert(node->left, key);
 else if (key > node->key)
 node->right = insert(node->right, key);
 return node;
}

// Helper Function to search
struct node* search(struct node* root, int key) {
 if (root == NULL || root->key == key)
 return root;

 if (root->key < key)
 return search(root->right, key);

 return search(root->left, key);
}

int searchAndInsert(struct node* root, int key)
{
 struct node* res = search(root, key);
 if(res) {
 printf("Key Found\n");
 } else {
 printf("Key Not Found. Inserting into BST\n");
 insert(root, key);
 }
}

void inorder(struct node* node)
{
 if (node == NULL)
 return;
 inorder(node->left);
 printf("%d ", node->key);
 inorder(node->right);
}

void preorder(struct node* node)
{
 if (node == NULL)
 return;
 printf("%d ", node->key);
 preorder(node->left);
 preorder(node->right);
}

void postorder(struct node* node)
{
 if (node == NULL)
 return;
 postorder(node->left);
 postorder(node->right);
 printf("%d ", node->key);
}

int main()
{
 struct node* root = NULL;
 int ch = 100;
 int rootVal;
 printf("Root Node Value: ");
 scanf("%d", &rootVal);
 root = insert(root, rootVal);
 printf ("\n-------Menu--------");
 printf ("\n1- Insert");
 printf ("\n2- Search");
 printf ("\n3- Inorder");
 printf ("\n4- Preorder");
 printf ("\n5- Postorder");
 printf ("\n6- Quit");
 printf ("\n--------------------");
 while(ch != 6) {
 printf("\nChoice: ");
 scanf("%d", &ch);
 
 switch(ch) {
 case 1: {
 int n = 0;
 printf("Insert Value: ");
 scanf("%d", &n);
 insert(root, n);
 break;
 }
 case 2: {
 int n = 0;
 printf("Search Value: ");
 scanf("%d", &n);
 searchAndInsert(root, n);
 break;
 }
 case 3: {
 printf("Inorder Traversla:\n");
 inorder(root);
 printf("\n");
 break;
 }
 case 4: {
 printf("Preorder Traversla:\n");
 preorder(root);
 printf("\n");
 break;
 }
 case 5: {
 printf("Postorder Traversla:\n");
 postorder(root);
 printf("\n");
 break;
 }
 case 6: {
 printf("Goodbye!\n");
 break;
 }
 default: {
 printf("Invalid Choice. Quitting\n");
 ch = 6;
 }
 }
 }
 return 0;
}