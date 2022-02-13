#include<stdio.h>
#include<math.h>

#define MAX 50
/*
	Tim hai gia tri gan nhau nhat
*/
void InpMat(int mat[][MAX], int &n);
void OutMat(int mat[][MAX], int n);
void FindTwoClosestValues(int mat[][MAX], int n);

	/*Main function*/
int main() {
	int mat[MAX][MAX], n;
	InpMat(mat, n);
	
	FindTwoClosestValues(mat, n);
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

	/*Tim khoang cach gan nhau nhat*/
int ClosestDistance(int mat[][MAX], int n) {
	int closest = -1;
	for(int i=0; i<n*n; i++) 	//So dong
		for(int j=i+1; j<n*n; j++) 		//So cot
			if(closest==-1 || closest > abs(mat[i/n][i%n] - mat[j/n][j%n]))
				closest = abs(mat[i/n][i%n] - mat[j/n][j%n]);
	return closest;
}

	/*Tim hai gia tri gan nhau nhat*/
void FindTwoClosestValues(int mat[][MAX], int n) {
	int closest = ClosestDistance(mat, n);
	for(int i=0; i<n*n; i++) 	//So dong
		for(int j=i+1; j<n*n; j++) 		//So cot
			if(abs(mat[i/n][i%n] - mat[j/n][j%n]) == closest)
				printf("\n%5d%5d", mat[i/n][i%n], mat[j/n][j%n]);
}
