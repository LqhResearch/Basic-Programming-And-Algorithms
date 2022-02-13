#include <stdio.h>
/*
	Viet ham nhap, xuat cac phan so:
	-	Phan so duong tren tang thu k cua cay.
*/
typedef struct PhanSo {
	int tuSo;
	int mauSo;
} PhanSo;

typedef struct node {	//Node cua cay nhi phan
	PhanSo data;
	node *left;
	node *right;
} node;

typedef struct node *TREE;	//Tao cay nhi phan
	TREE root;	//node goc

	/*Dinh danh lai phan so*/
void FormatPS(PhanSo &ps) {
	if(ps.mauSo < 0) {
		ps.tuSo = -ps.tuSo;
		ps.mauSo = -ps.mauSo;
	}
}

	/*Tao cay nhi phan cac phan so*/
void CreateTree(TREE &root) {
	PhanSo ps;
	printf("\n\t-Tu so: ");
	scanf("%d", &ps.tuSo);
	
	if(ps.tuSo != -1) {
		printf("\t-Mau so: ");
		scanf("%d", &ps.mauSo);
		FormatPS(ps);
		
		root = new node;
		root->data = ps;
		printf("\nCay con trai cua %d / %d: ", ps.tuSo, ps.mauSo);
		CreateTree(root->left);
		printf("\nCay con phai cua %d / %d: ", ps.tuSo, ps.mauSo);
		CreateTree(root->right);
	}
	else root = NULL;
}

	/*Duyet cay theo thu tu truoc cac phan so*/
void NodeLeftRight(TREE root)
{
	if (root != NULL)
	{
		printf("\t%d / %d", root->data.tuSo, root->data.mauSo);
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

	/*Output tang k cac phan so duong*/
void OutTangK(TREE root, int k) {
	if(root != NULL) {
		k--;
		if(root->left != NULL)
			OutTangK(root->left, k);
		if(k == 0 && root->data.tuSo > 0)
			printf("%5d / %d", root->data.tuSo, root->data.mauSo);
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
	printf("Tang %d cac phan so duong: ", k);
	OutTangK(bin, k+1);
	return 0;
}

