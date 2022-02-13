#include<stdio.h>

#define MAX 50
/*
	Tinh tong cac so nguyen to trong ma tran so nguyen
*/
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

	//Kiem tra mot so co phai la so nguyen to hay khong?
bool CheckSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)
			count++;
	if(count==2) return true;
	else return false;	
}

	//Tong cac so nguyen to
int TongSNT(int mat[][MAX], int m, int n) {
	int tong=0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(CheckSNT(mat[i][j]) == true)
				tong+=mat[i][j];
	return tong;
}

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	printf("Tong cac so nguyen to trong ma tran = %d", TongSNT(mat, m, n));
	return 0;
}

