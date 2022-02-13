#include <stdio.h>
/*
	Viet ham nhap, xuat cac nut tren cay co gia tri lon hon x va nho hon y.
*/
typedef struct node {	//Node cua cay nhi phan
	int data;
	node *left;
	node *right;
} node;

typedef struct node *TREE;	//Tao cay nhi phan
	TREE root;	//node goc

int x, y; //Khoang x va y

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

	/*Duyet cay theo thu tu truoc cac gia tri khoang [x, y]*/
void NodeLeftRight(TREE root)
{
	if (root != NULL)
	{
		if(root->data >= x && root->data <= y)
			printf("%5d", root->data);
		NodeLeftRight(root->left);
		NodeLeftRight(root->right);
	}
}

	/*Main function*/
int main() {
	TREE bin;
	CreateTree(bin);
	printf("Nhap khoang [x, y]: ");
	scanf("%d%d", &x, &y);
	
	printf("\nDuyet cay cac gia tri [%d, %d]: ", x, y);
	NodeLeftRight(bin);
	return 0;
}

