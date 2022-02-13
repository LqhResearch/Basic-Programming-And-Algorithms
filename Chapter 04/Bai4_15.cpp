#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50
/*
	Viet cac ham sap xep sau:
	-	Sap xep cac phan tu tren cung mot dong tang dan tu trai sang phai.
	-	Sap xep cac phan tu tren cung mot dong giam dan tu trai sang phai.
	-	Sap xep cac phan tu tren cung mot cot tang dan tu tren xuong duoi.
	-	Sap xep cac phan tu tren cung mot cot giam dan tu tren xuong duoi.
	-	Sap xep cac phan tu tang dan tu trai sang phai va tu tren xuong duoi.
	-	Sap xep cac phan tu giam dan tu trai sang phai va tu tren xuong duoi.
*/
	//Xuat ma tran so nguyen
void OutMat(int mat[][MAX], int m, int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	//Nhap ma tran so nguyen
void InpMat(int mat[][MAX], int &m, int &n) {
	do{
		printf("\nNhap so dong = ");
		scanf("%d", &m);
		if(m<=0)
			printf("So dong phai lon hon 0\n");
	}while(m<=0);
	do{
		printf("Nhap so cot = ");
		scanf("%d", &n);
		if(n<=0)
			printf("So cot phai lon hon 0\n");
	}while(n<=0);
	
	printf("\n===Nhap ma tran===\n");
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) {	//So cot
			printf("Phan tu thu [%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, m, n);
}

	//Hoan vi hai gia tri
void Swap(int &a, int &b) {
	int temp=a;
	a=b;
	b=temp;
}

	//Sap xep cac phan tu tren cung mot dong tang dan tu trai sang phai
void SortCellOfRow(int mat[][MAX], int m, int n, int dong, char sort[]) {
	if(strcmp(sort, "up") == 0) {
		for(int k=0; k<n; k++)
			for(int j=k+1; j<n; j++)	//So cot
				if(mat[dong][k] > mat[dong][j])
					Swap(mat[dong][k], mat[dong][j]);
	}
	if(strcmp(sort, "down") == 0) {
		for(int k=0; k<n; k++)
			for(int j=k+1; j<n; j++)	//So cot
				if(mat[dong][k] < mat[dong][j])
					Swap(mat[dong][k], mat[dong][j]);
	}
}
		
void SortRowUp(int mat[][MAX], int m, int n) {
	for(int i=0; i<m; i++)
		SortCellOfRow(mat, m, n, i, (char*)"up");
	OutMat(mat, m, n);
}

	//Sap xep cac phan tu tren cung mot dong giam dan tu trai sang phai
void SortRowDown(int mat[][MAX], int m, int n) {
	for(int i=0; i<m; i++)
		SortCellOfRow(mat, m, n, i, (char*)"down");
	OutMat(mat, m, n);
}

	//Sap xep cac phan tu tren cung mot cot tang dan tu tren xuong duoi
void SortCellOfColumn(int mat[][MAX], int m, int n, int cot, char sort[]) {
	if(strcmp(sort, "up") == 0) {
		for(int i=0; i<m; i++)
			for(int k=i+1; k<n; k++)
				if(mat[i][cot] > mat[k][cot])
						Swap(mat[i][cot], mat[k][cot]);
	}
	if(strcmp(sort, "down") == 0) {
		for(int i=0; i<m; i++)
			for(int k=i+1; k<n; k++)
				if(mat[i][cot] < mat[k][cot])
						Swap(mat[i][cot], mat[k][cot]);
	}
}

void SortColumnUp(int mat[][MAX], int m, int n) {
	for(int j=0; j<n; j++)
		SortCellOfColumn(mat, m, n, j, (char*)"up");
	OutMat(mat, m, n);
}

	//Sap xep cac phan tu tren cung mot cot giam dan tu tren xuong duoi
void SortColumnDown(int mat[][MAX], int m, int n) {
	for(int j=0; j<n; j++)
		SortCellOfColumn(mat, m, n, j, (char*)"down");
	OutMat(mat, m, n);
}

	//Sap xep cac phan tu tang dan tu trai sang phai va tu tren xuong duoi.
void SortUp(int mat[][MAX], int soDong, int soCot) {
	int allCell=soDong*soCot;
	for(int i=0; i<allCell; i++)
		for(int j=i+1; j<allCell; j++)
			if(mat[i/soCot][i%soCot] > mat[j/soCot][j%soCot])
				Swap(mat[i/soCot][i%soCot], mat[j/soCot][j%soCot]);
	OutMat(mat, soDong, soCot);
}

	//Sap xep cac phan tu giam dan tu trai sang phai va tu tren xuong duoi.
void SortDown(int mat[][MAX], int soDong, int soCot) {
	int allCell=soDong*soCot;
	for(int i=0; i<allCell; i++)
		for(int j=i+1; j<allCell; j++)
			if(mat[i/soCot][i%soCot] < mat[j/soCot][j%soCot])
				Swap(mat[i/soCot][i%soCot], mat[j/soCot][j%soCot]);
	OutMat(mat, soDong, soCot);
}

	//Quan li sap xep
void SortManage() {
	int mat[MAX][MAX], m, n, type;
	
	do{
		printf("\n\t===SAP XEP===");
		printf("\n1. Sap xep cac phan tu tren cung mot dong tang dan tu trai sang phai");
		printf("\n2. Sap xep cac phan tu tren cung mot dong giam dan tu trai sang phai");
		printf("\n3. Sap xep cac phan tu tren cung mot cot tang dan tu tren xuong duoi");
		printf("\n4. Sap xep cac phan tu tren cung mot cot giam dan tu tren xuong duoi");
		printf("\n5. Sap xep cac phan tu tang dan tu trai sang phai va tu tren xuong duoi");
		printf("\n6. Sap xep cac phan tu giam dan tu trai sang phai va tu tren xuong duoi");
		printf("\n0. Thoat");
		printf("\n>> Hay lua chon: ");
		scanf("%d", &type);
		if(type<0 || type>6)
			printf("Chuc nang nay khong ton tai\n");
	}while(type<0 || type>6);
	
	switch(type) {
		case 1:{
			printf("\n===Sap xep cac phan tu tren cung mot dong tang dan tu trai sang phai===");
			InpMat(mat, m, n);
			SortRowUp(mat, m, n);
			break;
		}
		case 2:{
			printf("\n===Sap xep cac phan tu tren cung mot dong giam dan tu trai sang phai===");
			InpMat(mat, m, n);
			SortRowDown(mat, m, n);
			break;
		}
		case 3:{
			printf("\n===Sap xep cac phan tu tren cung mot cot tang dan tu tren xuong duoi===");
			InpMat(mat, m, n);
			SortColumnUp(mat, m, n);
			break;
		}
		case 4:{
			printf("\n===Sap xep cac phan tu tren cung mot cot giam dan tu tren xuong duoi===");
			InpMat(mat, m, n);
			SortColumnDown(mat, m, n);
			break;
		}
		case 5:{
			printf("\n===Sap xep cac phan tu tang dan tu trai sang phai va tu tren xuong duoi===");
			InpMat(mat, m, n);
			SortUp(mat, m, n);
			break;
		}
		case 6:{
			printf("\n===Sap xep cac phan tu giam dan tu trai sang phai va tu tren xuong duoi===");
			InpMat(mat, m, n);
			SortDown(mat, m, n);
			break;
		}
		case 0: exit(1);
	}
}

	//Chuong trinh chinh
int main() {
	do{
		SortManage();
	}while(true);
	return 0;
}

