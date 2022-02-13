#include <stdio.h>
#include <math.h>
/*
	Tong cac node co dung hai nut con va la so chinh phuong.
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

	/*Test so chinh phuong*/
bool TestSCP(int n) {
	int temp = sqrt(n);
	return (temp*temp == n) ? true : false;
}

	/*Tong cac node co dung hai nut con va la so chinh phuong*/
int sumNode2Con(TREE root) {
	if(root != NULL) {
		int a = sumNode2Con(root->left);
		int b = sumNode2Con(root->right);
		if(root->left != NULL && root->right != NULL)	//2 nut con
			if(TestSCP(root->data) == true)		//Test so chinh phuong
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
	
	printf("\nTong cac node co dung hai nut con va la so chinh phuong: %d", sumNode2Con(bin));
	return 0;
}

