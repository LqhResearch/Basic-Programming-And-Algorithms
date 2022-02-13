#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac hoc sinh
	Biet rang thong tin cua mot hoc sinh bao gom:
	-	Ho ten (30 ky tu).
	-	Diem toan.
	-	Diem van.
	-	Diem trung binh (tat ca la so thuc).
	a)	Cai dat tat ca cac thao tac co ban cho danh sach lien ket cac hoc sinh.
	b)	Liet ke cac hoc sinh co diem toan nho hon 5 diem.
	c)	Dem so luong hoc sinh co diem toan va diem van 8 diem trong danh sach.
	d)	Viet ham sap xep cac hoc sinh giam dan theo diem trung binh.
*/
typedef struct HocSinh {
	char hoTen[30];
	float toan;
	float van;
	float dtb;
} HocSinh;

typedef struct node {
	HocSinh data;
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

	/*Tao node hoc sinh*/
node* CreateNode() {
	HocSinh hs;
	printf("\n-----Nhap Thong Tin-----\n");
	printf("\t- Ho ten: ");
	fflush(stdin);		gets(hs.hoTen);
	
	do{
		printf("\t- Diem toan: ");
		scanf("%f", &hs.toan);
		if(hs.toan<0 || hs.toan>10)
			printf("Hay nhap diem trong khoang [0, 10]\n");
	}while(hs.toan<0 || hs.toan>10);
	
	do{
		printf("\t- Diem van: ");
		scanf("%f", &hs.van);
		if(hs.van<0 || hs.van>10)
			printf("Hay nhap diem trong khoang [0, 10]");
	}while(hs.van<0 || hs.van>10);
	
	hs.dtb = (hs.toan+hs.van) / 2;
	
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
	printf("\n-----Xuat danh sach-----\n");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\nHo ten: %s\tToan = %.2f\tVan = %.2f\tDiem TB = %.2f", p->data.hoTen, p->data.toan, p->data.van, p->data.dtb);
	}
	else printf("\nDanh sach hoc sinh rong");
}

	/*Tim hoc sinh theo ten*/
bool SearchHS(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.hoTen, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa hoc vien theo ten*/
void DeleteHS(List &l) {
	char name[30];
	printf("\t- Nhap ho ten can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchHS(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.hoTen, name) == 0)
				break;
			else a = p;
		}
		/*Xoa hoc sinh*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay hoc sinh %s", name);
}

	/*Liet ke hoc sinh co diem toan nho hon 5*/
void ListedHST5(List &l) {
	int count = 0;
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(p->data.toan < 5) {
				printf("\nHo ten: %s\tToan = %.2f\tVan = %.2f\tDiem TB = %.2f", p->data.hoTen, p->data.toan, p->data.van, p->data.dtb);
				count++;
			}	
	}
	if(count == 0) printf("\nKhong co hoc sinh nao co diem toan < 5");
}

	/*Dem so luong hoc sinh co diem toan va diem van lon hon 8*/
void CountHSTV8(List &l) {
	int count = 0;
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(p->data.toan > 8 && p->data.van > 8) {
				count++;
			}	
	}
	if(count == 0) printf("\nKhong co hoc sinh co diem toan va diem van lon hon 8");
	else printf("\n%d hoc sinh co diem toan va diem van lon hon 8", count++);
}

	/*Hoan vi 2 hoc sinh*/
void Swap(HocSinh &hs1, HocSinh &hs2) {
	HocSinh temp = hs1;
	hs1 = hs2;
	hs2 = temp;
}

	/*Sap xep giam dan theo diem trung binh*/
void SortDTB(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(p->data.dtb < t->data.dtb)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Quan ly list hoc sinh*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly Hoc sinh==========");
		printf("\n1. Them hoc sinh");
		printf("\n2. Xuat danh sach hoc sinh");
		printf("\n3. Xoa hoc sinh");
		printf("\n4. Liet ke hoc sinh co diem toan nho hon 5");
		printf("\n5. Dem so luong hoc sinh co diem toan va diem van lon hon 8");
		printf("\n6. Sap xep giam dan theo diem trung binh");
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
			ListedHST5(l);
			break;
		}
		case 5:{
			CountHSTV8(l);
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

