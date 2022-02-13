#include<stdio.h>
/*
	Hay khai bao cau truc du lieu cho danh sach lien ket don so phuc
*/
typedef struct SoPhuc {
	float thuc;
	float ao;
} SoPhuc;

typedef struct node {
	SoPhuc data;
	node *pNext;
} node;

typedef struct List {
	node *pHead;
	node *pTail;
} List;

	/*Main function*/
int main() {
	
	return 0;
}

