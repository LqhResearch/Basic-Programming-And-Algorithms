#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac hop sua.
	Biet rang thong tin cua mot hop sua bao gom:
	-	Nhan hieu (20 ky tu).
	-	Trong luong (so thuc).
	-	Han su dung (kieu nga).
	a)	Cai dat tat ca cac thao tac co ban cho danh sach lien ket cac hop sua.
	b)	Dem so luong hop sua san xuat truoc nam 2020 trong danh sach.
	c)	Tim hop sua moi nhat trong danh sach.
	d)	Sap xep cac hop sua theo thu tu tang dan theo han su dung.
*/
typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct HopSua {
	char hieu[20];
	float kLuong;
	Date hsd;
} HopSua;

typedef struct node {
	HopSua data;
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

	/*Tao node hop sua*/
node* CreateNode() {
	HopSua hs;
	printf("\n-----Nhap Thong Tin Hop Sua-----\n");
	printf("\t- Nhan hieu: ");
	fflush(stdin);		gets(hs.hieu);
	printf("\t- Trong luong: ");
	scanf("%f", &hs.kLuong);
	printf("\t- Nhap ngay/thang/nam: ");
	scanf("%d%d%d", &hs.hsd.day, &hs.hsd.month, &hs.hsd.year);
	
	node *p = new node;
	if(p != NULL) {
		p->data = hs;
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
	printf("\nNhan hieu\tKhoi luong\tHan su dung");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%f\t%d/%d/%d", p->data.hieu, p->data.kLuong, p->data.hsd.day, p->data.hsd.month, p->data.hsd.year);		
	}
	else printf("\nDanh sach hop sua rong");
}

	/*Tim hop sua theo ten nhan hieu*/
bool SearchHS(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.hieu, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa hop sua theo ten nhan hieu*/
void DeleteHS(List &l) {
	char name[30];
	printf("\t- Nhap nhan hieu can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchHS(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.hieu, name) == 0)
				break;
			else a = p;
		}
		/*Xoa hop sua*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay hop sua nhan hieu %s", name);
}

	/*Dem so luong hop sua san xuat truoc nam 2020 trong danh sach*/
void CountHS2020(List l) {
	int count = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		if(p->data.hsd.year < 2020)
			count++;
	if(count != 0) printf("\n%d hop sua san xuat truoc 2020", count);
	else printf("Khong tim thay hop sua san xuat truoc 2020");
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

	/*Tim hop sua moi nhat trong danh sach*/
void SearchHSNew(List l) {
	node* ans = new node;
	ans = l.pHead;	//Gan phan tu dau tien la gia tri mac dinh
	for(node* p=l.pHead->pNext; p != NULL; p=p->pNext) {
		if(p->data.hsd.year > ans->data.hsd.year)
			ans = p;
		if(p->data.hsd.year == ans->data.hsd.year) {
			if(DayOfYear(p->data.hsd) > DayOfYear(ans->data.hsd))
				ans = p;
		}
	}
	
	printf("\nHop sua moi nhat: ");
	printf("\n%s\t%f\t%d/%d/%d", ans->data.hieu, ans->data.kLuong, ans->data.hsd.day, ans->data.hsd.month, ans->data.hsd.year);	
}

	/*Hoan vi 2 hop sua*/
void Swap(HopSua &hs1, HopSua &hs2) {
	HopSua temp = hs1;
	hs1 = hs2;
	hs2 = temp;
}

	/*Sap xep cac hop sua theo thu tu tang dan theo han su dung*/
void SortDTB(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext) {
				if(p->data.hsd.year > t->data.hsd.year)
					Swap(p->data, t->data);
				if(p->data.hsd.year == t->data.hsd.year) {
					if(DayOfYear(p->data.hsd) > DayOfYear(t->data.hsd))
						Swap(p->data, t->data);
				}
			}			
	}
	XuatDS(l);
}

	/*Quan ly list hop sua*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly Hop Sua==========");
		printf("\n1. Them hop sua");
		printf("\n2. Xuat danh sach hop sua");
		printf("\n3. Xoa hop sua");
		printf("\n4. Dem so luong hop sua san xuat truoc nam 2020 trong danh sach");
		printf("\n5. Tim hop sua moi nhat trong danh sach");
		printf("\n6. Sap xep cac hop sua theo thu tu tang dan theo han su dung");
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
			DeleteHS(l);
			break;
		}
		case 4:{
			CountHS2020(l);
			break;
		}
		case 5:{
			SearchHSNew(l);
			break;
		}
		case 6:{
			SortDTB(l);
			break;
		}
		case 0: exit(0);
	}
}

int main() {
	List l;
	Init(l);
	do{
		menu(l);
	}while(true);
	return 0;
}

