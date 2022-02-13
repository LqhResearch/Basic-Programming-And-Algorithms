#include<stdio.h>

#define MAX 50
/*
	Tim gia tri lon thu nhi trong ma tran so nguyen
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void TheSecondMax(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	TheSecondMax(mat, m, n);
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
		for(int j=0; j<n; j++) 		//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	//Tim gia tri lon thu nhi trong ma tran
void TheSecondMax(int mat[][MAX], int m, int n) {
	int max, secondMax;
	if(m*n == 1) printf("\nMa tran khong co gia tri lon nhi");	//Kiem tra
	max = (mat[0][0] > mat[0][1]) ? mat[0][0] : mat[0][1];	//Gan max
	secondMax = (mat[0][0] < mat[0][1]) ? mat[0][0] : mat[0][1];	//Gan secondMax
	
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(mat[i][j] > max) {
				secondMax = max; //Gan secondMax
				max = mat[i][j]; //Gan max
			}
	if(m*n != 1) printf("\nGia tri lon thu nhi la %d", secondMax);
}

