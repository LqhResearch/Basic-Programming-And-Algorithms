#include<stdio.h>
#include<stdlib.h>
/*
	Them nut vao danh sach: 
	-	Them nut vao cuoi danh sach.
	-	Them nut vao sau nut q trong danh sach.
	-	Them nut vao truoc nut q trong danh sach.
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
	printf("\nNhap nut: ");
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

	/*Search q*/
node* SearchNode(List l, int x) {
	for(node* q=l.pHead; q !=NULL; q=q->pNext)
		if(q->data == x)
			return q;
	return NULL;
}

	/*Add node after node q*/
void AddNodeAfterQ(List &l) {
	int x;
	printf("\nNhap nut can tim: ");
	scanf("%d", &x);
	node* q=SearchNode(l, x);
	if(q != NULL) {
		node* new_ele = CreateNode();
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
	}
	else printf("\nKhong tim thay node %d", x);
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

	/*Them mot nut vao truoc q*/
void AddNodeBeforeQ(List &l) {
	int x;
	printf("\nNhap nut can tim: ");
	scanf("%d", &x);
	node* q=SearchNode(l, x); 	//Tim node
	
	if(q != NULL) {
		node* new_ele = CreateNode();
		if(q == l.pHead) {
			new_ele->pNext = l.pHead;
			l.pHead = new_ele;
		}
		else {
			node* p;
			for(node* i=l.pHead; i != NULL; i=i->pNext)	//Duyet node tim node truoc q
				if(i->data != q->data)
					p=i;
				else break;
			p->pNext = new_ele;
			new_ele->pNext = q;
		}
	}
	else printf("\nNode %d khong tim thay", x);
}

int main() {
	List l;		//Danh sach lien ket
	Init(l);
	int choice;
	
	do{
		do{
			printf("\n===============Them nut DSLK==============");
			printf("\n1. Them nut vao cuoi danh sach");
			printf("\n2. Them nut vao sau nut q trong danh sach");
			printf("\n3. Them nut vao truoc nut q trong danh sach");
			printf("\n4. Xuat danh sach");
			printf("\n0. Thoat");
			printf("\n >> Hay lua chon: ");
			scanf("%d", &choice);
			if(choice<0 || choice>4)
				printf("\nChuc nang nay khong ton tai");
		}while(choice<0 || choice>4);
		
		switch(choice) {
			case 1:{
				AddNodeAfter(l);
				break;
			}
			case 2:{
				AddNodeAfterQ(l);
				break;
			}
			case 3:{
				AddNodeBeforeQ(l);
				break;
			}
			case 4:{
				OutputList(l);
				break;
			}
			case 0: exit(0);
		}
	}while(true);
	return 0;
}

