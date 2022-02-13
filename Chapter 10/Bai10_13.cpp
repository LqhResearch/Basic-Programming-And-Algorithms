#include <stdio.h>
/*
	Tong cac node co dung mot nut con.
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

	/*Tong cac node co dung mot nut con*/
int sumNode1Con(TREE root) {
	if(root != NULL) {
		int a = sumNode1Con(root->left);
		int b = sumNode1Con(root->right);
		if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
			return root->data + a + b;
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
	
	printf("\nTong cac node co dung mot nut con: %d", sumNode1Con(bin));
	return 0;
}

