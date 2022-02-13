#include<stdio.h>

#define MAX 50
/*
	Tim gia tri nho nhat trong tam giac tren duong cheo chinh
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void MinTGTren(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	MinTGTren(mat, n);
	return 0;
}

	/*Nhap ma tran vuong so thuc*/
void InpMat(float mat[][MAX], int &n) {
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
			scanf("%f", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, n);
}

	/*Xuat ma tran vuong so thuc*/
void OutMat(float mat[][MAX], int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) 		//So cot
			printf("%f\t", mat[i][j]);
		printf("\n");
	}
}

	/*Tim gia tri nho nhat trong tam giac tren duong cheo chinh*/
void MinTGTren(float mat[][MAX], int n) {
	float max = mat[0][1];
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++)
			if(i<j && mat[i][j] < max)
				max = mat[i][j];
	printf("\nGia tri nho nhat tren duong cheo chinh: %f", max);
}
