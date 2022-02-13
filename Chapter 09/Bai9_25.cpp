#include<stdio.h>
#include<stdlib.h>
/*
	Kiem tra danh sach cac phan so co toan phan so duong hay khong?
*/
typedef struct PhanSo {
	int tuSo;
	int mauSo;
} PhanSo;

typedef struct node {
	PhanSo data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Khoi tao dslk rong*/
void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

	/*Tao nut*/
node* CreateNode() {
	PhanSo ps;
	printf("Nhap tu so: ");
	scanf("%d", &ps.tuSo);
	printf("Nhap mau so: ");
	scanf("%d", &ps.mauSo);
		
	node* p = new node;
	if(p != NULL) {
		p->data = ps;
		p->pNext = NULL;
		return p;
	}
	else return NULL;
}

	/*Them node vao cuoi dslk*/
void AddTail(List &l) {
	node* new_ele = CreateNode();
	if(l.pHead == NULL) {
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else {
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

	/*Duyet danh sach lien ket*/
void Output(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%d/%d\t", p->data.tuSo, p->data.mauSo);
	}
	else printf("Danh sach rong");
}

	/*Kiem tra danh sach co toan duong?*/
bool TestToanDuong(List l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext) {
			float tmp = 1.0*p->data.tuSo / p->data.mauSo;
			if(tmp < 0)
				return false;
		}
	}
	return true;
}

int main() {
	List l;
	Init(l);
	int choice;
	do{
		printf("\n===============Node===============");
		printf("\n1. Them node phan so");
		printf("\n2. Duyet danh sach");
		printf("\n3. Toan duong khong?");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:{
				AddTail(l);
				break;
			}
			case 2:{
				Output(l);
				break;
			}
			case 3:{
				if(TestToanDuong(l) == true)
					printf("\nDanh sach toan phan so duong");
				else printf("\nDanh sach khong toan phan so duong");
				break;
			}
			case 0: exit(0);
		}
		
	}while(true);
	return 0;
}

