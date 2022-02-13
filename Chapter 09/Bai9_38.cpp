#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac nhan vien:
	Biet rang mot nhan vien gom nhung thanh phan nhu sau:
	-	Ma nhan vien (5 ky tu).
	-	Ten nhan vien (30 ký tu).
	-	Luong nhan vien (kieu thuc).
	a. Nhap, xuat danh sach.
	b. Tim nhan vien co luong cao nhat trong danh sach.
	c. Tinh tong luong cua cac nhan vien.
	d. Sap xep danh sach tang dan theo luong nhan vien.
*/
typedef struct NhanVien {
	char maSo[5];
	char ten[30];
	float luong;
} NhanVien;

typedef struct node {
	NhanVien data;
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

	/*Tao node cac sach cua thu vien*/
node* CreateNode() {
	NhanVien nv;
	printf("\n-----Nhap Thong Tin Nhan vien-----\n");
	printf("\t- Ma so: ");
	fflush(stdin);		gets(nv.maSo);
	printf("\t- Ten: ");
	fflush(stdin);		gets(nv.ten);
	printf("\t- Luong: ");
	scanf("%f", &nv.luong);
	
	node *p = new node;
	if(p != NULL) {
		p->data = nv;
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
	if(l.pHead != NULL) {
		printf("\n-----Xuat danh sach-----");
		printf("\nTen sach\tTac gia\tNam xb");
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%s\t%.2f", p->data.maSo, p->data.ten, p->data.luong);
	}
	else printf("\nDanh sach nhan vien rong");
}

	/*Tim nhan vien theo ma so*/
bool SearchNV(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.maSo, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa sach theo ten sach*/
void DeleteNV(List &l) {
	char name[5];
	printf("\t- Nhap ma so nhan vien can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchNV(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.maSo, name) == 0)
				break;
			else a = p;
		}
		/*Xoa nhan vien*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim nhan vien co ma so %s", name);
}


	/*Hoan vi 2 nhan vien*/
void Swap(NhanVien &nv1, NhanVien &nv2) {
	NhanVien temp = nv1;
	nv1 = nv2;
	nv2 = temp;
}

	/*Sap xep danh sach tang dan theo luong nhan vien*/
void SortNV(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(p->data.luong > t->data.luong)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Tim nhan vien co luong cao nhat trong danh sach*/
void MaxLuongNV(List l) {
	float max = l.pHead->data.luong;
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)
		if(p->data.luong > max)
			max = p->data.luong;
			
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)
		if(p->data.luong == max)
			printf("\n%s\t%s\t%.2f", p->data.maSo, p->data.ten, p->data.luong);
}

	/*Tinh tong luong cua cac nhan vien*/
void SumLuongNV(List l) {
	float sum = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		sum+=p->data.luong;
	printf("\nTong luong cua tat ca nhan vien = %.2f", sum);
}

	/*Quan ly sach cua thu vien*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly sach Nhan vien==========");
		printf("\n1. Them nhan vien");
		printf("\n2. Xuat danh sach nhan vien");
		printf("\n3. Xoa nhan vien");
		printf("\n4. Tim nhan vien co luong cao nhat trong danh sach");
		printf("\n5. Tinh tong luong cua cac nhan vien");
		printf("\n6. Sap xep danh sach tang dan theo luong nhan vien"); 
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>6)
			printf("\nChuc nang nay khong ton tai");
	}while(choice<0 || choice>6);
	
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
			DeleteNV(l);
			break;
		}
		case 4:{
			MaxLuongNV(l);
			break;
		}
		case 5:{
			SumLuongNV(l);
			break;
		}
		case 6:{
			SortNV(l);
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

