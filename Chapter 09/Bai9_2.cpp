#include<stdio.h>
/*
	Hay khai bao cau truc du lieu cho danh sach lien ket don phan so
*/
typedef struct PhanSo {
	int tuSo;
	int mauSo;
} PhanSo;

typedef struct node {
	PhanSo data;
	node *pNext;
} node;

typedef struct List {
	node *pHead;
	node *pTail;
} List;

	/*Main function*/
int main() {
	
	return 0;
}

