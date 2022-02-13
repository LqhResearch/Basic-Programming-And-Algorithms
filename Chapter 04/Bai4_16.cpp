#include<stdio.h>

#define MAX 50
/*
	Ham xuat cac gia tri chan trong ma tran so nguyen theo thu tu giam dan
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

	//Sap xep giam dan
void GiamDan(int arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i] < arr[j])
			{
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
}

	//Xuat cac gia tri chan giam dan
void SoChanGiamDan(int mat[][MAX], int m, int n) {
	int arr[m*n], viTri=-1;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(mat[i][j]%2==0)
				arr[++viTri]=mat[i][j];
	printf("\nCac gia tri chan giam dan: ");
	GiamDan(arr, viTri+1);
	for(int i=0; i<=viTri; i++)
		printf("%5d", arr[i]);
}

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	SoChanGiamDan(mat, m, n);
	return 0;
}

