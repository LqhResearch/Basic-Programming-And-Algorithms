#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac phong trong khach san.
	Biet rang thong tin cua mot hop sua bao gom:
	-	Ma phong (5 ky tu).
	-	Ten phong (30 ky tu).
	-	Don gia thue (kieu so thuc).
	-	So luong giuong (kieu nguyen).
	-	Tinh trang phong: 0 ranh, 1 ban.
	a)	Cai dat tat ca cac thao tac co ban cho danh sach lien ket cac phong.
	b)	Liet ke cac phong rong trong danh sach.
	c)	Tinh tong so luong giuong trong danh sach.
	d)	Sap xep danh sach lien ket tang dan theo don gia thue.
*/

typedef struct Phong {
	char maSo[5];
	char tenP[30];
	float cost;
	int sLGiuong;
	int tinhTrangP;
} Phong;

typedef struct node {
	Phong data;
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

	/*Tao node cac phong cua khach san*/
node* CreateNode() {
	Phong ph;
	printf("\n-----Nhap Thong Tin Phong-----\n");
	printf("\t- Ma so: ");
	fflush(stdin);		gets(ph.maSo);
	printf("\t- Ten phong: ");
	fflush(stdin);		gets(ph.tenP);
	printf("\t- Gia tien: ");
	scanf("%f", &ph.cost);
	printf("\t- So luong giuong: ");
	scanf("%d", &ph.sLGiuong);
	printf("\t- Tinh trang phong (0. ranh, 1. ban): ");
	scanf("%d", &ph.tinhTrangP);
	
	node *p = new node;
	if(p != NULL) {
		p->data = ph;
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
	printf("\nMa so\tTen phong\tGia phong\tSo luong giuong\tTinh trang phong");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%s\t%.2f\t%d\t%d", p->data.maSo, p->data.tenP, p->data.cost, p->data.sLGiuong, p->data.tinhTrangP);
	}
	else printf("\nDanh sach phong cua khach san rong");
}

	/*Tim phong theo ma so phong*/
bool SearchP(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.maSo, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa phong theo ma so phong*/
void DeleteP(List &l) {
	char name[30];
	printf("\t- Nhap ma so phong can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchP(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.maSo, name) == 0)
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
	else printf("\nKhong tim thay ma so phong %s", name);
}

	/*Liet ke cac phong rong trong danh sach*/
void ListedPNull(List l) {
	int count = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.tinhTrangP == 0) {
			printf("\n%s\t%s\t%.2f\t%d\t%d", p->data.maSo, p->data.tenP, p->data.cost, p->data.sLGiuong, p->data.tinhTrangP);
			count++;
		}
	if(count == 0) printf("\nKhong tim thay phong rong");
}

	/*Tinh tong so luong giuong trong danh sach*/
void sumSoGiuong(List l) {
	int sum = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		sum+=p->data.sLGiuong;
	printf("\n%d giuong trong khach san", sum);
}

	/*Hoan vi 2 hop sua*/
void Swap(Phong &ph1, Phong &ph2) {
	Phong temp = ph1;
	ph1 = ph2;
	ph2 = temp;
}

	/*Sap xep danh sach lien ket tang dan theo don gia thue*/
void SortCost(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(p->data.cost > t->data.cost)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Quan ly list phong cua khach san*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly Phong Khach san==========");
		printf("\n1. Them phong");
		printf("\n2. Xuat danh sach phong");
		printf("\n3. Xoa phong");
		printf("\n4. Liet ke cac phong rong trong danh sach");
		printf("\n5. Tinh tong so luong giuong trong danh sach");
		printf("\n6. Sap xep danh sach lien ket tang dan theo don gia thue");
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
			DeleteP(l);
			break;
		}
		case 4:{
			ListedPNull(l);
			break;
		}
		case 5:{
			sumSoGiuong(l);
			break;
		}
		case 6:{
			SortCost(l);
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

