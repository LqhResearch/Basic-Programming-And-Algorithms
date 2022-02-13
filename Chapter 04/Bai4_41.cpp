#include<stdio.h>

#define MAX 50
/*
	Tim gia tri lon nhat tren mot dong cua ma tran so thuc
*/
void InpMat(float mat[][MAX], int &m, int &n);
void OutMat(float mat[][MAX], int m, int n);
void MaxDong(float mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	MaxDong(mat, m, n);
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

	//Max cua dong
void MaxDong(float mat[][MAX], int m, int n) {
	int row;
	do{
		printf("\nNhap dong can tim: ");
		scanf("%d", &row);
		if(row<0 || row>=m)
			printf("\nDong nay khong ton tai");
	}while(row<0 || row>=m);
	
	float max=mat[row][0];
	for(int j=1; j<n; j++) 	//So cot
		if(mat[row][j] > max)
			max=mat[row][j];
	printf("\nGia tri lon nhat cua dong %d: %f", row, max);
}
