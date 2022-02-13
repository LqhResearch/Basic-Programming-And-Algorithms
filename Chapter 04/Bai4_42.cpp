#include<stdio.h>

#define MAX 50
/*
	Tim gia tri nho nhat tren mot cot cua ma tran so thuc
*/
void InpMat(float mat[][MAX], int &m, int &n);
void OutMat(float mat[][MAX], int m, int n);
void MinCot(float mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	MinCot(mat, m, n);
	return 0;
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

	//Xuat ma tran so thuc
void OutMat(float mat[][MAX], int m, int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			printf("%f\t", mat[i][j]);
		printf("\n");
	}
}

	//Min cua cot
void MinCot(float mat[][MAX], int m, int n) {
	int column;
	do{
		printf("\nNhap cot can tim: ");
		scanf("%d", &column);
		if(column<0 || column>=n)
			printf("\nCot nay khong ton tai");
	}while(column<0 || column>=n);
	
	float min=mat[0][column];
	for(int i=1; i<m; i++) 	//So cot
		if(mat[i][column] < min)
			min=mat[i][column];
	printf("\nGia tri nho nhat cua cot %d: %f", column, min);
}
