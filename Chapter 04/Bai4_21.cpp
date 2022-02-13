#include<stdio.h>
#include<stdlib.h>

#define MAX 100
/*
	Sap xep gia tri cac phan tu trong ma tran
	-	Tang / Giam dan theo hinh xoan tron oc.
	-	Tang / Giam dan theo hinh xoan ziczac ngang.
*/
void menu();
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void TangDanSort(int mat[][MAX], int m, int n);
void GiamDanSort(int mat[][MAX], int m, int n);
void XoanTronOcTang(int mat[][MAX], int m, int n);
void XoanTronOcGiam(int mat[][MAX], int m, int n);
void ZicZacNgangTang(int mat[][MAX], int m, int n);
void ZicZacNgangGiam(int mat[][MAX], int m, int n);

int main() {
	do{
		menu();
	}while(true);
	return 0;
}

	//Danh sach chuc nang
void menu() {
	int mat[MAX][MAX], m, n;
	int choice;
	do{
		printf("\n\t=====Danh sach chuc nang=====\n");
		printf("\n1. Tang dan theo hinh xoan tron oc");
		printf("\n2. Giam dan theo hinh xoan tron oc");
		printf("\n3. Tang dan theo hinh xoan ziczac");
		printf("\n4. Giam dan theo hinh xoan ziczac");
		printf("\n0. Thoat");
		printf("\n >> Hay chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice >4)
			printf("\n\tChuc nang %d khong ton tai", choice);
	}while(choice<0 || choice >4);
	
	switch(choice) {
		case 1:{
			printf("\n=====Tang dan theo hinh xoan tron oc=====\n");
			InpMat(mat, m, n);
			XoanTronOcTang(mat, m, n);
			break;
		}
		case 2:{
			printf("\n=====Giam dan theo hinh xoan tron oc=====\n");
			InpMat(mat, m, n);
			XoanTronOcGiam(mat, m, n);
			break;
		}
		case 3:{
			printf("\n=====Tang dan theo hinh xoan ziczac=====\n");
			InpMat(mat, m, n);
			ZicZacNgangTang(mat, m, n);
			break;
		}
		case 4:{
			printf("\n=====Giam dan theo hinh xoan ziczac=====\n");
			InpMat(mat, m, n);
			ZicZacNgangGiam(mat, m, n);
			break;
		}
		case 0: exit(0);
	}
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

	//Hoan vi 2 so nguyen
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

	//Sap xep ma tran tang dan
void TangDanSort(int mat[][MAX], int m, int n) {
	for(int i=0; i<m*n-1; i++)
		for(int j=i+1; j<m*n; j++)
			if(mat[i/n][i%n] > mat[j/n][j%n])
				Swap(mat[i/n][i%n], mat[j/n][j%n]);
}

	//Sap xep ma tran giam dan
void GiamDanSort(int mat[][MAX], int m, int n) {
	for(int i=0; i<m*n-1; i++)
		for(int j=i+1; j<m*n; j++)
			if(mat[i/n][i%n] < mat[j/n][j%n])
				Swap(mat[i/n][i%n], mat[j/n][j%n]);
}

	//Hinh xoan tron oc tang
void XoanTronOcTang(int mat[][MAX], int m, int n) {
	TangDanSort(mat, m, n);
	int newMat[MAX][MAX];	//Tao mang phu
	int left = 0, right = n;
	int up = 0, down = m;
	int num = m*n;
	int count = 0;
	
		//Chep mang phu
	for(int i=0; i<m*n; i++)
		newMat[i/n][i%n] = mat[i/n][i%n];
		
		//Thuat toan xoan oc tang dan
	while(count < num) {
			//Chay hang tren
		for(int i=left; i<right && count < num; i++) {
			mat[up][i] = newMat[count/n][count%n];
			count++;
		}		
		up++;
		
			//Chay cot phai
		for(int i=up; i<down && count < num; i++) {
			mat[i][right-1] = newMat[count/n][count%n];
			count++;
		}	
		right--;
		
			//Chay hang duoi
		for(int i=right-1; i>=left && count < num; i--) {
			mat[down-1][i] = newMat[count/n][count%n];
			count++;
		}		
		down--;
		
			//Chay cot trai
		for(int i=down-1; i>=up && count < num; i--) {
			mat[i][left] = newMat[count/n][count%n];
			count++;
		}	
		left++;
	}
	printf("\nXoan oc tang dan: \n");
	OutMat(mat, m, n);
}

	//Hinh xoan tron oc giam
void XoanTronOcGiam(int mat[][MAX], int m, int n) {
	GiamDanSort(mat, m, n);
	int newMat[MAX][MAX];	//Tao mang phu
	int left = 0, right = n;
	int up = 0, down = m;
	int num = m*n;
	int count = 0;
	
		//Chep mang phu
	for(int i=0; i<m*n; i++)
		newMat[i/n][i%n] = mat[i/n][i%n];
		
		//Thuat toan xoan oc tang dan
	while(count < num) {
			//Chay hang tren
		for(int i=left; i<right && count < num; i++) {
			mat[up][i] = newMat[count/n][count%n];
			count++;
		}		
		up++;
		
			//Chay cot phai
		for(int i=up; i<down && count < num; i++) {
			mat[i][right-1] = newMat[count/n][count%n];
			count++;
		}	
		right--;
		
			//Chay hang duoi
		for(int i=right-1; i>=left && count < num; i--) {
			mat[down-1][i] = newMat[count/n][count%n];
			count++;
		}		
		down--;
		
			//Chay cot trai
		for(int i=down-1; i>=up && count < num; i--) {
			mat[i][left] = newMat[count/n][count%n];
			count++;
		}	
		left++;
	}
	printf("\nXoan oc giam dan: \n");
	OutMat(mat, m, n);
}

	/*Tang dan theo hinh xoan ziczac*/
void ZicZacNgangTang(int mat[][MAX], int m, int n) {
	TangDanSort(mat, m, n);
	int newMat[MAX][MAX];	//Tao mang phu
	
		//Chep mang phu
	for(int i=0; i<m*n; i++)
		newMat[i/n][i%n] = mat[i/n][i%n];
	
	int count = 0;
	for(int i=0; i<m; i++) {
		//Voi moi dong chan, dem so duoc gan vao tung phan tu cua cac cot tu trai sang phai
		if(i%2==0)
			for(int j=0; j<n; j++) {
				mat[i][j] = newMat[count/n][count%n];
				count++;
			}
				
		//Voi moi dong le, dem so duoc gan vao tung phan tu cua cac cot tu phai sang trai
		if(i%2==1)
			for(int j=n-1; j>=0; j--) {
				mat[i][j] = newMat[count/n][count%n];
				count++;
			}
	}
	printf("\nZiczac tang dan: \n");
	OutMat(mat, m, n);
}

	/*Giam dan theo hinh xoan ziczac*/
void ZicZacNgangGiam(int mat[][MAX], int m, int n) {
	GiamDanSort(mat, m, n);
	int newMat[MAX][MAX];	//Tao mang phu
	
		//Chep mang phu
	for(int i=0; i<m*n; i++)
		newMat[i/n][i%n] = mat[i/n][i%n];
	
	int count = 0;
	for(int i=0; i<m; i++) {
		//Voi moi dong chan, dem so duoc gan vao tung phan tu cua cac cot tu trai sang phai
		if(i%2==0)
			for(int j=0; j<n; j++) {
				mat[i][j] = newMat[count/n][count%n];
				count++;
			}
				
		//Voi moi dong le, dem so duoc gan vao tung phan tu cua cac cot tu phai sang trai
		if(i%2==1)
			for(int j=n-1; j>=0; j--) {
				mat[i][j] = newMat[count/n][count%n];
				count++;
			}
	}
	printf("\nZiczac giam dan: \n");
	OutMat(mat, m, n);
}
