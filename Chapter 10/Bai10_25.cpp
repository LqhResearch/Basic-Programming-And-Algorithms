#include <stdio.h>
/*
	Dem so luong nut trong tang cao hon tang k.
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

	/*Max cua 2 gia tri*/
int max(int a, int b)
{
	return a > b ? a : b;
}

	//Tinh chieu cao cua cau = Muc lon nhat + 1
int HighTree(TREE root)
{
	if(root == NULL)
		return 0;
	else
		return max(HighTree(root->left), HighTree(root->right)) + 1;
}

	/*Dem so luong nut trong tang thap hon tang k*/
int CountTangK(TREE root, int k) {
	if(root != NULL) {
		k--;
		int a = CountTangK(root->left, k);
		int b = CountTangK(root->right, k);
		if(k==0)
			return 1 + a + b;
		return a + b;
	}
	return 0;
}

int Count(TREE root, int k) {
	if(root != NULL) {
		int countNum = 0;
		for(int i=k; i<HighTree(root); i++)
			countNum+=CountTangK(root, i);
		return countNum;
	}
	return 0;
}

	/*Main function*/
int main() {
	TREE bin;
	CreateTree(bin);
	
	printf("\nDuyet cay: ");
	NodeLeftRight(bin);
	
	int k;
	printf("\nNhap tang can dem: ");
	scanf("%d", &k);
	printf("\nDem so luong nut cao hon tang %d: %d", k, Count(bin, k));
	return 0;
}

