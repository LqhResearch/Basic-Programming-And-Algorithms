#include<stdio.h>
/*
	Noi hai danh sach lien ket don l1 va l2 lai thanh danh sach lien ket don l.
*/
typedef struct node {
	int x;
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

	/*Tao node*/
node* CreateNode(int x) {
	node *p = new node;
	if(p != NULL) {
		p->x = x;
		p->pNext = NULL;
		return p;
	}
	else return NULL;
}

	/*Add node o cuoi*/
void AddAfter(List &l, int x) {
	node *new_ele = CreateNode(x);
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
	if(l.pHead != NULL) {
		for(node* p=l.pHead; p != NULL; p=p->pNext)
			printf("%5d", p->x);
	}
	else printf("\nDanh sach rong");
}

	/*Ghep 2 list thanh 1*/
void MergeList(List l1, List l2, int n, int m) {
	List l;		Init(l);
	for(node* p=l1.pHead; p != NULL; p=p->pNext)
		AddAfter(l, p->x);
	for(node* p=l2.pHead; p != NULL; p=p->pNext)
		AddAfter(l, p->x);
	printf("\nXuat danh sach: ");	XuatDS(l);
}

	/*Main function*/
int main() {
	int n, m, x;	//So luong node
	List l1;	Init(l1);
	
	//Tao danh sach lien ket don 1
	printf("\nNhap so luong node: ");
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		printf("Nhap node: ");
		scanf("%d", &x);
		AddAfter(l1, x);
	}
	printf("\nXuat danh sach: ");	XuatDS(l1);
	
	//Tao danh sach lien ket don 2
	List l2;	Init(l2);
	printf("\nNhap so luong node: ");
	scanf("%d", &m);
	for(int i=1; i<=m; i++) {
		printf("Nhap node: ");
		scanf("%d", &x);
		AddAfter(l2, x);
	}
	printf("\nXuat danh sach: ");	XuatDS(l2);
	
	//Ghep 2 list thanh 1 list
	MergeList(l1, l2, n, m);
	return 0;
}

