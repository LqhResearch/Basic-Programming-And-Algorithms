#include<stdio.h>

#define MAX 50
/*
	Kiem tra ma tran co doi xung qua duong cheo phu hay khong?
*/
void InpMat(float mat[][MAX], int &n);
void OutMat(float mat[][MAX], int n);
void TestDoiXung(float mat[][MAX], int n);

	/*Main funtion*/
int main() {
	int n;
	float mat[MAX][MAX];
	InpMat(mat, n);
	
	TestDoiXung(mat, n);
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

	/*Kiem tra ma tran co doi xung qua duong cheo phu hay khong?*/
void TestDoiXung(float mat[][MAX], int n) {
	bool flag = true;
	for(int i=0; i<n; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(i+j!=n-1 && mat[i][j] != mat[n-i-1][n-j-1]) {	//Duong cheo phu
				flag = false;
				break;
			}
	if(flag == true) printf("\nMa tran doi xung qua duong cheo phu");
	else printf("\nMa tran khong doi xung qua duong cheo phu");
}

