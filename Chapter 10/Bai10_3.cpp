#include<stdio.h>
/*
	Khai bao cau truc du lieu cay nhi phan cac toa do diem trong mat phang Oxy.
*/
typedef struct ToaDo {
	int x;
	int y;
} ToaDo;

typedef struct node {	//Node cua cay nhi phan
	ToaDo data;
	node *left;
	node *right;
} node;

typedef struct node *TREE;	//Tao cay nhi phan
	TREE root;	//node goc

	/*Main function*/
int main() {

	return 0;
}

