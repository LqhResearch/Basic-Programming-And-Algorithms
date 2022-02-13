#include<stdio.h>

#define MAX 50
/*
	Liet ke cac cot co tong dong nho nhat trong ma tran so thuc
*/
void InpMat(float mat[][MAX], int &m, int &n);
void OutMat(float mat[][MAX], int m, int n);
void Listed(float mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	Listed(mat, m, n);
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
	
	//Tim tong cua cac cot co gia tri nho nhat?
float TongMinCot(float mat[][MAX], int m, int n) {
	float min;
	for(int j=0; j<n; j++) {	//So dot
		float tong = 0;
		for(int i=0; i<m; i++) 	//So dong
			tong+=mat[i][j];
		if(tong < min || j==0)
			min = tong;
	}
	return min;
}

bool TestTongCot(float mat[][MAX], int m, int n, int col, float min) {
	float tong = 0;
	for(int i=0; i<m; i++) 	//Duyet hang
		tong+=mat[i][col];
	if(tong == min)	return true;
	else return false;
}

	//Liet ke cac cot co tong dong nho nhat trong ma tran so thuc
void Listed(float mat[][MAX], int m, int n) {
	float min = TongMinCot(mat, m, n);
	printf("\nChi so cot co tong nho nhat: ");
	for(int j=0; j<n; j++)		//Duyet cot
		if(TestTongCot(mat, m, n, j, min) == true)
			printf("%5d", j);
}
