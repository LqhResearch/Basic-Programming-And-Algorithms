#include<stdio.h>

#define MAX 50
/*
	Ma tran vuong cac so nguyen (n >= 3).
	Sap xep cac gia tri trong ma tran tam giac tren (khong tinh duong cheo) tang dan.
*/
void InpMat(int mat[][MAX], int &n);
void OutMat(int mat[][MAX], int n);
void Swap(int &a, int &b);
void TangDan(int mat[][MAX], int n);

	/*Main function*/
int main() {
	int mat[MAX][MAX], n;
	InpMat(mat, n);
	
	TangDan(mat, n);
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

	/*Hoan vi hai so nguyen*/
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

	/*Sap xep cac gia tri trong ma tran tam giac tren (khong tinh duong cheo) tang dan*/
void TangDan(int mat[][MAX], int n) {
	for(int i=0; i<n*n; i++) 		//So dong
		for(int j=i+1; j<n*n; j++) 		//So cot
			if((i/n < i%n) && (j/n < j%n))
				if(mat[i/n][i%n] > mat[j/n][j%n])
					Swap(mat[i/n][i%n], mat[j/n][j%n]);
	
	printf("\nSap xep cac gia tri trong ma tran tam giac tren tang dan: \n");
	OutMat(mat, n);
}

