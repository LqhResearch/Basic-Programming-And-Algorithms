#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac nhan vien.
	Biet rang thong tin cua nhan vien bao gom:
	-	Ho ten (30 ky tu)
	-	Ngay sinh (kieu ngay)
	-	Luong (so thuc)
	-	Gioi tinh (0. Nu, 1. Nam)
	a. Cai dat tat ca cac thao tac co ban cho danh sach lien ket nhan vien.
	b. Liet ke cac nhan vien tren 40 tuoi trong danh sach.
	c. Dem so luong nhan vien co luong lon hon 1.000.000 dong trong danh sach.
	d. Viet ham sap xep cac nhan vien giam dan theo nam sinh (khong quan tam ngay va thang sinh).
*/
typedef struct Ngay {
	int day;
	int month;
	int year;
} Ngay;

typedef struct NhanVien {
	char hoTen[30];
	Ngay birth;
	float luong; 	//Don vi la (trieu dong)
	int gioiTinh;
} NhanVien;

typedef struct node {
	NhanVien data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Khoi tao danh sach rong*/
void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

	/*Tao nut*/
node* CreateNode() {
	NhanVien nv;
	printf("\n-----Nhap thong tin nhan vien-----\n");
	printf("	- Ho ten: ");
	fflush(stdin);		gets(nv.hoTen);
	printf("	- Ngay thang nam sinh: ");
	scanf("%d %d %d", &nv.birth.day, &nv.birth.month, &nv.birth.year);
	printf("	- Tien luong (trieu dong): ");
	scanf("%f", &nv.luong);
	printf("	- Gioi tinh (0. Nu, 1. Nam): ");
	scanf("%d", &nv.gioiTinh);
	
	node* p = new node;
	if(p != NULL) {
		p->data = nv;
		p->pNext = NULL;
		return p;
	}
	else return NULL;
}

	/*Them node vao cuoi danh sach*/
void AddLastNode(List &l) {
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

	/*Them node vao dau danh sach*/
void AddFirstNode(List &l) {
	node* new_ele = CreateNode();
	if(l.pHead == NULL) {
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else {
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

	/*Duyet danh sach lien ket*/
void Output(List l) {
	printf("\nTat ca cac nhan vien: \n");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(p->data.gioiTinh == 0)
				printf("%s   %d/%d/%d   %.2f   Nu\n", p->data.hoTen, p->data.birth.day, p->data.birth.month, p->data.birth.year, p->data.luong);
			else printf("%s   %d/%d/%d   %.2f   Nam\n", p->data.hoTen, p->data.birth.day, p->data.birth.month, p->data.birth.year, p->data.luong);
	}
	else printf("Danh sach rong");
}

	/*Tim nhan vien theo ten*/
bool SearchNV(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.hoTen, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa nhan vien theo ten*/
void DeleteNV(List &l) {
	char name[30];
	printf("\t- Nhap ho ten can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchNV(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.hoTen, name) == 0)
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
	else printf("\nKhong tim thay nhan vien %s", name);
}

	/*Chuc nang danh sach lien ket*/
void menu() {
	List l;
	Init(l);
	int choice;
	do{
		do{
			printf("\n===============Nhan vien===============");
			printf("\n1. Them nhan vien vao dau");
			printf("\n2. Them nhan vien vao cuoi");
			printf("\n3. Duyet nhan vien");
			printf("\n4. Xoa nhan vien theo ten");
			printf("\n0. Thoat");
			printf("\n >> Hay lua chon: ");
			scanf("%d", &choice);
			if(choice<0 || choice>5)
				printf("\nChuc nang nay khong ton tai");
		}while(choice<0 || choice>5);
		
		switch(choice) {
			case 1: {
				AddFirstNode(l);
				break;
			}
			case 2: {
				AddLastNode(l);
				break;
			}
			case 3: {
				Output(l);
				break;
			}
			case 4: {
				DeleteNV(l);
				break;
			}
			case 0: exit(0);
		}
	}while(true);
}

int main() {
	do{
		menu();
	}while(true);
	return 0;
}

