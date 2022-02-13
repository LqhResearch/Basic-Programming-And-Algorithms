#include<stdio.h>

#define MAX 50
/*
	Dem so luong so hoan thien trong mot hang cua ma tran so thuc
*/
void OutMat(float mat[][MAX], int m, int n);
void InpMat(float mat[][MAX], int &m, int &n);
bool TestSHH(int n);
void CountSHHHang(float mat[][MAX], int m, int n);

int main() {
	int m, n;
	float mat[MAX][MAX];
	InpMat(mat, m, n);
	
	CountSHHHang(mat, m, n);
	return 0;
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

bool TestSHH(int n) {
	int sum = 0;
	for(int i=1; i<n; i++)
		if(n%i==0)
			sum+=i;
	if(sum == n) return true;
	else return false;
}

	//Dem so luong so hoan thien trong mot hang cua ma tran so thuc
void CountSHHHang(float mat[][MAX], int m, int n) {
	int count = 0, row;
	printf("\nNhap hang can dem: ");
	scanf("%d", &row);
	for(int j=0; j<n; j++)		//So cot
		if(TestSHH(mat[row][j]) == true)
			count++;
	if(count == 0)	printf("\nKhong tim thay so hoan thien trong hang %d", row);
	else printf("\nMa tran co chua %d so hoan thien trong hang %d", count, row);
}

