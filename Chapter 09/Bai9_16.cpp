#include<stdio.h>
/*
	Viet ham tao node va duyet danh sach lien ket don cac so phuc
*/
typedef struct SoPhuc {
	float thuc;
	float ao;
} SoPhuc;

typedef struct node {
	SoPhuc data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Tao node moi*/
node* CreateNode() {
	SoPhuc sp;
	printf("Nhap so phuc: ");
	scanf("%f%f", &sp.thuc, &sp.ao);
	
	node* p = new node;
	if(p != NULL) {
		p->data = sp;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Duyet danh sach lien ket*/
void OutputList(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%.2f%.2f", p->data.thuc, p->data.ao);
	}
	else printf("\nDanh sach rong");
}

int main() {

	return 0;
}

