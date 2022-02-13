#include<stdio.h>

#define MAX 100
/*
	Kiem tra ma tran co toan duong hay khong?
*/
void OutMat(int mat[][MAX], int m, int n);
void InpMat(int mat[][MAX], int &m, int &n);
bool TestToanDuong(int mat[][MAX], int m, int n);

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	if(TestToanDuong(mat, m, n) == true)
		printf("\nMa tran co toan duong");
	else printf("\nMa tran khong toan duong");
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

	//Kiem tra ma tran co toan duong hay khong?
bool TestToanDuong(int mat[][MAX], int m, int n) {
	bool flag = false;
	int count = 0;
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(mat[i][j] > 0)
				count++;
	if(count == m*n) flag = true;
	return flag;
}
