#include<stdio.h>
#include<stdlib.h>
/*
	Danh sach lien ket kep cac so nguyen:
	-	Khai bao danh sach lien ket kep.
	-	Khoi tao danh sach lien ket kep.
	-	Kiem tra danh sach lien ket kep co rong hay khong?.
	-	Tao node trong danh sach lien ket kep.
	-	Duyet danh sach lien ket kep.
	-	Them mot node vao dau.
	-	Them mot node vao cuoi.
	-	Them mot node p vao sau node q.
	-	Them mot node p vao truoc node q.
	-	Xoa mot node vao dau.
	-	Xoa mot node vao cuoi.
	-	Xoa mot node sau node q.
	-	Xoa mot node truoc node q.
	-	Sap xep danh sach theo thu tu tang dan.
	-	Sap xep danh sach theo thu tu giam dan.
	-	Tong cac node trong dslk kep.
	-	Tich cac node trong dslk kep.
*/
	/*Khai bao danh sach lien ket kep*/
typedef struct node {
	int data;
	node *pre;		//tro den phan tu dung truoc no
	node *next;		//tro den phan tu dung sau no
} node;

typedef struct List {
	node *head;		//tro den phan tu dau danh sach
	node *tail;		//tro den phan tu cuoi danh sach
} List;

	/*Khoi tao danh sach lien ket kep*/
void Init(List &l) {
	l.head = l.tail = NULL;
}

	/*Kiem tra danh sach lien ket kep co rong hay khong?*/
void Empty(List l) {
	if(l.head == NULL)
		printf("\nDanh sach lien ket rong");
	else printf("\nDanh sach lien ket khong rong");
}

	/*Tao node trong danh sach lien ket kep*/
node* CreateNode() {
	int x;
	printf("Nhap node: ");
	scanf("%d", &x);
	
	node* p = new node;
	if(p != NULL) {
		p->data = x;
		p->pre = NULL;
		p->next = NULL;
		return p;
	}
	else return NULL;
}

	/*Duyet danh sach lien ket kep*/
void XuatDS(List l) {
	if(l.head != NULL) {
		printf("\nXuat danh sach: ");
		for(node* p=l.head; p != NULL; p=p->next)
			printf("%5d", p->data);
	}
	else printf("\nDanh sach rong");
}

	/*Them mot node vao dau*/
void AddHead(List &l) {
	node *new_ele = CreateNode();
	if(l.head == NULL) {
		l.head = new_ele;
		l.tail = l.head;
	}
	else {
		new_ele->next = l.head;
		l.head->pre = new_ele;
		l.head = new_ele;
	}
}
	
	/*Them mot node vao cuoi*/
void AddTail(List &l) {
	node *new_ele = CreateNode();
	if(l.head == NULL) {
		l.head = new_ele;
		l.tail = l.head;
	}
	else {
		l.tail->next = new_ele;
		new_ele->pre = l.tail;
		l.tail = new_ele;
	}
}

	/*Tim node trong danh sach*/
node* SearchNode(List l) {
	int x;
	if(l.head != NULL) {
		printf("Nut can tim: ");
		scanf("%d", &x);
		for(node* p=l.head; p != NULL; p=p->next)
			if(p->data == x)
				return p;
	}
	return NULL;
}

	/*Them mot node p vao sau node q*/
void AddAfter(List &l) {
	node* q = SearchNode(l);		//Tim node q
	node* p = q->next;
	node* new_ele = CreateNode();	//Tao node
	if(q != NULL) {
		new_ele->next = p;
		new_ele->pre = q;
		q->next = new_ele;
		if(p != NULL)
			p->pre = new_ele;
		if(q == l.tail)
			l.tail = new_ele;
	}
}

	/*Them mot node p vao sau node q*/
void AddBefore(List &l) {
	node* q = SearchNode(l);		//Tim node q
	node* p = q->pre;
	node* new_ele = CreateNode();	//Tao node
	if(q != NULL) {
		new_ele->next = q;
		new_ele->pre = p;
		q->pre = new_ele;
		if(p != NULL)
			p->next = new_ele;
		if(q == l.head)
			l.head = new_ele;
	}
}

	/*Xoa mot node vao dau*/
void DeleteHead(List &l) {
	if(l.head != NULL) {
		node *p = l.head;
		l.head = l.head->next;
		l.head->pre = NULL;
		delete p;
		if(l.head == NULL)
			l.tail = NULL;
		else 
			l.head->pre = NULL;
	}
	XuatDS(l);
}

	/*Xoa mot node vao cuoi*/
