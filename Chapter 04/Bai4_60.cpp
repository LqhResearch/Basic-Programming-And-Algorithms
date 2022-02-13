#include<stdio.h>

#define MAX 50
/*
	Liet ke cac dong co nhieu chu so nhat trong ma tran so nguyen
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void Listed(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	Listed(mat, m, n);
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

	//Dem chu so bat ki
int CountChuSo(int n) {
	int count = 0;
	while(n!=0) {
		count++;
		n/=10;
	}
	return count;
}

	//Tim so luong so chan nhieu nhat
int CountMaxChuSo(int mat[][MAX], int m, int n) {
	int max = 0;
	for(int i=0; i<m; i++) {	//So dong
		int count = 0;
		for(int j=0; j<n; j++) 		//So cot		
			count+=CountChuSo(mat[i][j]);
		if(count>max)
			max = count;
	}
	return max;	
}

	//Kiem tra dong
bool TestDong(int mat[][MAX], int m, int n, int row, int max) {
	int count = 0;
	for(int j=0; j<n; j++)	//Duyet cot
		count+=CountChuSo(mat[row][j]);
	if(count==max) return true;
	else return false;
}

	//Liet ke cac dong co nhieu chu so nhat trong ma tran so nguyen
void Listed(int mat[][MAX], int m, int n) {
	printf("\nChi so dong co nhieu chu so nhat: ");
	int max = CountMaxChuSo(mat, m, n);
	for(int i=0; i<m; i++)
		if(TestDong(mat, m, n, i, max) == true)
			printf("%5d", i);
}
