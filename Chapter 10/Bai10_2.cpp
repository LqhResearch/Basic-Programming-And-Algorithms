#include<stdio.h>
/*
	Khai bao cau truc du lieu cay nhi phan cac phan so.
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

	/*Main function*/
int main() {

	return 0;
}

