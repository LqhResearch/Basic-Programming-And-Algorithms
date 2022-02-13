#include<stdio.h>

#define MAX 50
/*
	Tim gia tri lon nhat, nho nhat cua trong duong cheo phu cua ma tran vuong so thuc
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void MaxDCP(float mat[][MAX], int n);
void MinDCP(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	MaxDCP(mat, n);
	MinDCP(mat, n);
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

	/*Tim gia tri lon nhat cua trong duong cheo phu cua ma tran vuong so thuc*/
void MaxDCP(float mat[][MAX], int n) {
	float max = mat[n-1][0];
	for(int i=0; i<n; i++)
		if(mat[i][n-i-1] > max)
			max = mat[i][n-i-1];
	printf("\nGia tri lon nhat trong duong cheo phu: %f", max);
}

	/*Tim gia tri nho nhat cua trong duong cheo phu cua ma tran vuong so thuc*/
void MinDCP(float mat[][MAX], int n) {
	float min = mat[n-1][0];
	for(int i=0; i<n; i++)
		if(mat[i][n-i-1] < min)
			min = mat[i][n-i-1];
	printf("\nGia tri nho nhat trong duong cheo phu: %f", min);
}
