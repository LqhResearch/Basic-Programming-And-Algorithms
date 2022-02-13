#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac ve xem phim.
	Biet rang thong tin cua mot ve xem phim bao gom:
	-	Ten phim (20 ky tu)
	-	Gia tien (kieu nguyen)
	-	Xuat chieu (kieu thoi gian)
	-	Ngay xem (kieu ngay)
	a. Cai dat tat cac thao tac co ban cho sach lien ket don cac ve xem phim.
	b. Tinh tong gia tien cua tat ca cac ve xem phim.
	d. Sap xep sach theo thu tu tang dan theo ngay xem va xuat chieu.
*/
typedef struct Time {
	int hour;
	int minute;
	int second;
} Time;

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct VeXemPhim {
	char ten[20];
	int gia;
	Time xChieu;
	Date NgXem;
} VeXemPhim;

typedef struct node {
	VeXemPhim data;
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

	/*Tao node cac ve xem phim*/
node* CreateNode() {
	VeXemPhim vp;
	printf("\n-----Nhap Thong Tin Ve xem phim-----\n");
	printf("\t- Ten phim: ");
	fflush(stdin);		gets(vp.ten);
	printf("\t- Gia tien: ");
	scanf("%d", &vp.gia);
	printf("\t- Xuat chieu (hh/mm/ss): ");
	scanf("%d%d%d", &vp.xChieu.hour, &vp.xChieu.minute, &vp.xChieu.second);
	printf("\t- Ngay chieu (dd/mm/yyyy): ");
	scanf("%d%d%d", &vp.NgXem.day, &vp.NgXem.month, &vp.NgXem.year);
	
	node *p = new node;
	if(p != NULL) {
		p->data = vp;
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
	printf("\nTen phim\tGia tien\tXuat chieu\tNgay chieu");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%d\t%d:%d:%d\t%d/%d/%d", p->data.ten, p->data.gia, p->data.xChieu.hour, 
			p->data.xChieu.minute, p->data.xChieu.second, p->data.NgXem.day, p->data.NgXem.month, p->data.NgXem.year);
	}
	else printf("\nDanh sach sach cua thu vien rong");
}

	/*Tim phim theo ten phim*/
bool SearchP(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.ten, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa phim theo ten phim*/
void DeleteVXP(List &l) {
	char name[20];
	printf("\t- Nhap ten phim can xoa: ");
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
		/*Xoa phim*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay phim ten %s", name);
}

	/*Hoan vi 2 phim*/
void Swap(VeXemPhim &vp1, VeXemPhim &vp2) {
	VeXemPhim temp = vp1;
	vp1 = vp2;
	vp2 = temp;
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

	/*Tra ve giay trong thoi gian*/
int SecondOfTime(Time t) {
	return t.hour*3600+t.minute*60+t.second;
}

	/*Sap xep sach theo thu tu tang dan theo ngay xem va xuat chieu*/
void SortVXP(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext) {
				int day1 = DayOfYear(p->data.NgXem);
				int day2 = DayOfYear(t->data.NgXem);
				if(day1 > day2)
					Swap(p->data, t->data);
				if(day1 == day2) {
					int second1 = SecondOfTime(p->data.xChieu);
					int second2 = SecondOfTime(t->data.xChieu);
					if(second1 > second2)
						Swap(p->data, t->data);
				}
			}			
	}
	XuatDS(l);
}

	/*Tinh tong gia tien cua tat ca cac ve xem phim*/
void sumGiaTien(List l) {
	int sum = 0;
	for(node* p=l.pHead; p != NULL; p=p->pNext)
		sum+=p->data.gia;
	printf("\nTong gia cua tat ca ve xem phim: %d", sum);
}

	/*Quan ly sach cua thu vien*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly sach Rap chieu phim==========");
		printf("\n1. Them ve xem phim");
		printf("\n2. Xuat danh sach ve xem phim");
		printf("\n3. Xoa ve xem phim");
		printf("\n4. Tinh tong gia tien cua tat ca cac ve xem phim");
		printf("\n5. Sap xep sach theo thu tu tang dan theo ngay xem va xuat chieu");
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
			DeleteVXP(l);
			break;
		}
		case 4:{
			sumGiaTien(l);
			break;
		}
		case 5:{
			SortVXP(l);
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

