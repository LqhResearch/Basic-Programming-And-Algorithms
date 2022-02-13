#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac tinh.
	Biet rang thong tin cua mot tinh bao gom:
	-	Ten tinh (30 ky tu)
	-	Dien tich (kieu thuc)
	-	Dan so (kieu nguyen)
	a. Cai dat tat cac thao tac co ban cho sach lien ket don cac quyen sach.
	b. Tinh tong dien tich tat ca tinh trong danh sach lien ket don.
	c. Tim dia chi node chua tinh co dien tich lon nhat.
	d. Tim tinh co dan so dong nhat.
	d. Sap xep sach theo thu tu tang dan cua dien tich.

*/
typedef struct Tinh {
	char ten[30];
	float dtich;
	int danSo;
} Tinh;

typedef struct node {
	Tinh data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Khoi tao danh sach lien ket don rong*/
void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

	/*Tao node cac tinh*/
node* CreateNode() {
	Tinh t;
	printf("\n-----Nhap Thong Tin Tinh-----\n");
	printf("\t- Ten tinh: ");
	fflush(stdin);		gets(t.ten);
	printf("\t- Dien tich: ");
	scanf("%f", &t.dtich);
	printf("\t- Dan so: ");
	scanf("%d", &t.danSo);
	
	node *p = new node;
	if(p != NULL) {
		p->data = t;
		p->pNext = NULL;
		return p;
	}
	else return NULL;
}

	/*Add node o cuoi*/
void AddAfter(List &l) {
	node *new_ele = CreateNode();
	if(l.pHead == NULL) {
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else {
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

	/*Duyet danh sach*/
void XuatDS(List l) {
	printf("\n-----Xuat danh sach-----");
	printf("\nTen tinh\tDien tich\tDan so");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%.2f\t%d", p->data.ten, p->data.dtich, p->data.danSo);
	}
	else printf("\nDanh sach tinh rong");
}

	/*Tim tinh theo ten tinh*/
bool SearchP(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.ten, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa tinh theo ten tinh*/
void DeleteT(List &l) {
	char name[30];
	printf("\t- Nhap ten tinh can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchP(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.ten, name) == 0)
				break;
			else a = p;
		}
		/*Xoa tinh*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay tinh ten %s", name);
}

	/*Tong dien tich tat ca tinh*/
void sumDTTinh(List l) {
	float sum = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		sum+=p->data.dtich;
	printf("\nTong dien tich: %.2f", sum);
}

	/*Tim dia chi node chua tinh co dien tich lon nhat*/
void SearchNodeDT(List l) {
	float max = l.pHead->data.dtich;
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)
		if(p->data.dtich > max)
			max = p->data.dtich;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.dtich == max)
			printf("\nDia chi la %x", p->data);
}

	/*Tim tinh co dan so dong nhat*/
void SearchDongDan(List l) {
	int maxDS = l.pHead->data.danSo;
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)
		if(p->data.danSo > maxDS)
			maxDS = p->data.danSo;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.danSo == maxDS)
			printf("\nTinh %s", p->data.ten);
}

	/*Hoan vi 2 tinh*/
void Swap(Tinh &t1, Tinh &t2) {
	Tinh temp = t1;
	t1 = t2;
	t2 = temp;
}

	/*Sap xep sach theo thu tu tang dan cua dien tich*/
void SortTinh(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(p->data.dtich > t->data.dtich)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Quan ly tinh*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly Tinh==========");
		printf("\n1. Them tinh");
		printf("\n2. Xuat danh sach tinh");
		printf("\n3. Xoa tinh");
		printf("\n4. Tong dien tich tat ca tinh");
		printf("\n5. Tim dia chi node chua tinh co dien tich lon nhat");
		printf("\n6. Tim tinh co dan so dong nhat");
		printf("\n7. Sap xep sach theo thu tu tang dan cua dien tich");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>7)
			printf("\nChuc nang nay khong ton tai");
	}while(choice<0 || choice>7);
	
	switch(choice) {
		case 1:{
			AddAfter(l);
			break;
		}
		case 2:{
			XuatDS(l);
			break;
		}
		case 3:{
			DeleteT(l);
			break;
		}
		case 4:{
			sumDTTinh(l);
			break;
		}
		case 5:{
			SearchNodeDT(l);
			break;
		}
		case 6:{
			SearchDongDan(l);
			break;
		}
		case 7:{
			SortTinh(l);
			break;
		}
		case 0: exit(0);
	}
}

	/*Main function*/
int main() {
	List l;
	Init(l);
	do{
		menu(l);
	}while(true);
	return 0;
}
