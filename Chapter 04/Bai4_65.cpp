#include<stdio.h>
#include<stdlib.h>

#define MAX 50
/*
	Xoay ma tran mot goc goc 90 do, 180 do, 270 do.
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void menu();
void XoayGoc(int mat[][MAX], int m, int n, int soLan);

	//Chuong trinh chinh
int main() {
	do{
		menu();
	}while(true);
	return 0;
}

	/*Chuc nang cua xoay goc*/
void menu() {
	int choice;
	do{
		printf("\n=====Xoay goc ma tran=====");
		printf("\n1. Xoay mot goc 90 do");
		printf("\n2. Xoay mot goc 180 do");
		printf("\n3. Xoay mot goc 270 do");
		printf("\n0. Thoat.");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>3)
			printf("\nChuc nang nay khong ton tai.");
	}while(choice<0 || choice>3);
	
	int mat[MAX][MAX], m, n;
	if(choice != 0)
		InpMat(mat, m, n);
	switch(choice) {
		case 1:{
			XoayGoc(mat, m, n, 1);
			break;
		}
		case 2:{
			XoayGoc(mat, m, n, 2);
			break;
		}
		case 3:{
			XoayGoc(mat, m, n, 3);
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

	/*Xoay ma tran mot goc goc 90 do, 180 do, 270 do*/
void XoayGoc(int mat[][MAX], int m, int n, int soLan) {
	int newMat[MAX][MAX];
	for(int k=1; k<=soLan; k++) {
		for(int i=0; i<n; i++) {	//So dong
			int dong=m-1;
			for(int j=0; j<m; j++) {	//So cot
				newMat[i][j] = mat[dong--][i];
			}
		}
		int _m = n, _n = m;
		for(int i=0; i<_m; i++)		//So dong
			for(int j=0; j<_n; j++)		//So cot
				mat[i][j] = newMat[i][j];
		m = _m, n = _n;
	}
	printf("\nXoay goc %d do", soLan*90);
	OutMat(mat, m, n);
}