void DeleteTail(List &l) {
	if(l.tail != NULL) {
		node *p = l.tail;
		l.tail = l.tail->pre;
		l.tail->next = NULL;
		delete p;
		if(l.head == NULL)
			l.tail = NULL;
		else 
			l.head->pre = NULL;
	}
	XuatDS(l);
}

	/*Xoa mot node sau node q*/
void DeleteAfter(List &l) {
	node* q = SearchNode(l);		//Tim node q
	node* p;
	if(q != NULL) {
		p = q->next;
		if(p != NULL) {
			q->next = p->next;
			if(p == l.tail)
				l.tail = q;
			else
				p->next->pre = q;
			delete p;
		}
	}
}

	/*Xoa mot node truoc node q*/
void DeleteBefore(List &l) {
	node* q = SearchNode(l);		//Tim node q
	node* p;
	if(q != NULL) {
		p = q->pre;
		if(p != NULL) {
			q->pre = p->pre;
			if(p == l.head)
				l.head = q;
			else
				p->pre->next = q;
			delete p;
		}
	}
}

	/*Hoan vi hai so nguyen*/
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

	/*Sap xep danh sach theo thu tu tang dan*/
void SortUp(List &l) {
	if(l.head != NULL) {
		for(node* p=l.head; p != NULL; p=p->next)
			for(node* t=p->next; t != NULL; t=t->next)
				if(p->data > t->data)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Sap xep danh sach theo thu tu giam dan*/
void SortDown(List &l) {
	if(l.head != NULL) {
		for(node* p=l.head; p != NULL; p=p->next)
			for(node* t=p->next; t != NULL; t=t->next)
				if(p->data < t->data)
					Swap(p->data, t->data);
	}
	XuatDS(l);
}

	/*Tong cac node trong dslk kep*/
void SumList(List &l) {
	int sum = 0;
	if(l.head != NULL) {
		for(node* p=l.head; p != NULL; p=p->next)
			sum+=p->data;
		printf("\nTong: %d", sum);
	}
}

	/*Tich cac node trong dslk kep*/
void MultiList(List &l) {
	int multi = 1;
	if(l.head != NULL) {
		for(node* p=l.head; p != NULL; p=p->next)
			multi*=p->data;
		printf("\nTich: %d", multi);
	}
}

	/*Chuc nang danh lien ket kep*/
void menu(List &l) {
	int choice;
	do{
		printf("\n\t==========Danh sach lien ket kep==========");
		printf("\n1. Them node");
		printf("\n2. Duyet danh sach");
		printf("\n3. Kiem tra danh sach co rong hay khong?");
		printf("\n4. Them mot node vao dau");
		printf("\n5. Them mot node vao cuoi");
		printf("\n6. Them mot node p vao sau node q");
		printf("\n7. Them mot node p vao truoc node q");
		printf("\n8. Xoa mot node vao dau");
		printf("\n9. Xoa mot node vao cuoi");
		printf("\n10. Xoa mot node sau node q");
		printf("\n11. Xoa mot node truoc node q");
		printf("\n12. Sap xep danh sach theo thu tu tang dan");
		printf("\n13. Sap xep danh sach theo thu tu giam dan");
		printf("\n14. Tong cac node trong dslk kep");
		printf("\n15. Tich cac node trong dslk kep");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>15)
			printf("\nChuc nang nay khong ton tai");
	}while(choice<0 || choice>15);
	
	switch(choice) {
		case 1:{
			AddTail(l);
			break;
		}
		case 2:{
			XuatDS(l);	
			break;
		}
		case 3:{
			Empty(l);
			break;
		}
		case 4:{
			AddHead(l);
			break;
		}
		case 5:{
			AddTail(l);
			break;
		}
		case 6:{
			AddAfter(l);
			break;
		}
		case 7:{
			AddBefore(l);
			break;
		}
		case 8:{
			DeleteHead(l);
			break;
		}
		case 9:{
			DeleteTail(l);
			break;
		}
		case 10:{
			DeleteAfter(l);
			break;
		}
		case 11:{
			DeleteBefore(l);
			break;
		}
		case 12:{
			SortUp(l);
			break;
		}
		case 13:{
			SortDown(l);
			break;
		}
		case 14:{
			SumList(l);
			break;
		}
		case 15:{
			MultiList(l);
			break;
		}
		case 0: exit(0);
	}
}

	/*Main funtion*/
int main() {
	List l;		Init(l);
	do {
		menu(l);
	}while(true);
	return 0;
}

