#include<stdio.h>

#define MAX 50
/*
	Sap xep cac phan tu am tang dan, cac phan tu duong giam dan va cac gia tri 0 giu nguyen vi tri.
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

	//Hoan vi 2 so
void Swap(int &a, int &b) {
	int temp=a;
	a=b;
	b=temp;
}

	//Sap xep ma tran
void SortMat(int mat[][MAX], int m, int n) {
	int allCell=m*n;
	for(int i=0; i<allCell; i++)
		for(int j=i+1; j<allCell; j++) {
			if(mat[i/n][i%n]<0 && mat[j/n][j%n]<0)	//Sap xep so am tang dan
				if(mat[i/n][i%n] > mat[j/n][j%n])
					Swap(mat[i/n][i%n], mat[j/n][j%n]);
					
			if(mat[i/n][i%n]>0 && mat[j/n][j%n]>0) 	//Sap xep so duong giam dan
				if(mat[i/n][i%n] < mat[j/n][j%n])
					Swap(mat[i/n][i%n], mat[j/n][j%n]);
		}
	OutMat(mat, m, n);
}

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	SortMat(mat, m, n);
	return 0;
}

