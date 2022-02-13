#include<stdio.h>
/*
	Viet ham tao node va duyet danh sach lien ket don cac toa do diem trong mat phang Oxy
*/
typedef struct ToaDoDiem {
	int x;
	int y;
} ToaDoDiem;

typedef struct node {
	ToaDoDiem data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Tao node moi*/
node* CreateNode() {
	ToaDoDiem diem;
	printf("Nhap toa do x va y: ");
	scanf("%d%d", &diem.x, &diem.y);
	
	node* p = new node;
	if(p != NULL) {
		p->data = diem;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Duyet danh sach lien ket*/
void OutputList(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%5d%5d", p->data.x, p->data.y);
	}
	else printf("\nDanh sach rong");
}

int main() {

	return 0;
}

