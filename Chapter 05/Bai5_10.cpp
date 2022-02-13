#include<stdio.h>

#define MAX 50
/*
	Tong cac phan tu chan nam tren bien cua ma tran vuong so thuc
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void SumBienSoChan(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	SumBienSoChan(mat, n);
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

	/*Tong cac phan tu chan nam tren bien cua ma tran vuong so thuc*/
void SumBienSoChan(float mat[][MAX], int n) {
	float sum = 0;
	for(int i=0; i<n; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(i==0 || j==0 || i==n-1 || j==n-1)	//Bien cua ma tran vuong
				sum+=mat[i][j];
	printf("\nTong cac phan tu trong bien: %f", sum);
}
