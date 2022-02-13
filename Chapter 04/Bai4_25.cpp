#include<stdio.h>

#define MAX 50
/*
	Dem so chu so trong ma tran so nguyen duong
*/
void OutMat(int mat[][MAX], int m, int n);
void InpMat(int mat[][MAX], int &m, int &n);
int DemChuSo(int n);
void DemChuSoMat(int mat[][MAX], int &m, int &n);


int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	DemChuSoMat(mat, m, n);
	return 0;
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

	//Dem chu so cua 1 phan tu trong ma tran
int DemChuSo(int n) {
	int count = 0;
	while(n != 0) {
		count++;
		n/=10;
	}
	return count;
}

	//Dem so chu so trong ma tran so nguyen duong
void DemChuSoMat(int mat[][MAX], int &m, int &n) {
	int count = 0;
	for(int i=0; i<m; i++)		//So dong
		for(int j=0; j<n; j++)		//So cot
			count+=DemChuSo(mat[i][j]);
	printf("\nMa tran co chua %d chu so", count);
}
