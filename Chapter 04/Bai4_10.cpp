#include<stdio.h>

#define MAX 50
/*
	Trung binh cong cua cac so duong trong ma tran so thuc
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

	//Trung binh cong cua cac so duong
float TrungBinhCongDuong(float mat[][MAX], int m, int n) {
	float tbc=0;
	int count=0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(mat[i][j]>0) {
				tbc+=mat[i][j];
				count++;
			}
	return tbc/count;
}

int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	printf("Trung binh cong cua cac gia tri duong trong ma tran = %f", TrungBinhCongDuong(mat, m, n));
	return 0;
}

