#include<stdio.h>

#define MAX 50
/*
	Kiem tra duong cheo chinh co tang dan tu tren xuong hay khong?
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void TestDuongCheoChinh(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	TestDuongCheoChinh(mat, n);
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

	/*Kiem tra duong cheo chinh co tang dan tu tren xuong hay khong?*/
void TestDuongCheoChinh(float mat[][MAX], int n) {
	bool flag = true;
	for(int i=1; i<n; i++)
		if(mat[i-1][i-1] > mat[i][i]) {
			flag = false;
			break;
		}
	if(flag == true) printf("\nDuong cheo chinh tang dan");
	else printf("\nDuong cheo chinh khong tang dan");
}
