#include<stdio.h>

#define MAX 50
/*
	Kiem tra mot hang cua ma tran co tang dan hay khong?
*/
void OutMat(int mat[][MAX], int m, int n);
void InpMat(int mat[][MAX], int &m, int &n);
bool TestHangTangDan(int mat[][MAX], int m, int n, int &k);

int main() {
	int mat[MAX][MAX], m, n, k;
	InpMat(mat, m, n);
	
	if(TestHangTangDan(mat, m, n, k) == true)
		printf("\nHang %d tang dan", k);
	else printf("\nHang %d khong tang dan", k);
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

	//Kiem tra mot hang cua ma tran co tang dan hay khong?
bool TestHangTangDan(int mat[][MAX], int m, int n, int &k) {
	bool flag = true;
	printf("\nNhap hang: ");
	scanf("%d", &k);
	for(int j=1; j<n; j++) 		//So cot
		if(mat[k][j-1] > mat[k][j])
			return false;
	return flag;
}

