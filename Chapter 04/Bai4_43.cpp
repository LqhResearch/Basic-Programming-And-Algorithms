#include<stdio.h>

#define MAX 50
/*
	Tim gia tri duong nho nhat va dem so luong trong ma tran so thuc
*/
void InpMat(float mat[][MAX], int &m, int &n);
void OutMat(float mat[][MAX], int m, int n);
void MinDuong(float mat[][MAX], int m, int n);
void CountMinDuong(float mat[][MAX], int m, int n, int minDuong);

	//Chuong trinh chinh
int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	MinDuong(mat, m, n);
	return 0;
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

	//Xuat ma tran so thuc
void OutMat(float mat[][MAX], int m, int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			printf("%f\t", mat[i][j]);
		printf("\n");
	}
}

	//Tim gia tri duong nho nhat trong ma tran so thuc
void MinDuong(float mat[][MAX], int m, int n) {
	float minDuong = 0; //Khoi tao gia tri mac dinh
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(mat[i][j]>0 && (mat[i][j]<minDuong || minDuong==0))
				minDuong=mat[i][j];
	if(minDuong==0) printf("\nMa tran khong chua gia tri duong");
	else {
		printf("\nGia tri duong nho nhat: %f", minDuong);
		CountMinDuong(mat, m, n, minDuong);
	}
}

	//Dem so luong gia tri min duong
void CountMinDuong(float mat[][MAX], int m, int n, int min) {
	int count = 0;
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(mat[i][j] == min)
				count++;
	printf(" xuat hien %d lan", count);
}
