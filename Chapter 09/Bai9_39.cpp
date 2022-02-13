#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac chuyen bay.
	Biet rang mot chuyen bay gom nhung thanh phan nhu sau:
	-	Ma chuyen bay (5 ky tu).
	-	Ngay bay (kieu ngay).
	-	Gio bay (kieu thoi gian).
	-	Noi di (20 ky tu).
	-	Noi den (20 ky tu).
	a. Nhap, xuat danh sach.
	b. Tim mot ngay co nhieu chuyen bay nhat.
	c. Sap xep chuyen bay theo ma chuyen bay.
*/
typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct Time {
	int hour;
	int minute;
	int second;
} Time;

typedef struct ChuyenBay {
	char maSo[5];
	Date ngay;
	Time tg;
	char noiDi[20];
	char noiDen[20];
} ChuyenBay;

typedef struct node {
	ChuyenBay data;
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
	ChuyenBay cb;
	printf("\n-----Nhap Thong Tin Chuyen bay-----\n");
	printf("\t- Ma chuyen bay: ");
	fflush(stdin);		gets(cb.maSo);
	printf("\t- Ngay khoi hanh (dd/mm/yyyy): ");
	scanf("%d%d%d", &cb.ngay.day, &cb.ngay.month, &cb.ngay.year);
	printf("\t- Gio khoi hanh (hh/mm/ss): ");
	scanf("%d%d%d", &cb.tg.hour, &cb.tg.minute, &cb.tg.second);
	printf("\t- Noi di: ");
	fflush(stdin);		gets(cb.noiDi);
	printf("\t- Noi den: ");
	fflush(stdin);		gets(cb.noiDen);
	
	node *p = new node;
	if(p != NULL) {
		p->data = cb;
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
		printf("\nMa chuyen bay\tNgay khoi hanh\tGio khoi hanh\tNoi di\tNoi den");
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%d/%d/%d\t%d:%d:%d\t%s\t%s", p->data.maSo, p->data.ngay.day, p->data.ngay.month, 
			p->data.ngay.year, p->data.tg.hour, p->data.tg.minute, p->data.tg.second, p->data.noiDi, p->data.noiDen);
	}
	else printf("\nDanh sach chuyen bay rong");
}

	/*Tim chuyen bay theo ma so*/
bool SearchCB(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.maSo, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa chuyen bay theo ma so chuyen bay*/
void DeleteCB(List &l) {
	char name[5];
	printf("\t- Nhap ma so chuyen bay can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchCB(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.maSo, name) == 0)
				break;
			else a = p;
		}
		/*Xoa chuyen bay*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim chuyen bay co ma so %s", name);
}

	/*Hoan vi 2 chyuyen bay*/
void Swap(ChuyenBay &cb1, ChuyenBay &cb2) {
	ChuyenBay temp = cb1;
	cb1 = cb2;
	cb2 = temp;
}

	/*Sap xep chuyen bay theo ma so*/
void SortCB(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(strcmp(p->data.maSo, t->data.maSo) > 0)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Kiem tra ngay nay co ton tai hay khong*/
bool Exist(List l, node* ht) {
	for(node* p=l.pHead; p != ht; p=p->pNext)
		if(p == ht)
			return false;
	return true;
}

	/*Tra ve so thu tu ngay trong nam*/
int DayOfYear(Date dmy) {
	int doy = dmy.day;
	for(int i=1; i<dmy.month; i++) {
		if(i==2) {	//Thang hai
			if(dmy.year%400==0 || (dmy.year%4==0 && dmy.year%100!=0))
				doy+=29;
			else doy+=28;
		}
		if(i==4 || i==6 || i==9 || i==11)
			doy+=30;
		else doy+=31;
	}
	return doy;
}

	/*Tim mot ngay co nhieu chuyen bay nhat*/
void SearchMaxCB(List l) {
	int max = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(Exist(l, p) == true) {
			int count = 0;
			int doyP = DayOfYear(p->data.ngay);
			for(node* t=p; t != NULL; t=t->pNext)
				if(doyP == DayOfYear(t->data.ngay))
					count++;
			if(count > max) max = count;
		}
	
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(Exist(l, p) == true) {
			int count = 0;
			int doyP = DayOfYear(p->data.ngay);
			for(node* t=p; t != NULL; t=t->pNext)
				if(doyP == DayOfYear(t->data.ngay))
					count++;
			if(count == max) printf("\n%d/%d/%d", p->data.ngay.day, p->data.ngay.month, p->data.ngay.year);
		}
}

	/*Quan ly chuyen bay*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly sach Chuyen bay==========");
		printf("\n1. Them chuyen bay");
		printf("\n2. Xuat danh sach chuyen bay");
		printf("\n3. Xoa chuyen bay");
		printf("\n4. Tim mot ngay co nhieu chuyen bay nhat");
		printf("\n5. Sap xep chuyen bay theo ma so");
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
			DeleteCB(l);
			break;
		}
		case 4:{
			SearchMaxCB(l);
			break;
		}
		case 5:{
			SortCB(l);
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

