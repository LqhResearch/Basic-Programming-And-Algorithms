#include<stdio.h>

#define MAX 50
/*
	Tim gia tri lon nhat trong ma tran vuong so nguyen
*/
void InpMat(int mat[][MAX], int &n);
void OutMat(int mat[][MAX], int n);
void MaxSquareMatrix(int mat[][MAX], int n);

	/*Main function*/
int main() {
	int mat[MAX][MAX], n;
	InpMat(mat, n);
	
	MaxSquareMatrix(mat, n);
	return 0;
}

	/*Nhap ma tran vuong so nguyen*/
void InpMat(int mat[][MAX], int &n) {
	do{
		printf("Nhap so dong = ");
		scanf("%d", &n);
		if(n<=0)
			printf("So dong phai lon hon 0\n");
	}while(n<=0);
	
	printf("\n===Nhap ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) {	//So cot
			printf("Phan tu thu [%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, n);
}

	/*Xuat ma tran vuong so nguyen*/
void OutMat(int mat[][MAX], int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) 		//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	/*Tim gia tri lon nhat trong ma tran vuong so nguyen*/
void MaxSquareMatrix(int mat[][MAX], int n) {
	int max = mat[0][0];
	for(int i=0; i<n; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(mat[i][j] > max)
				max = mat[i][j];
	printf("\nGia tri lon nhat ma tran vuong: %d", max);
}
