#include<stdio.h>

#define MAX 50
/*
	Dem tan suat xuat hien trong ma tran so thuc
*/
void OutMat(float mat[][MAX], int m, int n);
void InpMat(float mat[][MAX], int &m, int &n);
void DemXXuatHien(float mat[][MAX], int m, int n);

int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	DemXXuatHien(mat, m, n);
	return 0;
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

bool TestSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)
			count++;
	if(count==2) return true;
	else return false;
}

	//Dem tan suat xuat hien trong ma tran so thuc
void DemXXuatHien(float mat[][MAX], int m, int n) {
	int count = 0;
	float x;
	printf("\nNhap gia tri can tim: ");
	scanf("%f", &x);
	for(int i=0; i<m; i++)		//So dong
		for(int j=0; j<n; j++)		//So cot
			if(mat[i][j] == x)
				count++;
	if(count == 0)	printf("\nKhong tim thay gia tri x trong ma tran");
	else printf("\nMa tran co chua %d gia tri %f", count, x);
}

