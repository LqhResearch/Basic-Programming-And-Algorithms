#include<stdio.h>

#define MAX 50
/*
	Tim gia tri xuat hien nhieu nhat trong ma tran so thuc
*/
void InpMat(float mat[][MAX], int &m, int &n);
void OutMat(float mat[][MAX], int m, int n);
int CountValue(float mat[][MAX], int m, int n);
void SearchValue(float mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	SearchValue(mat, m, n);
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

	//Dem gia tri bat ki
int CountValue(float mat[][MAX], int m, int n, int k) {
	int count = 0;
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++)		//So cot
			if(mat[i][j] == k)
				count++;
	return count;
}

	//Kiem tra ton tai truoc do
bool CheckExist(float mat[][MAX], int m, int n, int row, int col) {
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) {		//So cot
			if(i==row && j==col)
				return false;
			if(mat[i][j] == mat[row][col])
				return true;
		}
}

	//Tim gia tri xuat hien nhieu nhat trong ma tran so thuc
void SearchValue(float mat[][MAX], int m, int n) {
	//Tim so lan xuat hien nhieu nhat
	int maxCount = 0;
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(CountValue(mat, m, n, mat[i][j]) > maxCount)
				maxCount = CountValue(mat, m, n, mat[i][j]);
	
	//Tim gia tri xuat hien nhieu nhat
	printf("\nGia tri xuat hien nhieu nhat: ");
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(CountValue(mat, m, n, mat[i][j]) == maxCount)
				if(CheckExist(mat, m, n, i, j) == false)
					printf("%f\t", mat[i][j]);
}
