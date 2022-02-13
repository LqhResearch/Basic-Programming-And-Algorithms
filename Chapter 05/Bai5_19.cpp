#include<stdio.h>

#define MAX 50
/*
	Sap xep cac dong tang dan theo tong cua dong
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void SapXepDong(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	SapXepDong(mat, n);
	return 0;
}

	/*Nhap ma tran vuong so thuc*/
void InpMat(float mat[][MAX], int &n) {
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
			scanf("%f", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, n);
}

	/*Xuat ma tran vuong so thuc*/
void OutMat(float mat[][MAX], int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) 		//So cot
			printf("%f\t", mat[i][j]);
		printf("\n");
	}
}

	/*Hoan vi 2 so thuc*/
void Swap(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

void SwapRow(float mat[][MAX], int n, int row1, int row2) {
	for(int j=0; j<n; j++)
		Swap(mat[row1][j], mat[row2][j]);
}

	/*Tong cua mot dong*/
float SumDong(float mat[][MAX], int n, int row) {
	float sum = 0;
	for(int j=0; j<n; j++)
		sum+=mat[row][j];
	return sum;
}

	/*Sap xep cac dong tang dan theo tong cua dong*/
void SapXepDong(float mat[][MAX], int n) {
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(SumDong(mat, n, i) > SumDong(mat, n, j))
				SwapRow(mat, n, i, j);
	OutMat(mat, n);
}
