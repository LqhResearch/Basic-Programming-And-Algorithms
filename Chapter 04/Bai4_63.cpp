#include<stdio.h>
#include<stdlib.h>

#define MAX 50
/*
	Dich chuyen xoay vong ma tran:
	
	-	Dich xuong xoay vong cac hang.
				Vi du: 
			87	75	62	54
			46	40	33	28
			20	18	15	10
			-20	67	53	23
				Ket qua dich xuong xoay vong cac hang: 
			-20	67	53	23
			87	75	62	54
			46	40	33	28
			20	18	15	10
		
	-	Dich trai xoay vong cac cot.
				Vi du: 
			87	75	62	54
			46	40	33	28
			20	18	15	10
			-20	67	53	23
				Ket qua dich trai xoay vong cac cot
			75	62	54	87
			40	33	28	46
			18	15	10	20
			67	53	23	-20

	-	Dich tren xoay vong cac hang.
	-	Dich phai xoay vong cac cot.
	-	Dich trai xoay vong theo chieu kim dong ho cac gia tri nam tren bien.
	-	Dich phai xoay vong theo chieu kim dong ho cac gia tri nam tren bien.
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void menu();
void DichTrenXoayVong(int mat[][MAX], int m, int n);
void DichXuongXoayVong(int mat[][MAX], int m, int n);
void DichTraiXoayVong(int mat[][MAX], int m, int n);
void DichPhaiXoayVong(int mat[][MAX], int m, int n);
void DichTraiBienKDH(int mat[][MAX], int m, int n);
void DichPhaiBienKDH(int mat[][MAX], int m, int n);

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

	/*Danh sach xoay vong*/
void menu() {
	int choice;
	do{
		printf("\n=====Dich chuyen xoay vong ma tran=====");
		printf("\n1. Dich tren xoay vong cac hang.");
		printf("\n2. Dich xuong xoay vong cac hang.");
		printf("\n3. Dich trai xoay vong cac cot.");
		printf("\n4. Dich phai xoay vong cac cot.");
		printf("\n5. Dich trai xoay vong theo chieu kim dong ho cac gia tri nam tren bien.");
		printf("\n6. Dich phai xoay vong theo chieu kim dong ho cac gia tri nam tren bien.");
		printf("\n0. Thoat.");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>6)
			printf("\nChuc nang nay khong ton tai.");
	}while(choice<0 || choice>6);
	
	int mat[MAX][MAX], m, n;
	if(choice != 0)
		InpMat(mat, m, n);
	switch(choice) {
		case 1:{
			DichTrenXoayVong(mat, m, n);
			break;
		}
		case 2:{
			DichXuongXoayVong(mat, m, n);
			break;
		}
		case 3:{
			DichTraiXoayVong(mat, m, n);
			break;
		}
		case 4:{
			DichPhaiXoayVong(mat, m, n);
			break;
		}
		case 5:{
			DichTraiBienKDH(mat, m, n);
			break;
		}
		case 6:{
			DichPhaiBienKDH(mat, m, n);
			break;
		}
		case 0: exit(0);
	}
}

	/*Dich tren xoay vong cac hang.*/
void DichTrenXoayVong(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX];
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
		{
			if(i==m-1) newMat[i][j] = mat[0][j];
			else newMat[i][j] = mat[i+1][j];
		}
	printf("\nDich tren xoay vong: ");
	OutMat(newMat, m, n);
}

	/*Dich xuong xoay vong cac hang.*/
void DichXuongXoayVong(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX];
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
		{
			if(i==0) newMat[i][j] = mat[m-1][j];
			else newMat[i][j] = mat[i-1][j];
		}
	printf("\nDich xuong xoay vong: ");
	OutMat(newMat, m, n);
}

	/*Dich trai xoay vong cac hang.*/
void DichTraiXoayVong(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX];
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
		{
			if(j==n-1) newMat[i][j] = mat[i][0];
			else newMat[i][j] = mat[i][j+1];
		}
	printf("\nDich trai xoay vong: ");
	OutMat(newMat, m, n);
}

	/*Dich phai xoay vong cac hang.*/
void DichPhaiXoayVong(int mat[][MAX], int m, int n) {
	int newMat[MAX][MAX];
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
		{
			if(j==0) newMat[i][j] = mat[i][n-1];
			else newMat[i][j] = mat[i][j-1];
		}
	printf("\nDich phai xoay vong: ");
	OutMat(newMat, m, n);
}

	/*Dich trai xoay vong theo chieu kim dong ho cac gia tri nam tren bien.*/
void DichTraiBienKDH(int mat[][MAX], int m, int n) {	//Nguoc chieu kim dong ho
	int newMat[MAX][MAX];
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
		{
			if(i==0 && j==n-1)
				newMat[i][j] = mat[1][n-1];
			else if(i==m-1 && j==n-1)
				newMat[i][j] = mat[m-1][n-2];	
			else if(i==0)
				newMat[i][j] = mat[i][j+1];
			else if(j==0)
				newMat[i][j] = mat[i-1][j];
			else if(j==n-1)
				newMat[i][j] = mat[i+1][j];
			else if(i==m-1)
				newMat[i][j] = mat[i][j-1];
			
			else newMat[i][j] = mat[i][j];
			
		}
	printf("\nDich phai xoay vong: ");
	OutMat(newMat, m, n);
}

	/*Dich phai xoay vong theo chieu kim dong ho cac gia tri nam tren bien.*/
void DichPhaiBienKDH(int mat[][MAX], int m, int n) {	// chieu kim dong ho
	int newMat[MAX][MAX];
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
		{
			if(i==0 && j==0)
				newMat[i][j] = mat[1][0];
			else if(i==0)
				newMat[i][j] = mat[i][j-1];
			else if(j==n-1)
				newMat[i][j] = mat[i-1][j];
			else if(i==m-1)
				newMat[i][j] = mat[i][j+1];
			else if(j==0)
				newMat[i][j] = mat[i+1][j];
			else newMat[i][j] = mat[i][j];
			
		}
	printf("\nDich phai xoay vong: ");
	OutMat(newMat, m, n);
}

