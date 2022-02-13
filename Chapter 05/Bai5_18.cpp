#include<stdio.h>

#define MAX 50
/*
	Sap xep cac phan tu tren duong cheo phu giam dan
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void SapXepDuongCheoPhu(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	SapXepDuongCheoPhu(mat, n);
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

	/*Hoan vi 2 so thuc*/
void Swap(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

	/*Sap xep cac phan tu tren duong cheo phu giam dan*/
void SapXepDuongCheoPhu(float mat[][MAX], int n) {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(mat[i][i] < mat[j][j])
				Swap(mat[i][n-i-1], mat[j][n-j-1]);		//Duong cheo phu
	OutMat(mat, n);
}
