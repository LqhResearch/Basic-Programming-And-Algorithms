#include<stdio.h>

#define MAX 50
/*
	Dem so luong so nguyen to trong ma tran vuong so nguyen?
*/
void InpMat(int mat[][MAX], int &n);
void OutMat(int mat[][MAX], int n);
void CountSNT(int mat[][MAX], int n);

	/*Main function*/
int main() {
	int mat[MAX][MAX], n;
	InpMat(mat, n);
	
	CountSNT(mat, n);
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

	/*Kiem tra so bat ki co phai la so nguyen to hay khong?*/
bool TestSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)
			count++;
	if(count==2) return true;
	else return false;
}

	/*Dem so luong so nguyen to trong ma tran vuong so nguyen?*/
void CountSNT(int mat[][MAX], int n) {
	int count = 0;
	for(int i=0; i<n; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(TestSNT(mat[i][j]) == true)
				count++;
	if(count == 0) printf("\nMa tran vuong khong chua so nguyen to");
	else printf("\nMa tran vuong co %d so nguyen to", count);
}
