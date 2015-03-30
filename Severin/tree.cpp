#include <stdio.h>

struct Node
{
	int data;
	Node *left = NULL;
	Node *right = NULL;
	Node *parent = NULL;
};

Node *search(Node *root, int x)
{
	while(root)
	{
		if(root->data == x)
			return root;
		else if(root->data < x)
			root = root->right;
		else root = root->left;
	}
	return NULL;
}

void insert(Node **root, int data)
{
	Node *New = new Node;
	New->data = data;
	Node *parent = NULL;
	Node *current = *root;
	while(current)
	{
		parent = current;
		if(New->data < current->data)
			current = current->left;
		else
			current = current->right;
	}
	New->parent = parent;
	if(NULL == parent)
		*root = New;
	else if(New->data < parent->data)
			parent->left = New;
		else
			parent->right = New; 

}

Node *minimum(Node *root)
{
	Node *current = root;
	if (!current)
		return NULL;
	while(current->left)
	{
		current = current->left;
	}
	return current;
}

Node *maximum(Node *root)
{
	Node *current = root;
	if (!current)
		return NULL;
	while(current->right)
	{
		current = current->right;
	}
	return current;
}

Node *prev(Node *n)
{
	if(n->left)
		return maximum(n->left);
	else
	{
		while(n)
		{
			if(n->parent->right == n)
				return n->parent;
			n = n->parent;
		}
		return NULL;
	}
}

Node *next(Node *n)
{
	if(n->right)
		return minimum(n->right);
	else
	{
		while(n)
		{
			if(n->parent->left == n)
				return n->parent;
			n = n->parent;
		}
		return NULL;
	}
}

void ChangeParentChild(Node *n, Node *New)
{
	if(n->parent->right == n)
			n->parent->right = New;
		else n->parent->left = New;
}

int Delete(Node **root, Node *n)
{
	if(!n) 
	{
		printf("error node not exist\n");
		return 0;
	}
	int tmp = n->data;
	if(!n->right && !n->left)
	{
		ChangeParentChild(n, NULL);
	}
	else if(!n->right)
	{
		n->left->parent = n->parent;
		ChangeParentChild(n, n->left);
	}
	else if(!n->left)
	{
		n->right->parent = n->parent;
		ChangeParentChild(n, n->right);
	}
	else
	{
		Node *tmp1 = n;
		n = next(n);
		tmp1->data = n->data;
		ChangeParentChild(n, NULL);
	}
	delete n;
	return tmp;
}

void inorderWalk (Node *root) 
{
	if (root != NULL) 
	{
		inorderWalk (root->left);
		printf("%d\t", root->data);
		inorderWalk (root->right);
	}
}

int main(int argc, char const *argv[])
{
	Node *root = NULL; 
	return 0;
}
