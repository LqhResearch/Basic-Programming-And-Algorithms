#include<stdio.h>
/*
	Viet ham tao node va duyet danh sach lien ket don cac thi sinh
*/
typedef struct ThiSinh {
	char maSo[5];
	char hoTen[30];
	int toan;
	int van;
	int hoa;
	float dtb;
} ThiSinh;

typedef struct node {
	ThiSinh data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Tao node moi*/
node* CreateNode() {
	ThiSinh ts;
	printf("Nhap ma so: ");
	fflush(stdin);		gets(ts.maSo);
	printf("Nhap ho ten: ");
	fflush(stdin);		gets(ts.hoTen);
	printf("Nhap diem toan: ");
	scanf("%d", &ts.toan);
	printf("Nhap diem van: ");
	scanf("%d", &ts.van);
	printf("Nhap diem hoa: ");
	scanf("%d", &ts.hoa);
	ts.dtb=(ts.toan+ts.van+ts.hoa)/3;
	
	node* p = new node;
	if(p != NULL) {
		p->data = ts;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Duyet danh sach lien ket*/
void OutputList(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%s %s %d %d %d %.2f", p->data.maSo, p->data.hoTen, p->data.toan, p->data.van, p->data.hoa, p->data.dtb);
	}
	else printf("\nDanh sach rong");
}

int main() {

	return 0;
}

