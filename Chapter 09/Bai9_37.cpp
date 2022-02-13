#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac mat hang.
	Biet rang thong tin cua mot mat hang bao gom:
	-	Ten mat hang (20 ky tu)
	-	Don gia (kieu nguyen)
	-	So luong ton (kieu nguyen)
	a. Nhap, xuat danh sach
	b. Tim mat hang co tong gia tri ton lon nhat
	c. Dem so luong mat hang co so luong ton lon hon 1000
*/
typedef struct MatHang {
	char ten[50];
	int gia;
	int sLTon;
} MatHang;

typedef struct node {
	MatHang data;
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

	/*Tao node cac mat hang*/
node* CreateNode() {
	MatHang mh;
	printf("\n-----Nhap Thong Tin Mat hang-----\n");
	printf("\t- Ten mat hang: ");
	fflush(stdin);		gets(mh.ten);
	printf("\t- Gia tien: ");
	scanf("%d", &mh.gia);
	printf("\t- So luong ton: ");
	scanf("%d", &mh.sLTon);
	
	node *p = new node;
	if(p != NULL) {
		p->data = mh;
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
	printf("\nTen mat hang\tDon gia\tSo luong ton");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%d\t%d", p->data.ten, p->data.gia, p->data.sLTon);
	}
	else printf("\nDanh sach mat hang rong");
}

	/*Tim sach theo ten mat hang*/
bool SearchP(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.ten, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa sach theo ten mat hang*/
void DeleteMH(List &l) {
	char name[20];
	printf("\t- Nhap ten mat hang can xoa: ");
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
		/*Xoa mat hang*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay mat hang ten %s", name);
}

	/*Tim mat hang co tong gia tri ton lon nhat*/
void SearchMH(List l) {
	node* flag = l.pHead;
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)
		if((p->data.gia*p->data.sLTon) > (flag->data.gia*flag->data.sLTon))
			flag = p;
	
	//Liet ke danh sach
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)
		if(p->data.gia*p->data.sLTon == flag->data.gia*flag->data.sLTon)
			printf("\n%s\t%d\t%d", p->data.ten, p->data.gia, p->data.sLTon);
}

	/*Dem so luong mat hang co so luong to lon hon 1000*/
void CountMH(List l) {
	int count=0;
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext)
		if(p->data.sLTon > 1000)
			count++;
	printf("\n%d san pham co so luong ton lon hon 1000", count);
}

	/*Quan ly mat hang*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly sach Mat hang==========");
		printf("\n1. Them mat hang");
		printf("\n2. Xuat danh sach mat hang");
		printf("\n3. Xoa mat hang");
		printf("\n4. Tim mat hang co tong gia tri ton lon nhat");
		printf("\n5. Dem so luong mat hang co so luong ton lon hon 1000");
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
			DeleteMH(l);
			break;
		}
		case 4:{
			SearchMH(l);
			break;
		}
		case 5:{
			CountMH(l);
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

