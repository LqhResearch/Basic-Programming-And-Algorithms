#include<stdio.h>
#include<math.h>

#define MAX 50
/*
	Cho ma tran cac so thuc A(m x n).
	Hay xay dung ma tran B(m x n) tu ma tran A sao cho B[i][j] = abs(A[i][j]).
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void CreateMatrix(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	CreateMatrix(mat, m, n);
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

	/*Tao ma tran B[i][j] = abs(A[i][j])*/
void CreateMatrix(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX];
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			newMat[i][j] = abs(mat[i][j]);
	printf("\nTao ma tran B: ");
	OutMat(newMat, m, n);
}
