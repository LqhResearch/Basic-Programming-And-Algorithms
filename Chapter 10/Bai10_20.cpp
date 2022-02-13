#include <stdio.h>
/*
	Dem so luong nut co dung 1 con.
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

	/*Dem so luong nut co dung 1 con*/
int Count1Con(TREE root) {
	if(root != NULL) {
		int a = Count1Con(root->left);
		int b = Count1Con(root->right);
		if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) //1 con
			return 1 + a + b;
		return a + b;
	}
	return 0;
}

	/*Main function*/
int main() {
	TREE bin;
	CreateTree(bin);
	
	printf("\nDuyet cay: ");
	NodeLeftRight(bin);
	
	printf("\nDem so luong nut co dung 1 con: %d", Count1Con(bin));
	return 0;
}

