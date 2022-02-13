#include<stdio.h>

#define MAX 50
/*
	Tim gia tri am lon nhat trong ma tran
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void MaxSoAm(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	MaxSoAm(mat, m, n);
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

	//Gia tri am lon nhat trong ma tran
void MaxSoAm(int mat[][MAX], int m, int n) {
	int maxAm = 0; //Gia tri mac dinh
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 	//So cot
			if(mat[i][j]<0 && (mat[i][j]>maxAm || maxAm==0))
				maxAm=mat[i][j];
	if(maxAm == 0) printf("\nMa tran khong chua gia tri am");
	else printf("\nGia tri am lon nhat la %d", maxAm);
}
