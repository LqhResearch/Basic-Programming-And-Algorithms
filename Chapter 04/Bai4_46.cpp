#include<stdio.h>

#define MAX 50
/*
	Tim ma tran con co tong lon nhat trong ma tran
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void SearchChildMatrix(int mat[][MAX], int m, int n);
void OutChildMat(int mat[][MAX], int startRow, int startCol, int endRow, int endCol);
int SumChildMat(int mat[][MAX], int startRow, int startCol, int endRow, int endCol);
int MaxChildMatrix(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	SearchChildMatrix(mat, m, n);
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

	/*Tim ma tran con co tong lon nhat trong ma tran*/
void SearchChildMatrix(int mat[][MAX], int m, int n) {
	printf("\nMa tran con co tong lon nhat: ");
	int maxMat = MaxChildMatrix(mat, m, n);
	for(int i=1; i<=m; i++) 		//So phan tu cua dong
		for(int j=1; j<=n; j++) 		//So phan tu so cot
			for(int k=0; k<=m-i; k++) 		//So dong
				for(int l=0; l<=n-j; l++) 		//So cot
				{
					int sum = SumChildMat(mat, k, l, k+i-1, l+j-1);
					if(sum == maxMat)
						OutChildMat(mat, k, l, k+i-1, l+j-1);
				}
}

	/*Xuat ma tran con*/
void OutChildMat(int mat[][MAX], int startRow, int startCol, int endRow, int endCol) {
	printf("\nMa tran con: \n");
	for(int i=startRow; i <= endRow; i++) {
		for(int j=startCol; j<=endCol; j++)
			printf("%5d", mat[i][j]);
		printf("\n");
	}
		
}

	/*Tong ma tran con*/
int SumChildMat(int mat[][MAX], int startRow, int startCol, int endRow, int endCol) {
	int sum = 0;
	for(int i=startRow; i <= endRow; i++)
		for(int j=startCol; j<=endCol; j++)
			sum+=mat[i][j];
	return sum;	
}

	/*Tim max cua ma tran con*/
int MaxChildMatrix(int mat[][MAX], int m, int n) {
	int max, count=0;
	for(int i=1; i<=m; i++) 		//So phan tu cua dong
		for(int j=1; j<=n; j++) 		//So phan tu so cot
			for(int k=0; k<=m-i; k++) 		//So dong
				for(int l=0; l<=n-j; l++) 		//So cot
				{
					int sum = SumChildMat(mat, k, l, k+i-1, l+j-1);
					if(sum > max || count == 0) {
						max = sum;
						count++;
					}
				}
	return max;
}
