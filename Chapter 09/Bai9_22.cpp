#include<stdio.h>
#include<stdlib.h>
/*
	Dem so luong node trong mot dslk don cac so nguyen
*/
typedef struct node {
	int data;
	node* pNext;
} node;

typedef struct List {
	node* pHead;
	node* pTail;
} List;

	/*Khoi tao dslk rong*/
void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

	/*Tao nut*/
node* CreateNode() {
	int x;
	printf("Nhap nut = ");
	scanf("%d", &x);
	
	node* p = new node;
	if(p != NULL) {
		p->data = x;
		p->pNext = NULL;
		return p;
	}
	else return NULL;
}

	/*Them node vao cuoi dslk*/
void AddTail(List &l) {
	node* new_ele = CreateNode();
	if(l.pHead == NULL) {
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else {
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

	/*Duyet danh sach lien ket*/
void Output(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%5d", p->data);
	}
	else printf("Danh sach rong");
}

	/*Dem so node*/
void CountNode(List l) {
	int count = 0;
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			count++;
	}
	printf("\nDanh sach co %d node", count);
}

int main() {
	List l;
	Init(l);
	int choice;
	do{
		printf("\n===============Node===============");
		printf("\n1. Them node");
		printf("\n2. Duyet danh sach");
		printf("\n3. Dem node");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:{
				AddTail(l);
				break;
			}
			case 2:{
				Output(l);
				break;
			}
			case 3:{
				CountNode(l);
				break;
			}
			case 0: exit(0);
		}
		
	}while(true);
	return 0;
}

