#include<stdio.h>
/*
	Khai bao cau truc du lieu cho danh sach lien ket don cac toa do diem trong mat phang Oxy
*/
typedef struct ToaDoDiem {
	int x;
	int y;
} ToaDoDiem;

typedef struct node {
	ToaDoDiem data;
	node *pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Main function*/
int main() {

	return 0;
}

