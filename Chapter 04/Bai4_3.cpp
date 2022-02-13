#include<stdio.h>

#define MAX 50
/*
	Ham tim gia tri lon nhat trong ma tran so nguyen
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

int MaxMat(int mat[][MAX], int m, int n) {
	int max=mat[0][0];
	for(int i=0; i<m; i++) 
		for(int j=0; j<n; j++) 
			if(mat[i][j]>max)
				max=mat[i][j];
	return max;
}

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	printf("Gia tri lon nhat cua ma tran = %d", MaxMat(mat, m, n));
	return 0;
}

