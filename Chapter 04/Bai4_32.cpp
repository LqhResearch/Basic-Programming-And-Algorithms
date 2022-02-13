#include<stdio.h>

#define MAX 100
/*
	Kiem tra ma tran co ton tai so duong hay khong?
*/
void OutMat(int mat[][MAX], int m, int n);
void InpMat(int mat[][MAX], int &m, int &n);
bool TestSoDuong(int mat[][MAX], int m, int n);

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	if(TestSoDuong(mat, m, n) == true)
		printf("\nMa tran co ton tai so duong");
	else printf("\nMa tran khong ton tai so duong");
	return 0;
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

	//Kiem tra ma tran co ton tai so duong hay khong?
bool TestSoDuong(int mat[][MAX], int m, int n) {
	bool flag = false;
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(mat[i][j] > 0) {
				flag = true;
				break;
			}
	return flag;
}
