// Q2
#include <stdio.h>
#include <stdlib.h>

static int count=0;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};


struct node* newNode(int data)
{
 struct node* temp=(struct node*)malloc(sizeof(struct node));
   temp->left=NULL;
   temp->right=NULL;
   temp->data=data;
   return temp;
}

struct node* CreateBinaryTree(int item)
{
  int x;

  if (item!=-1)
  {
    struct node* temp = newNode(item);

    printf("Enter left child of (%d) [ (-1) for prev child ]: ", item);
    scanf("%d",&x);

    temp->left = CreateBinaryTree(x);
    printf("Enter right child of (%d) [ (-1) for prev child ]: ",item);

    scanf("%d",&x);

    temp->right = CreateBinaryTree(x);
    return temp;
  }

  return NULL;
}

int max(int a,int b)
{
  if(a>b)
    return a;

  return b;
}

int diameter(struct node* root)
{
  if (root == NULL)
    return 0;

  int lh=height(root->left);
  int rh=height(root->right);

  int ld = diameter(root->left);
  int rd = diameter(root->right);

  return max(lh+rh+1, max(ld,rd));
}

int height(struct node* root)
{
  if (root == NULL)
    return 0;

  return 1 + max(height(root->left), height(root->right));
}

int main()
{
  struct node* root = NULL;
  int item;

  printf("Creating the tree...\nEnter root: ");
  scanf("%d",&item);
  root=CreateBinaryTree(item);
  printf("\nDiameter of tree is ");
  printf("%d",diameter(root));
}