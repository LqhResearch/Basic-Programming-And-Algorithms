#include<stdio.h>
/*
	Kiem tra danh sach co rong hay khong?
*/
typedef struct node {
	int data;
	node *pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Khoi tao danh sach rong*/
void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

	/*Kiem tra danh sach co rong hay khong?*/
bool IsEmpty(List l) {
	return l.pHead == NULL ? true : false;
}

	/*Main function*/
int main() {
	List l;
	Init(l);
	if(IsEmpty(l) == true)
		printf("\nDanh sach rong");
	else
		printf("\nDanh sach khong rong");
	return 0;
}

