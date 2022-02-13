#include<stdio.h>

#define MAX 50
/*
	Dem cac gia tri duong tren duong cheo chinh cua ma tran vuong so thuc
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void CountSoDuong(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	CountSoDuong(mat, n);
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

	/*Dem cac gia tri duong tren duong cheo chinh cua ma tran vuong so thuc*/
void CountSoDuong(float mat[][MAX], int n) {
	int count=0;
	for(int i=0; i<n; i++)
		if(mat[i][i] > 0)	//Duong cheo chinh
			count++;
	if(count==0) printf("\nKhong co gia tri duong tren duong cheo chinh");
	else printf("\n%d gia tri duong tren duong cheo chinh", count);	
}

