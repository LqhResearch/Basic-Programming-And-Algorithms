#include<stdio.h>
/*
	Viet ham tao node danh sach lien ket don cac phan so
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

	//Tao node phan so
node* CreateNode() {
	node *p;
	PhanSo ps;
	p = new(node);
	if(p != NULL) {
		printf("\nNhap tu so: ");
		scanf("%d", &ps.tuSo);
		printf("\nNhap mau so: ");
		scanf("%d", &ps.mauSo);
		p->data = ps;
		p->pNext = NULL;
		return p;
	}
	return NULL;
}

	/*Main function*/
int main() {
	
	return 0;
}

