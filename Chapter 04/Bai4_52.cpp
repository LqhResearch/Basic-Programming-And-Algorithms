#include<stdio.h>
#include<math.h>

#define MAX 50
/*
	Liet ke cac cot trong ma tran co chua so chinh phuong
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void Listed(int mat[][MAX], int m, int n);

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	Listed(mat, m, n);
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
		for(int j=0; j<n; j++) 	//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	//Kiem tra co phai la so chinh phuong hay khong?
bool CheckSCP(int n) {
	int tmp = sqrt(n);
	if(tmp*tmp == n) return true;
	else return false;
}

	//Kiem tra so chinh phuong cua cot
bool CheckSNTDong(int mat[][MAX], int m, int n, int col) {
	for(int i=0; i<m; i++)	//Duyet dong
		if(CheckSCP(mat[i][col]) == true)
			return true;
	return false;
}

	//Liet ke cac cot trong ma tran co chua so chinh phuong
void Listed(int mat[][MAX], int m, int n) {
	printf("\nChi so cot chua so chinh phuong: ");
	for(int j=0; j<n; j++) 	//So cot
		if(CheckSNTDong(mat, m, n, j) == true)
			printf("%5d", j);
}


