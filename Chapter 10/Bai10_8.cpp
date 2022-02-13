#include <stdio.h>
/*
	Viet ham nhap, xuat tat ca cac nut tang k cua cay.
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

	/*Tim max*/
int max(int a, int b)
{
	return a > b ? a : b;
}

	/*Tinh chieu cao cua cau = Muc lon nhat + 1*/
int HighTree(TREE root)
{
	if(root == NULL)
		return 0;
	else
		return max(HighTree(root->left), HighTree(root->right)) + 1;
}

	/*Output tang k*/
void OutTangK(TREE root, int k) {
	if(root != NULL) {
		k--;
		if(root->left != NULL)
			OutTangK(root->left, k);
		if(k == 0)
			printf("%5d", root->data);
		if(root->right != NULL)
			OutTangK(root->right, k);	
	}
}

	/*Main function*/
int main() {
	TREE bin;
	CreateTree(bin);
	
	printf("\nDuyet cay theo thu tu truoc: ");
	NodeLeftRight(bin);
	
	int k;
	printf("\nNhap tang can xuat: ");
	scanf("%d", &k);
	printf("Tang %d: ", k);
	OutTangK(bin, k+1);
	return 0;
}

