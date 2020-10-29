// Github Username: CRJain

// C Program to print mirror of binary tree.
#include <stdio.h>
#include <stdlib.h>

// Creating structure for tree nodes
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

// Function to create a new node in tree
struct node* createNewNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// Function to make mirror of a tree
void mirror(struct node* root)
{
	if(root == NULL)
		return;
	else
	{
		mirror(root->left);
		mirror(root->right);

		struct node* temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

// Function for inorder traversal of tree
void inOrderTraverse(struct node* root)
{
	if(root == NULL)
		return;

	inOrderTraverse(root->left);
	printf("%d ", root->data);
	inOrderTraverse(root->right);
}

int main()
{
	struct node* root = createNewNode(1);
	root->left = createNewNode(2);
	root->right = createNewNode(3);
	root->left->left = createNewNode(4);
	root->left->right = createNewNode(5);

	printf("Inorder Traversal of Original Tree:\n");
	inOrderTraverse(root);

	mirror(root);

	printf("\nInorder Traversal of Mirror of Original Tree:\n");
	inOrderTraverse(root);
	printf("\n");

	return 0;
}
