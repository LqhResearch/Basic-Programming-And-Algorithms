#include<stdio.h>

#define MAX 50
/*
	Dem so luong gia tri "Yen ngua" trong ma tran
*/
void OutMat(int mat[][MAX], int m, int n);
void InpMat(int mat[][MAX], int &m, int &n);
void CountYenNgua(int mat[][MAX], int &m, int &n);

int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	CountYenNgua(mat, m, n);
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

int MaxDong(int mat[][MAX], int dong, int n) {
	int max = mat[dong][0];
	for(int j=0; j<n; j++)
		if(mat[dong][j] > max)
			max = mat[dong][j];
	return max;
}

int MinCot(int mat[][MAX], int cot, int m) {
	int min = mat[0][cot];
	for(int i=0; i<m; i++)
		if(mat[i][cot] < min)
			min = mat[i][cot];
	return min;
}

	//Dem so luong gia tri "Yen ngua" trong ma tran
void CountYenNgua(int mat[][MAX], int &m, int &n) {
	int count = 0;
	for(int i=0; i<m; i++)		//So dong
		for(int j=0; j<n; j++)		//So cot
			if(MaxDong(mat, i, n) == MinCot(mat, j, m)) {
				count++;
				printf("%5d", mat[i][j]);
			}
	if(count == 0)	printf("\nKhong tim thay diem yen ngua");
	else printf("\nMa tran co chua %d diem yen ngua", count);			
}
