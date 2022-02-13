#include<stdio.h>

#define MAX 50
/*
	Liet ke cac dong trong ma tran so thuc dong thoi thoa cac dieu kien sau:
	+	Chua gia tri duong
	+	Chua gia tri am
	+	Chua gia tri 0 (phan tu trung hoa)
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

	//Kiem tra so duong
bool TestSoDuong(float mat[][MAX], int m, int n, int row) {
	for(int j=0; j<n; j++)	//Duyet cot
		if(mat[row][j] > 0)
			return true;
	return false;
}

	//Kiem tra so am
bool TestSoAm(float mat[][MAX], int m, int n, int row) {
	for(int j=0; j<n; j++)	//Duyet cot
		if(mat[row][j] < 0)
			return true;
	return false;
}

	//Kiem tra gia tri 0
bool TestSo0(float mat[][MAX], int m, int n, int row) {
	for(int j=0; j<n; j++)	//Duyet cot
		if(mat[row][j] == 0)
			return true;
	return false;
}


	//Liet ke
void Listed(float mat[][MAX], int m, int n) {
	printf("\nChi so dong co chua so duong, am va 0: ");
	for(int i=0; i<m; i++)	//Duyet hang
		if(TestSoDuong(mat, m, n, i) == true && TestSoAm(mat, m, n, i) == true && TestSo0(mat, m, n, i) == true)
			printf("%5d", i);
}
