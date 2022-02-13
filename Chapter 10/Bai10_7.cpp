#include <stdio.h>
/*
	Viet ham nhap, xuat cac gia tri hoan thien trong cay.
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

	/*Kiem tra so hoan thien cua node trong cay*/
bool TestSHT(int n) {
	int sum = 0;
	for(int i=1; i<n; i++)
		if(n%i==0)
			sum+=i;
	if(sum == n) return true;
	else return false;
}

	/*Duyet cay theo thu tu truoc cac gia tri hoan thien*/
void NodeLeftRight(TREE root)
{
	if (root != NULL)
	{
		if(TestSHT(root->data)==true)
			printf("%5d", root->data);
		NodeLeftRight(root->left);
		NodeLeftRight(root->right);
	}
}

	/*Main function*/
int main() {
	TREE bin;
	CreateTree(bin);
	
	printf("\nDuyet cay cac gia tri hoan thien: ");
	NodeLeftRight(bin);
	return 0;
}

