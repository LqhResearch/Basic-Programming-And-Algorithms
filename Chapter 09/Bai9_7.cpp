#include<stdio.h>
/*
	Nhap, xuat danh sach lien ket don cac so nguyen.
	Tinh tong cac node trong danh sach lien ket don.
*/
typedef struct node {
	int data;
	node* pNext;
} node;

typedef struct List {
	node *pHead;
	node *pTail;
} List;

	/*Khoi tao DSLK rong*/
void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

	/*Tao node*/
node* CreateNode(int x) {
	node *p = new node;
//or	p = new (node);
	if(p != NULL) {	//Tao thanh cong nut p
		p->data = x;
		p->pNext = NULL;
	}
	else return NULL;
}

	/*Tao node o dau danh sach lien ket*/
void addHead(List &l, node* new_ele) {
	if(l.pHead == NULL)	{	//Danh sach rong
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else {
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

	/*Tao node o dau danh sach lien ket*/
void addTail(List &l, node* new_ele) {
	if(l.pHead == NULL)	{	//Danh sach rong
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else {
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

	/*Nhap danh sach lien ket don cac so nguyen*/
void inputList(List &l) {
	int n, x;
	printf("\nNhap so luong node: ");
	scanf("%d", &n);
	
	Init(l);	//Khoi tao DSLK rong
	for(int i=1; i<=n; i++) {
		printf("Nhap so nguyen: ");
		scanf("%d", &x);
		node *p = CreateNode(x);
		//addHead(l, p);	//Them vao dau danh sach
		addTail(l, p);		//Them vao cuoi danh sach
	}
}

	/*Xuat danh sach lien ket don cac so nguyen*/
void outputList(List l) {
	printf("\nXuat DSLK: ");
	for(node *p=l.pHead; p != NULL; p=p->pNext) 
		printf("%5d", p->data);
}

	/*Tinh tong danh sach lien ket cac so nguyen*/
int sumList(List l) {
	int sum = 0;
	for(node *p=l.pHead; p != NULL; p=p->pNext) 
		sum+=p->data;
	return sum;
}

int main() {
	List l;
	inputList(l);
	outputList(l);
	printf("\nTong DSLK = %d", sumList(l));
	return 0;
}

