#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac luan van.
	Biet rang thong tin cua mot luan van bao gom:
	-	Ma luan van (10 ky tu).
	-	Ten luan van (100 ky tu).
	-	Ho ten sinh vien thuc hien (30 ky tu).
	-	Ho ten giao vien huong dan (30 ky tu).
	-	Nam thuc hien (kieu nguyen).
	a. Cai dat tat cac thao tac co ban cho sach lien ket don cac quyen sach.
	b. Tim nam co nhieu luan van nhat.
	c. Liet ke cac luan van thuc hien gan nhat.
*/
typedef struct LuanVan {
	char maSo[10];
	char ten[100];
	char sVien[30];		//Ho ten sinh vien thuc hien
	char gVien[30];		//Ho ten giao vien huong dan
	int nam;	
} LuanVan;

typedef struct node {
	LuanVan data;
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

	/*Tao node cac luan van*/
node* CreateNode() {
	LuanVan lv;
	printf("\n-----Nhap Thong Tin Luan van-----\n");
	printf("\t- Ma so luan van: ");
	fflush(stdin);		gets(lv.maSo);
	printf("\t- Ten luan van: ");
	fflush(stdin);		gets(lv.ten);
	printf("\t- Sinh vien thuc hien: ");
	fflush(stdin);		gets(lv.sVien);
	printf("\t- Giao vien huong dan: ");
	fflush(stdin);		gets(lv.gVien);
	printf("\t- Nam xuat ban: ");
	scanf("%d", &lv.nam);
	
	node *p = new node;
	if(p != NULL) {
		p->data = lv;
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
	printf("\nMa luan van\tTen luan van\tSinh vien thuc hien\tGiao vien huong dan\tNam thuc hien");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%s\t%s\t%s\t%d", p->data.maSo, p->data.ten, p->data.sVien, p->data.gVien, p->data.nam);
	}
	else printf("\nDanh sach luan van rong");
}

	/*Tim sach luan van theo ma so luan van*/
bool SearchLV(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.ten, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa luan van theo ma so luan van*/
void DeleteLV(List &l) {
	char name[10];
	printf("\t- Nhap ma so luan van can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchLV(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.ten, name) == 0)
				break;
			else a = p;
		}
		/*Xoa luan van*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay ma so luan van %s", name);
}

	/*Tim nam co nhieu luan van nhat*/
void SearchMaxLV(List l) {
	int maxlv = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext) {
		int count = 0;
		for(node* t=p; t != NULL; t=t->pNext)
			if(p->data.nam == t->data.nam)
				count++;
		if(count > maxlv) maxlv = count;
	}
		
	for(node* p=l.pHead; p != NULL; p=p->pNext) {
		int count = 0;
		for(node* t=p; t != NULL; t=t->pNext)
			if(p->data.nam == t->data.nam)
				count++;
		if(count == maxlv)
			printf("\n%d", p->data.nam);
	}	
}

	/*Liet ke cac luan van thuc hien gan nhat*/
void ListedLV(List l) {
	int year = l.pHead->data.nam;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.nam > year)
			year = p->data.nam;
	
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.nam == year)
			printf("\n%s\t%s\t%s\t%s\t%d", p->data.maSo, p->data.ten, p->data.sVien, p->data.gVien, p->data.nam);
}

	/*Quan ly luan van tot nghiep cho sinh vien*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly Luan van==========");
		printf("\n1. Them luan van");
		printf("\n2. Xuat danh sach luan van");
		printf("\n3. Xoa luan van");
		printf("\n4. Tim nam co nhieu luan van nhat");
		printf("\n5. Liet ke cac luan van thuc hien gan nhat");
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
			DeleteLV(l);
			break;
		}
		case 4:{
			SearchMaxLV(l);
			break;
		}
		case 5:{
			ListedLV(l);
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

