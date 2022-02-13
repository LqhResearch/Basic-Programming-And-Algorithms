#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac cau thu.
	Biet rang thong tin cua mot qau thu bao gom:
	-	Ma cau thu (10 ky tu).
	-	Ten cau thu (30 ky tu).
	-	Ngay sinh (kieu ngay).
	a. Cai dat tat cac thao tac co ban cho sach lien ket don cac quyen sach.
	b. Liet ke danh sach cac cau thu nho tuoi nhat trong danh sach.
	c. Sap xep cau thu theo thu tu giam dan theo nam sinh.
*/
typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct CauThu {
	char maSo[10];
	char ten[30];
	Date ngSinh;
} CauThu;

typedef struct node {
	CauThu data;
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

	/*Tao node cac sach cua cau thu*/
node* CreateNode() {
	CauThu ct;
	printf("\n-----Nhap Thong Tin Cau Thu-----\n");
	printf("\t- Ma cau thu: ");
	fflush(stdin);		gets(ct.maSo);
	printf("\t- Ten cau thu: ");
	fflush(stdin);		gets(ct.ten);
	printf("\t- Ngay sinh (dd/mm/yyyy): ");
	scanf("%d%d%d", &ct.ngSinh.day, &ct.ngSinh.month, &ct.ngSinh.year);
	
	node *p = new node;
	if(p != NULL) {
		p->data = ct;
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
	printf("\nMa cau thu\tTen cau thu\tNgay sinh");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%s\t%d/%d/%d", p->data.maSo, p->data.ten, p->data.ngSinh.day, 
			p->data.ngSinh.month, p->data.ngSinh.year);
	}
	else printf("\nDanh sach cau thu rong");
}

	/*Tim cau thu theo ma so*/
bool SearchCT(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.ten, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa cau thu theo ma so*/
void DeleteCT(List &l) {
	char name[10];
	printf("\t- Nhap ma so cau thu can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchCT(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.maSo, name) == 0)
				break;
			else a = p;
		}
		/*Xoa cau thu*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim cau thu ma so %s", name);
}

	/*Liet ke danh sach cac cau thu nho tuoi nhat trong danh sach*/
void ListedMinAges(List l) {
	int max = l.pHead->data.ngSinh.year;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.ngSinh.year > max)
			max = p->data.ngSinh.year;
	
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.ngSinh.year == max)
			printf("\n%s\t%s\t%d/%d/%d", p->data.maSo, p->data.ten, p->data.ngSinh.day, 
			p->data.ngSinh.month, p->data.ngSinh.year);
}

	/*Hoan vi 2 cau thu*/
void Swap(CauThu &ct1, CauThu &ct2) {
	CauThu temp = ct1;
	ct1 = ct2;
	ct2 = temp;
}

	/*Sap xep cau thu theo thu tu giam dan theo nam sinh*/
void SortNamSinh(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(p->data.ngSinh.year < t->data.ngSinh.year)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Quan ly sach cua cau thu*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly sach Cau thu==========");
		printf("\n1. Them cau thu");
		printf("\n2. Xuat danh sach cau thu");
		printf("\n3. Xoa cau thu");
		printf("\n4. Liet ke danh sach cac cau thu nho tuoi nhat trong danh sach");
		printf("\n5. Sap xep cau thu theo thu tu giam dan theo nam sinh");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>5)
			printf("\nChuc nang nay khong ton tai");
	}while(choice<0 || choice>5);
	
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
			DeleteCT(l);
			break;
		}
		case 4:{
			ListedMinAges(l);
			break;
		}
		case 5:{
			SortNamSinh(l);
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

