#include <stdio.h>
/*
	Viet ham nhap cac gia tri trong cay:
	-	Duyet cay theo thu tu truoc.
	-	Duyet cay theo thu tu giua.
	-	Duyet cay theo thu tu sau.
*/
typedef struct node {	//Node cua cay nhi phan
	int data;
	node *left;
	node *right;
} node;

typedef struct node *TREE;	//Tao cay nhi phan
	TREE root;	//node goc

	/*Tao cay nhi phan so nguyen*/
void CreateTree(TREE &root) {
	int n;
	printf("\nNhap gia tri: ");
	scanf("%d", &n);
	if(n != -1) {
		root = new node;
		root->data = n;
		printf("\nCay con trai cua %d: ", n);
		CreateTree(root->left);
		printf("\nCay con phai cua %d: ", n);
		CreateTree(root->right);
	}
	else root = NULL;
}

	/*Duyet cay theo thu tu truoc*/
void NodeLeftRight(TREE root)
{
	if (root != NULL)
	{
		printf("%5d", root->data);
		NodeLeftRight(root->left);
		NodeLeftRight(root->right);
	}
}

	/*Duyet cay theo thu tu giua*/
void LeftNodeRight(TREE root)
{
	if (root != NULL)
	{
		LeftNodeRight(root->left);
		printf("%5d", root->data);
		LeftNodeRight(root->right);
	}
}

	/*Duyet cay theo thu tu sau*/
void LeftRightNode(TREE root)
{
	if (root != NULL)
	{
		LeftRightNode(root->left);
		LeftRightNode(root->right);
		printf("%5d", root->data);
	}
}

	/*Main function*/
int main() {
	TREE bin;
	CreateTree(bin);
	
	printf("\nDuyet cay theo thu tu truoc: ");
	NodeLeftRight(bin);
	
	printf("\nDuyet cay theo thu tu giua: ");
	LeftNodeRight(bin);
	
	printf("\nDuyet cay theo thu tu sau: ");
	LeftRightNode(bin);
	return 0;
}

