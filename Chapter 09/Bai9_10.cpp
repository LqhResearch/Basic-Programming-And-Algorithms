#include<stdio.h>
/*
	Lay node dau tien trong danh sach ra khoi danh sach lien ket?
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

	/*Tao node moi*/
node* CreateNode() {
	int x;
	printf("Nhap nut: ");
	scanf("%d", &x);
	
	node* p = new node;
	if(p != NULL) {
		p->data = x;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Them nut vao cuoi danh sach*/
void AddNodeAfter(List &l) {
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

	/*Tao danh sach lien ket*/
void CreateDSLK(List &l) {
	int n;
	printf("\nNhap so luong node: ");
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++)
		AddNodeAfter(l);
}


	/*Duyet danh sach lien ket*/
void OutputList(List l) {
	printf("\nXuat danh sach: ");
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%5d", p->data);
	}
	else printf("\nDanh sach rong");
}

	/*Xoa node dau tien trong danh sach*/
void DeleteFirstNode(List &l) {
	node* p=l.pHead;
	l.pHead=p->pNext;
	delete p;
}

	/*Main function*/
int main() {
	List l;
	Init(l);
	CreateDSLK(l);
	OutputList(l);
	printf("\nSau khi xoa node dau tien: ");
	DeleteFirstNode(l);
	OutputList(l);
	return 0;
}

