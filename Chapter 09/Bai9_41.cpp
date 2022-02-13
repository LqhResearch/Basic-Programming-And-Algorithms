#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao cau truc du lieu cua mot danh sach lien ket don cac thi sinh.
	Biet rang thong tin cua mot thi sinh bao gom:
	-	Ma thi sinh (5 ky tu)
	-	Ho ten thi sinh (30 ky tu)
	-	Diem toan (kieu thuc)
	-	Diem ly (kieu thuc)
	-	Diem hoa (kieu thuc)
	-	Diem tong cong (kieu thuc)
	a. Cai dat tat cac thao tac co ban cho sach lien ket don cac thi sinh.
	b. Liet ke cac thi sinh dau trong danh sach (diem tong cong >=15 khong bi diem 0)
	c. Sap xep sach theo thu tu giam dan theo diem tong cong.
*/
typedef struct ThiSinh {
	char maSo[5];
	char hoTen[30];
	float toan;
	float ly;
	float hoa;
	float dtc;	//Diem tong cong = toan + ly + hoa
} ThiSinh;

typedef struct node {
	ThiSinh data;
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

	/*Tao node cac thi sinh*/
node* CreateNode() {
	ThiSinh ts;
	printf("\n-----Nhap Thong Tin Thi sinh-----\n");
	printf("\t- Ma so: ");
	fflush(stdin);		gets(ts.maSo);
	printf("\t- Ten thi sinh: ");
	fflush(stdin);		gets(ts.hoTen);
	printf("\t- Diem toan - Diem ly - Diem hoa: ");
	scanf("%f%f%f", &ts.toan, &ts.ly, &ts.hoa);
	ts.dtc = ts.toan + ts.ly + ts.hoa;
	
	node *p = new node;
	if(p != NULL) {
		p->data = ts;
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
	printf("\nMa thi sinh\tTen thi sinh\tDiem toan\tDiem ly\tDiem hoa\tDiem tong cong");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("\n%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f", p->data.maSo, p->data.hoTen, p->data.toan, 
			p->data.ly, p->data.hoa, p->data.dtc);
	}
	else printf("\nDanh sach thi sinh rong");
}

	/*Tim thi sinh theo ma so thi sinh*/
bool SearchTS(List l, char name[]) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(strcmp(p->data.maSo, name) == 0)
				return true;
	}
	return false;
}

	/*Xoa thi sinh theo ma so thi sinh*/
void DeleteTS(List &l) {
	char name[5];
	printf("\t- Nhap ma so thi sinh can xoa: ");
	fflush(stdin);		gets(name);
	bool test = SearchTS(l, name);
	
	if(test == true) {
		node *a = new node;
		node *p = new node;
		for(p=l.pHead; p != NULL; p=p->pNext) {
			if(strcmp(p->data.maSo, name) == 0)
				break;
			else a = p;
		}
		/*Xoa thi sinh*/
		if(l.pHead == p) 
			l.pHead = p->pNext;
		else if(l.pTail == p) {
			l.pTail = a;
			a->pNext = NULL;
		}
		else a->pNext = p->pNext;
		delete p;
	}
	else printf("\nKhong tim thay thi sinh ma so %s", name);
}

	/*Hoan vi 2 sach*/
void Swap(ThiSinh &ts1, ThiSinh &ts2) {
	ThiSinh temp = ts1;
	ts1 = ts2;
	ts2 = temp;
}

	/*Sap xep sach theo thu tu giam dan theo diem tong cong*/
void SortTS(List &l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			for(node* t=p->pNext; t != NULL; t=t->pNext)
				if(p->data.dtc < t->data.dtc)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Liet ke cac thi sinh dau trong danh sach*/
void TSDau(List l) {
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			if(p->data.dtc >= 15 && p->data.toan != 0 && p->data.ly != 0 && p->data.hoa != 0)
				printf("\n%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f", p->data.maSo, p->data.hoTen, p->data.toan, 
				p->data.ly, p->data.hoa, p->data.dtc);
	}
}

	/*Quan ly thi sinh*/
void menu(List &l) {
	int choice;
	do{
		printf("\n==========Quan ly sach Thi sinh==========");
		printf("\n1. Them thi sinh");
		printf("\n2. Xuat danh sach thi sinh");
		printf("\n3. Xoa thi sinh");
		printf("\n4. Liet ke cac thi sinh dau trong danh sach");
		printf("\n5. Sap xep sach theo thu tu giam dan theo diem tong cong");
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
			DeleteTS(l);
			break;
		}
		case 4:{
			TSDau(l);
			break;
		}
		case 5:{
			SortTS(l);
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

