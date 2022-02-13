#include<stdio.h>
/*
	Viet ham tao node va duyet danh sach lien ket don cac phong trong khach san
*/
typedef struct Phong {
	char maSo[5];
	char tenPhong[30];
	int giaThue;
	int soGiuong;
	bool tinhTrangPhong;
} Phong;

typedef struct node {
	Phong data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Tao node moi*/
node* CreateNode() {
	Phong ph;
	printf("Nhap ma so phong: ");
	fflush(stdin);		gets(ph.maSo);
	printf("Nhap ten phong: ");
	fflush(stdin);		gets(ph.tenPhong);
	printf("Nhap gia phong: ");
	scanf("%d", &ph.giaThue);
	printf("Nhap so cai giuong: ");
	scanf("%d", &ph.soGiuong);
	printf("Phong da duoc thue chua? (0. ranh 1. ban): ");
	scanf("%d", &ph.tinhTrangPhong);
	
	node* p = new node;
	if(p != NULL) {
		p->data = ph;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Duyet danh sach lien ket*/
void OutputList(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%s %s %d %d %d", p->data.maSo, p->data.tenPhong, p->data.giaThue, p->data.soGiuong, p->data.tinhTrangPhong);
	}
	else printf("\nDanh sach rong");
}

int main() {

	return 0;
}

