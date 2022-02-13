#include<stdio.h>
#include<stdlib.h>

#define MAX 50
/*
	-	Xoa mot dong trong ma tran
		Vi du:
		Chi so			
		0		-87	-75	-62	-54
		1		46	40	33	28
		2		-20	-18	-15	-10
		3		123	32	54	23
		Ket qua xoa dong 1:
		Chi so		
		0		-87	-75	-62	-54
		1		-20	-18	-15	-10
		2		123	32	54	23
	-Xoa mot cot trong ma tran

*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void menu();
void DeleteRow(int mat[][MAX], int m, int n);
void DeleteCol(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	do{
		menu();
	}while(true);
	return 0;
}

	/*Chuc nang xoa ma tran*/
void menu() {
	int choice;
	do{
		printf("\n=====Xoa ma tran=====");
		printf("\n1. Xoa mot dong");
		printf("\n2. Xoa mot cot");
		printf("\n0. Thoat.");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>2)
			printf("\nChuc nang nay khong ton tai.");
	}while(choice<0 || choice>2);
	
	int mat[MAX][MAX], m, n;
	if(choice != 0)
		InpMat(mat, m, n);
	switch(choice) {
		case 1:{
			DeleteRow(mat, m, n);
			break;
		}
		case 2:{
			DeleteCol(mat, m, n);
			break;
		}
		case 0: exit(0);
	}
}

	//Nhap ma tran so nguyen
void InpMat(int mat[][MAX], int &m, int &n) {
	do{
		printf("Nhap so dong = ");
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

	//Xuat ma tran so nguyen
void OutMat(int mat[][MAX], int m, int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	/*Xoa mot dong trong ma tran*/
void DeleteRow(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX], k;
	do{
		printf("\nNhap chi so dong can xoa (0, %d) = ", m-1);
		scanf("%d", &k);
		if(k < 0 || k >= m)
			printf("\nDong %d khong ton tai", k);
	}while(k < 0 || k >= m);
	
	for(int i=0; i<m; i++) 	//So dong
		for(int j=0; j<n; j++) 	//So cot
		{
			if(i >= k)
				newMat[i][j] = mat[i+1][j];
			else newMat[i][j] = mat[i][j];
		}
	printf("\nSau khi xoa dong %d: ", k);
	OutMat(newMat, --m, n);
}

	/*Xoa mot cot trong ma tran*/
void DeleteCol(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX], k;
	do{
		printf("\nNhap chi so cot can xoa (0, %d) = ", n-1);
		scanf("%d", &k);
		if(k < 0 || k >= n)
			printf("\nCot %d khong ton tai", k);
	}while(k < 0 || k >= n);
	
	for(int i=0; i<m; i++) 	//So dong
		for(int j=0; j<n; j++) 	//So cot
		{
			if(j >= k)
				newMat[i][j] = mat[i][j+1];
			else newMat[i][j] = mat[i][j];
		}
	printf("\nSau khi xoa cot %d: ", k);
	OutMat(newMat, m, --n);
}
