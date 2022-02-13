#include<stdio.h>

#define MAX 50
/*
	Tinh tong cac phan tu thuoc tam giac tren (khong tinh duong cheo chinh) cua ma tran vuong so thuc
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void SumTamGiacTren(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	SumTamGiacTren(mat, n);
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

	/*Tinh tong cac phan tu thuoc tam giac tren cua ma tran vuong so thuc*/
void SumTamGiacTren(float mat[][MAX], int n) {
	float sum = 0;
	for(int i=0; i<n; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(j > i)	//Tam giac tren duong cheo chinh
				sum+=mat[i][j];
printf("\nTong cac phan tu trong ma tran tren: %f", sum);
}
