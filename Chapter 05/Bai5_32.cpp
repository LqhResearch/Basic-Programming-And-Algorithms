#include<stdio.h>

#define MAX 50
/*
	Kiem tra ma tran co phai la ma phuong bac n khong?
*/
void InpMat(int mat[][MAX], int &n);
void OutMat(int mat[][MAX], int n);
void TestMaPhuong(int mat[][MAX], int n);

	/*Main function*/
int main() {
	int mat[MAX][MAX], n;
	InpMat(mat, n);
	
	TestMaPhuong(mat, n);
	return 0;
}

	/*Nhap ma tran vuong so nguyen*/
void InpMat(int mat[][MAX], int &n) {
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
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, n);
}

	/*Xuat ma tran vuong so nguyen*/
void OutMat(int mat[][MAX], int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) 		//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	/*Sum dong*/
int SumDong(int mat[][MAX], int n, int row) {
	int sum=0;
	for(int j=0; j<n; j++)
		sum+=mat[row][j];
	return sum;
}

	/*Sum cot*/
int SumCot(int mat[][MAX], int n, int col) {
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=mat[i][col];
	return sum;
}

	/*Kiem tra ma tran co phai la ma phuong bac n khong?*/
void TestMaPhuong(int mat[][MAX], int n) {
	int count = 0, sum;		//Dem gia tri bang nhau giua dong, cot, duong cheo
	int value = SumDong(mat, n, 0);
	
	for(int i=0; i<n; i++) 		//So dong
		if(value == SumDong(mat, n, i))
			count++;

	for(int j=0; j<n; j++) 		//So cot
		if(value == SumCot(mat, n, j))
			count++;

	sum = 0;		//Duong cheo chinh
	for(int i=0; i<n; i++)
		sum+=mat[i][i];
	if(value == sum) count++;

	sum = 0;		//Duong cheo phu
	for(int i=0; i<n; i++)
		sum+=mat[i][n-i-1];
	if(value == sum) count++;

	if(count == 2*n+2) printf("\nMa tran la ma phuong bac %d", n);
	else printf("\nMa tran khong phai la ma phuong bac %d", n);
}
