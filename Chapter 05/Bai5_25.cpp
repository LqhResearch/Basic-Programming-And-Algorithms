#include<stdio.h>

#define MAX 50
/*
	Dem so dong giam trong ma tran
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void CountDongGiam(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	CountDongGiam(mat, n);
	return 0;
}

	/*Nhap ma tran vuong so thuc*/
void InpMat(float mat[][MAX], int &n) {
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
			scanf("%f", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat, n);
}

	/*Xuat ma tran vuong so thuc*/
void OutMat(float mat[][MAX], int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) 		//So cot
			printf("%f\t", mat[i][j]);
		printf("\n");
	}
}

	/*Kiem tra dong co giamdan hay khong*/
bool GiamDan(float mat[][MAX], int n, int row) {
	for(int j=1; j<n; j++)	//Duyet cot
		if(mat[row][j-1] < mat[row][j])
			return false;
	return true;
}

	/*Dem so dong giam trong ma tran*/
void CountDongGiam(float mat[][MAX], int n) {
	int count=0;
	for(int i=0; i<n; i++) 	//So dong
		if(GiamDan(mat, n, i) == true)
			count++;
	if(count==0) printf("\nKhong co dong giam dan");
	else printf("\n%d dong giam dan", count);
}
