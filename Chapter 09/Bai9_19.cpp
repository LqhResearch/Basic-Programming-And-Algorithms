#include<stdio.h>
/*
	Viet ham tao node va duyet danh sach lien ket don cac hoc sinh
*/
typedef struct HocSinh {
	char hoTen[30];
	int toan;
	int van;
	float dtb;
} HocSinh;

typedef struct node {
	HocSinh data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Tao node moi*/
node* CreateNode() {
	HocSinh hs;
	printf("Nhap ho ten: ");
	fflush(stdin);		gets(hs.hoTen);
	printf("Nhap diem toan: ");
	scanf("%d", &hs.toan);
	printf("Nhap diem van: ");
	scanf("%d", &hs.van);
	hs.dtb=(hs.toan+hs.van)/2;
	
	node* p = new node;
	if(p != NULL) {
		p->data = hs;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Duyet danh sach lien ket*/
void OutputList(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%s %d %d %.2f", p->data.hoTen, p->data.toan, p->data.van, p->data.dtb);
	}
	else printf("\nDanh sach rong");
}

int main() {

	return 0;
}

