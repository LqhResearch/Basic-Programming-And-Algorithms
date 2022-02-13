#include<stdio.h>
/*
	Viet ham tao node va duyet danh sach lien ket don cac toa do diem trong duong tron
*/
typedef struct DuongTron {
	int x;
	int y;
	int banKinh;
} DuongTron;

typedef struct node {
	DuongTron data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Tao node moi*/
node* CreateNode() {
	DuongTron toaDo;
	printf("Nhap toa do diem x va y cua duong tron: ");
	scanf("%d%d", &toaDo.x, &toaDo.y);
	printf("Nhap ban kinh: ");
	scanf("%d", &toaDo.banKinh);
	
	node* p = new node;
	if(p != NULL) {
		p->data = toaDo;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Duyet danh sach lien ket*/
void OutputList(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("Diem(%d, %d). Ban kinh: ", p->data.x, p->data.y, p->data.banKinh);
	}
	else printf("\nDanh sach rong");
}

int main() {

	return 0;
}

