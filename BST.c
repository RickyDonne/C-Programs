/*****************************************************
*C program to check if a tree is height-balanced or not
*AUTHOR: DEBARSHI BISWAS
*URN: 27600119051
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#define bool int

struct node {
	int data;
	struct node* left;
	struct node* right;
};

int height(struct node* node);
bool isBalanced(struct node* root);
int max(int a, int b);
struct node* newNode(int data);
void inorder (struct node *root);
struct node* insert(struct node* root,int x);
int FindHeight(struct node* root);

int main()
{
	struct node* root;
	root = newNode(20);
    insert(root, 23);
    insert(root, 24);
    insert(root, 45);
    insert(root, 15);
    insert(root, 17);
    inorder(root);

    printf("Height: %d\n", FindHeight(root));

	if (isBalanced(root))
		printf("Tree is balanced");
	else
		printf("Tree is not balanced");

	getchar();
	return 0;
}



bool isBalanced(struct node* root)
{
	int lh;
	int rh;

	if (root == NULL)
		return 1;
	lh = height(root->left);
	rh = height(root->right);
	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;

	return 0;
}

int FindHeight(struct node* root)
{
	if(root==NULL)
		return 0;

	else
	{
		int lb=FindHeight(root->left);
		int rb=FindHeight(root->right);
		return max(lb,rb)+1;
	}
}

int max(int a, int b)
{
	return (a >= b) ? a : b;
}


int height(struct node* node)
{
	if (node == NULL)
		return 0;
	return 1 + max(height(node->left), height(node->right));
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void inorder (struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}


struct node* insert(struct node* root,int x)
{
    if (root==NULL)
    {
        return newNode(x);
    }
    else if (x>root->data)
        root->right = insert(root->right,x);
    else
        root->left = insert(root->left,x);
    return root;
}
