// AllNodeSumOfTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// allnodessum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void modifyBSTUtil(struct node *root, int *sum)
{
	// Base Case
	if (root == NULL)  return;

	modifyBSTUtil(root->right, sum);

	*sum = *sum + root->data;
	root->data = *sum;

	
	modifyBSTUtil(root->left, sum);
}

void modifyBST(struct node *root)
{
	int sum = 0;
	modifyBSTUtil(root, &sum);
}


void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given data in BST */
struct node* insert(struct node* node, int data)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(data);

	/* Otherwise, recur down the tree */
	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	/* return the (unchanged) node pointer */
	return node;
}

// Driver Program to test above functions
int _tmain(int argc, _TCHAR* argv[])
{
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 100);
	insert(root, 120);
	insert(root, 401);
	insert(root, 500);
	insert(root, 560);
	insert(root, 480);

	modifyBST(root);

	// print inoder tarversal of the modified BST
	inorder(root);

	return 0;
}





