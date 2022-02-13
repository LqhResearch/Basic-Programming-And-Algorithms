#include<stdio.h>

#define MAX 50
/*
	Tim chu so xuat hien nhieu nhat trong ma tran so nguyen
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void SearchNumber(int mat[][MAX], int m, int n);
int chuSo[10];

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	SearchNumber(mat, m, n);
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

	//Khoi tao gia tri mac dinh cho mang
void DefaultArray() {
	for(int i=0; i<10; i++)
		chuSo[i] = 0;
}

	//Dem chu so cua ma tran
void CountNum(int n) {
	while(n!=0) {
		chuSo[n%10]++;
		n/=10;
	}
}

	//Tim max cua chu so
void MaxChuSo() {
	int max = 0;
	for(int i=0; i<10; i++)
		if(chuSo[i] > max)
			max = chuSo[i];
	
	for(int i=0; i<10; i++)
		if(chuSo[i] == max)
			printf("\nChu so xuat hien nhieu nhat la %d", i);
}

	//Tim chu so xuat hien nhieu nhat trong ma tran so nguyen
void SearchNumber(int mat[][MAX], int m, int n) {
	DefaultArray();
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			CountNum(mat[i][j]);
	MaxChuSo();
}

