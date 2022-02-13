#include<stdio.h>
/*
	Khai bao cau truc du lieu cho danh sach lien ket don cac thi sinh.
	Bien rang thi sinh gom nhung thanh phan thong tin nhu sau:
	-	Ma thi sinh: toi da 5 ky tu.
	-	Ho ten: toi da 30 ky tu.
	-	Diem toan: kieu so nguyen.
	-	Diem van: kieu so nguyen.
	-	Diem hoa: kieu so nguyen.
	-	Diem trung binh: kieu so thuc.
*/
typedef struct ThiSinh {
	char maSo[5];
	char hoTen[30];
	int toan;
	int van;
	int hoa;
	float dtb;
} ThiSinh;

typedef struct node {
	ThiSinh data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

int main() {

	return 0;
}

