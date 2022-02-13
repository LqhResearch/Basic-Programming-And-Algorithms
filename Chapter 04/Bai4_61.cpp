#include<stdio.h>

#define MAX 50
/*
	Hoan vi hai dong cua ma tran
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void Swap(int &a, int &b);
void SwapTwoColumn(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	SwapTwoColumn(mat, m, n);
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

	//Hoan vi 2 gia tri
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

	//Hoan vi hai dong cua ma tran
void SwapTwoColumn(int mat[][MAX], int m, int n) {
	int first, last;
	do{
		printf("\nNhap dong can hoan vi: ");
		scanf("%d", &first);
		if(first<0 || first>=m)
			printf("\nDong nay khong ton tai");
	}while(first<0 || first>=m);
	
	do{
		printf("\nNhap dong bi hoan vi: ");
		scanf("%d", &last);
		if(last<0 || last>=m)
			printf("\nDong nay khong ton tai");
	}while(last<0 || last>=m);
	
	//Hoan vi 2 dong
	for(int j=0; j<n; j++)	//Duyet cot
		Swap(mat[first][j], mat[last][j]);
	
	printf("\nSau khi hoan vi: \n");
	OutMat(mat, m, n);
}

