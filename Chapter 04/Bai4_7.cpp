#include<stdio.h>

#define MAX 50
/*
	Tinh tong cac gia tri tren cung mot dong ma tran so thuc
*/
	//Xuat ma tran so thuc
void OutMat(float mat[][MAX], int m, int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			printf("%f\t", mat[i][j]);
		printf("\n");
	}
}

	//Nhap ma tran so thuc
void InpMat(float mat[][MAX], int &m, int &n) {
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
			scanf("%f", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, m, n);
}

	//Tong cac gia tri tren cung mot dong
void TongDong(float mat[][MAX], int &m, int &n) {
	for(int i=0; i<m; i++) {
		int tong=0;
		for(int j=0; j<n; j++)
			tong+=mat[i][j];
		printf("\nDong %d = %d", i, tong);
	}
}

int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	TongDong(mat, m, n);
	return 0;
}

