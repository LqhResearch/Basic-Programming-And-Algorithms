#include<stdio.h>

#define MAX 50
/*
	Bien doi ma tran bang cac thay cac gia tri am bang tri tuyet doi cua no.
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

	//Thay cac gia tri am bang tri tuyet doi cua no
void TriTuyetDoi(int mat[][MAX], int m, int n) {
	for(int i=0; i<m; i++)	//So dong
		for(int j=0; j<n; j++)	//So cot
			if(mat[i][j] < 0)
				mat[i][j]=-mat[i][j];
	printf("Sau khi thay gia tri am bang tri tuyet doi\n");
	OutMat(mat, m, n);
}

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	TriTuyetDoi(mat, m, n);
	return 0;
}

