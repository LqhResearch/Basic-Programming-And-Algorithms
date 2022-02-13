#include<stdio.h>
/*
	Khai bao cau truc du lieu cho danh sach lien ket don cac phong trong khach san.
	Bien rang phong khach san gom nhung thanh phan thong tin nhu sau:
	-	Ma phong: toi da 5 ky tu.
	-	Ten phong: toi da 30 ky tu.
	-	Gia thue phong: kieu so thuc
	-	So luong giuong: kieu so nguyen.
	-	Tinh trang phong: 0 ranh, 1 ban.
*/
typedef struct Phong {
	char maSo[5];
	char tenPhong[30];
	int giaThue;
	int soGiuong;
	bool tinhTrangPhong;
} Phong;

typedef struct node {
	Phong data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

int main() {

	return 0;
}

