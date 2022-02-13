#include<stdio.h>
/*
	Viet ham khoi tao danh sach lien ket don cac sinh vien (maSo, hoTen, tuoi)
*/
typedef struct SinhVien {
	char maSo[10];
	char hoTen[50];
	int age;
} SinhVien;

typedef struct node {
	SinhVien data;
	node *pNext;
} node;

typedef struct List {
	node *pHead;
	node *pTail;
} List;

	//Khoi tao danh sach rong
void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

int main() {
	List l;
	
	Init(l);	//Khoi tao danh sach lien ket don
	return 0;
}

