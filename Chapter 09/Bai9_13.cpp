#include<stdio.h>
/*
	Khai bao cau truc du lieu cho danh sach lien ket don cac hoc sinh.
	Bien rang hoc sinh gom nhung thanh phan thong tin nhu sau:
	-	Ho ten: toi da 30 ky tu.
	-	Diem toan: kieu so nguyen.
	-	Diem van: kieu so nguyen.
	-	Diem trung binh: kieu so thuc.
*/
typedef struct HocSinh {
	char hoTen[30];
	int toan;
	int van;
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

int main() {

	return 0;
}

