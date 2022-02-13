#include<stdio.h>

#define MAX 50
/*
	Tinh tich cac gia tri duong tren cung mot cot cua ma tran so thuc
*/
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

	//Tich cac phan tu duong tren cung mot cot
void TichCot(float mat[][MAX], int &m, int &n) {
	for(int j=0; j<n; j++) {
		int tich=1;
		for(int i=0; i<m; i++)
			if(mat[i][j]>0)
				tich*=mat[i][j];
		printf("\nCot %d = %f", j, tich);
	}
}

int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	TichCot(mat, m, n);
	return 0;
}

