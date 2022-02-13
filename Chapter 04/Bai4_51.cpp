#include<stdio.h>

#define MAX 50
/*
	Liet ke chi so cac dong chua gia tri am trong ma tran so nguyen
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void Listed(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	Listed(mat, m, n);
	return 0;
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

	//Kiem tra gia tri am cua dong
bool CheckSoAm(int mat[][MAX], int m, int n, int row) {
	for(int j=0; j<n; j++) 	//So cot
		if(mat[row][j] < 0)
			return true;
	return false;
}

	//Liet ke chi so cac dong chua gia tri am trong ma tran so nguyen
void Listed(int mat[][MAX], int m, int n) {
	printf("\nChi so dog chua gia tri am: ");
	for(int i=0; i<m; i++) 		//So dong
		if(CheckSoAm(mat, m, n, i) == true)
			printf("%5d", i);
}

