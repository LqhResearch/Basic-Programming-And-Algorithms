#include<stdio.h>

#define MAX 50
/*
	Cho hai ma tran A va B. Kiem tra xem ma tran A co la con cua ma tran B hay khong?
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void TestTwoMatrix();
bool TestChildMatrix(int startRow, int startCol, int endRow, int endCol);
int mat1[MAX][MAX], m1, n1;
int mat2[MAX][MAX], m2, n2;

	//Chuong trinh chinh
int main() {
	printf("\nMa tran A: ");
	InpMat(mat1, m1, n1);
	printf("\nMa tran B: ");
	InpMat(mat2, m2, n2);
	
	TestTwoMatrix();
	return 0;
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

	//Xuat ma tran so nguyen
void OutMat(int mat[][MAX], int m, int n) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			printf("%5d", mat[i][j]);
		printf("\n");
	}
}

	/*Kiem tra xem ma tran A co la con cua ma tran B hay khong?*/
void TestTwoMatrix() {
	bool test;
	if(m1 > m2 || n1 > n2)
		printf("\nMa tran A khong phai la con cua ma tran B");
	else {
		for(int i=0; i<=m2-m1; i++)		//So dong B
			for(int j=0; j<=n2-n1; j++)	 	//So cot B
			{
				test = TestChildMatrix(i, j, i+m1-1, j+n1-1);
				if(test == true) {
					printf("\nMa tran A la con ma tran B");
					return;
				}
			}
	}
	if(test == false)
		printf("\nMa tran A khong phai la con ma tran B");
}

	/*Kiem tra mang con co kich thuoc nhu mang A co phai la con mang B hay khong*/
bool TestChildMatrix(int startRow, int startCol, int endRow, int endCol) {
	int count=0;
	for(int i=startRow; i <= endRow; i++)
		for(int j=startCol; j<=endCol; j++)
		{
			if(mat1[count/n1][count%n1] != mat2[i][j])
				return false;
			count++;
		}
	return true;
}
