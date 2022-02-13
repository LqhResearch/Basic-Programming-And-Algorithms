#include<stdio.h>

#define MAX 50
/*
	Viet ham sap xep cac phan tu ma tran theo yeu cau sau:
	-	Cot co chi so chan giam dan
	-	Cot co chi so le tang dan
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

	//Hoan vi 2 so
void Swap(int &a, int &b) {
	int temp=a;
	a=b;
	b=temp;
}

	//Sap xep
void SortOfRow(int mat[][MAX], int m, int n, int cot) {
	if(cot%2==0) {		//Sap xep dong co chi so chan giam dan
		for(int i=0; i<m; i++)
			for(int k=i+1; k<m; k++)
				if(mat[i][cot] < mat[k][cot])
					Swap(mat[i][cot], mat[k][cot]);	
	}
	else{	//Sap xep dong co chi so le tang dan
		for(int i=0; i<m; i++)
			for(int k=i+1; k<m; k++)
				if(mat[i][cot] > mat[k][cot])
					Swap(mat[i][cot], mat[k][cot]);	
	}		
}

	//Sap xep ma tran
void SortMat(int mat[][MAX], int m, int n) {
	for(int j=0; j<n; j++)
		SortOfRow(mat, m, n, j);
	OutMat(mat, m, n);
}

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	SortMat(mat, m, n);
	return 0;
}

