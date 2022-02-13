#include<stdio.h>
#include<stdlib.h>

#define MAX 50
/*
	Chieu guong ma tran theo truc doc hay truc ngang.
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void menu();
void TrucDoc(int mat[][MAX], int m, int n);
void TrucNgang(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	do{
		menu();
	}while(true);
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

	/*Chieu guong*/
void menu() {
	int choice;
	do{
		printf("\n=====Chieu guong=====");
		printf("\n1. Chieu guong theo truc doc");
		printf("\n2. Chieu guong theo truc ngang");
		printf("\n0. Thoat.");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>2)
			printf("\nChuc nang nay khong ton tai.");
	}while(choice<0 || choice>2);
	
	int mat[MAX][MAX], m, n;
	if(choice != 0)
		InpMat(mat, m, n);
	switch(choice) {
		case 1:{
			TrucDoc(mat, m, n);
			break;
		}
		case 2:{
			TrucNgang(mat, m, n);
			break;
		}
		case 0: exit(0);
	}
}

	/*Chieu guong ma tran theo truc doc*/
void TrucDoc(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX], dong=m, cot=2*n-1;
	for(int i=0; i<dong; i++) 		//So dong
		for(int j=0; j<cot; j++) 		//So cot
		{
			if(j >= n)
				newMat[i][j] = mat[i][cot-j-1];
			else newMat[i][j] = mat[i][j];
		}
	printf("\nChieu guong theo truc doc: ");
	OutMat(newMat, dong, cot);
}

	/*Chieu guong ma tran theo truc ngang*/
void TrucNgang(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX], dong=2*m-1, cot=n;
	for(int i=0; i<dong; i++) 		//So dong
		for(int j=0; j<cot; j++) 		//So cot
		{
			if(i >= m)
				newMat[i][j] = mat[dong-i-1][j];
			else newMat[i][j] = mat[i][j];
		}
	printf("\nChieu guong theo truc ngang: ");
	OutMat(newMat, dong, cot);
}
