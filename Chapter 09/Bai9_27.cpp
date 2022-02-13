#include<stdio.h>
#include<stdlib.h>
/*
	Tim phan so duong dau tien, phan so duong cuoi cung trong danh sach lien ket cac phan so
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

	/*Tim phan so duong dau tien*/
void FirstPSDuong(List l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext) {
			float tmp = 1.0*p->data.tuSo / p->data.mauSo;
			if(tmp > 0) {
				printf("\nPhan so duong dau tien: %d/%d", p->data.tuSo, p->data.mauSo);
				return;
			}
		}
	}
	printf("\nKhong tim thay phan so duong");
}

	/*Tim phan so duong cuoi cung*/
void LastPSDuong(List l) {
	PhanSo ps;
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(1.0*p->data.tuSo / p->data.mauSo > 0)
				ps = p->data;
	}
	printf("\nPhan so duong cuoi cung: %d/%d", ps.tuSo, ps.mauSo);
}

int main() {
	List l;
	Init(l);
	int choice;
	do{
		printf("\n===============Node===============");
		printf("\n1. Them node phan so");
		printf("\n2. Duyet danh sach");
		printf("\n3. Phan so duong dau tien");
		printf("\n4. Phan so duong cuoi cung");
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
				FirstPSDuong(l);
				break;
			}
			case 4:{
				LastPSDuong(l);
				break;
			}
			case 0: exit(0);
		}
		
	}while(true);
	return 0;
}

