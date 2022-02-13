#include<stdio.h>
/*
	Viet ham duyet danh sach lien ket don cac phan so
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

	/*Duyet danh sach*/
void ProcessList(List l) {
	node *p;
	p=l.pHead;
	while(p != NULL) {
		printf("\nPhan so: %d / %d", p->data.tuSo, p->data.mauSo);
		p = p->pNext;
	}
}

int main() {

	return 0;
}

