#include<stdio.h>
/*
	Hay khai bao cau truc du lieu cho danh sach lien ket don tong quat
*/
typedef struct KieuDuLieu {
	
} KieuDuLieu;

typedef struct node {
	KieuDuLieu data;	//KieuDuLieu la kieu duoc dinh nghia truoc
	node *pNext;		//Con tro chi den cau truc node
} node;

typedef struct List {
	node *pHead;		//Giu dia chi phan tu dau danh sach
	node *pTail;		//Giu dia chi phan tu cuoi danh sach
} List;

	/*Main funtion*/
int main() {
	
	return 0;
}

