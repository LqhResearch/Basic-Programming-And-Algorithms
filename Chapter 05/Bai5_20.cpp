#include<stdio.h>

#define MAX 50
/*
	Dua cac gia tri chan ve dau ma tran vuong
*/
void InpMat(int mat[][MAX], int &n);
void OutMat(int mat[][MAX], int n);
void ChangeSoChan(int mat[][MAX], int n);

	/*Main function*/
int main() {
	int mat[MAX][MAX], n;
	InpMat(mat, n);
	
	ChangeSoChan(mat, n);
	return 0;
}

	/*Nhap ma tran vuong so nguyen*/
void InpMat(int mat[][MAX], int &n) {
	do{
		printf("Nhap so dong = ");
		scanf("%d", &n);
		if(n<=0)
			printf("So dong phai lon hon 0\n");
	}while(n<=0);
	
	printf("\n===Nhap ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) {	//So cot
			printf("Phan tu thu [%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, n);
}

	/*Xuat ma tran vuong so nguyen*/
void OutMat(int mat[][MAX], int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) 		//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	/*Hoan vi 2 so thuc*/
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

	/*Dua cac gia tri chan ve dau ma tran vuong*/
void ChangeSoChan(int mat[][MAX], int n) {
	int vt=0;
	for(int i=0; i<n; i++) 	//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(mat[i][j]%2==0) {
				if(mat[vt/n][vt%n]%2==0)
					vt++;
				else {
					Swap(mat[vt/n][vt%n], mat[i][j]);
					vt++;
				}
			}
	OutMat(mat, n);
}
