#include<stdio.h>

#define MAX 50
/*
	Dem cac cap gia tri doi xung qua duong cheo chinh
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void CountCapDoiXung(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	CountCapDoiXung(mat, n);
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

	/*Dem cac cap gia tri doi xung qua duong cheo chinh*/
void CountCapDoiXung(float mat[][MAX], int n) {
	int count=0;
	for(int i=0; i<n; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(i>j && i!=j && mat[i][j] == mat[j][i])
				count++;
	if(count==0) printf("\nKhong co cap doi xung");
	else printf("\n%d cap doi xung", count);
}
