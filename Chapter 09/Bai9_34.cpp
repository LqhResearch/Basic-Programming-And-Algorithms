#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac quyen sach.
	Biet rang thong tin cua mot quyen sach bao gom:
	-	Ten sach (50 ky tu)
	-	Ten tac gia (30 ky tu)
	-	Nam xuat ban (kieu nguyen)
	a. Cai dat tat cac thao tac co ban cho sach lien ket don cac quyen sach.
	b. Tim quyen sach cu nhat trong danh sach lien ket.
	c. Tim mot nam co nhieu sach xuat ban nhat va liet ke tat ca cac quyen sach xuat ban trong nam do.
	d. Sap xep sach theo thu tu tang dan cua nam xuat ban.
*/
typedef struct Book {
	char ten[50];
	char tacGia[30];
	int namxb;	//Nam xuat ban sach
} Book;

typedef struct node {
	Book data;
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
	Book b;
	printf("\n-----Nhap Thong Tin Sach-----\n");
	printf("\t- Ten sach: ");
	fflush(stdin);		gets(b.ten);
	printf("\t- Ten tac gia: ");
	fflush(stdin);		gets(b.tacGia);
	printf("\t- Nam xuat ban: ");
	scanf("%d", &b.namxb);
	
	node *p = new node;
	if(p != NULL) {
		p->data = b;
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
	printf("\nTen sach\tTac gia\tNam xb");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%s\t%d", p->data.ten, p->data.tacGia, p->data.namxb);
	}
	else printf("\nDanh sach sach cua thu vien rong");
}

	/*Tim sach theo ten sach*/
bool SearchB(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.ten, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa sach theo ten sach*/
void DeleteB(List &l) {
	char name[30];
	printf("\t- Nhap ten sach can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchB(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.ten, name) == 0)
				break;
			else a = p;
		}
		/*Xoa phong*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay sach ten %s", name);
}

	/*Tim quyen sach cu nhat trong danh sach lien ket*/
void SearchOldBook(List l) {
	int year = l.pHead->data.namxb;
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)	//Tim nam cu nhat
		if(p->data.namxb < year)
			year = p->data.namxb;
	
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.namxb == year)
			printf("\n%s\t%s\t%d", p->data.ten, p->data.tacGia, p->data.namxb);
}

	/*Tim mot nam co nhieu sach xuat ban nhat*/
int SearchYear(List l) {
	int year, maxB = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext) {
		int book = 0;
		for(node* t=l.pHead; t != NULL; t=t->pNext)
			if(t->data.namxb == p->data.namxb)
				book++;
		if(book > maxB) {
			maxB = book;
			year = p->data.namxb;
		}
	}
	return year;
}

	/*Liet ke tat ca cac quyen sach xuat ban trong nam do*/
void ListedMaxBook(List l) {
	int year = SearchYear(l);
	printf("\nNam co nhieu sach nhat la %d: ", year);
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.namxb == year)
			printf("\n%s\t%s\t%d", p->data.ten, p->data.tacGia, p->data.namxb);
}

	/*Hoan vi 2 sach*/
void Swap(Book &b1, Book &b2) {
	Book temp = b1;
	b1 = b2;
	b2 = temp;
}

	/*Sap xep sach tang dan theo nam xuat ban*/
void SortBookNXB(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(p->data.namxb > t->data.namxb)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Quan ly sach cua thu vien*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly sach Thu vien==========");
		printf("\n1. Them sach");
		printf("\n2. Xuat danh sach sach");
		printf("\n3. Xoa sach");
		printf("\n4. Tim quyen sach cu nhat trong danh sach lien ket");
		printf("\n5. Tim mot nam co nhieu sach xuat ban nhat va liet ke tat ca cac quyen sach xuat ban trong nam do");
		printf("\n6. Sap xep sach tang dan theo nam xuat ban"); 
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
			DeleteB(l);
			break;
		}
		case 4:{
			SearchOldBook(l);
			break;
		}
		case 5:{
			ListedMaxBook(l);
			break;
		}
		case 6:{
			SortBookNXB(l);
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

