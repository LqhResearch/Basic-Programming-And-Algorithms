#include<stdio.h>

#define MAX 50
/*
	Tinh tich hai ma tran vuong
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void MultiplyMatrix(float mat1[][MAX], float mat2[][MAX], int n1, int n2);

	/*Main funtion*/
int main() {
	int n1, n2;
	float mat1[MAX][MAX], mat2[MAX][MAX];
	InpMat(mat1, n1);
	InpMat(mat2, n2);
	
	MultiplyMatrix(mat1, mat2, n1, n2);
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

	/*Tich mot phan tu tai vi tri bat ki cua ma tran*/
float MultiplyElement(float mat1[][MAX], float mat2[][MAX], int n1, int n2, int row, int col) {
	float sum = 0;
	for(int i=0; i<n1; i++)
		sum+=(mat1[row][i] * mat2[i][col]);
	return sum;	
}

	/*Tinh tich hai ma tran vuong*/
void MultiplyMatrix(float mat1[][MAX], float mat2[][MAX], int n1, int n2) {
	float multi[MAX][MAX];
	for(int i=0; i<n1; i++) 		//So dong
		for(int j=0; j<n1; j++) 		//So cot
			multi[i][j] = MultiplyElement(mat1, mat2, n1, n2, i, j);
	printf("\nTich hai ma tran A x B: \n");
	OutMat(multi, n1);
}
