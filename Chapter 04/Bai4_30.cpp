#include<stdio.h>

#define MAX 50
/*
	Liet ke gia tri "Hoang Hau" tren ma tran.
	Biet rang: Mot phan tu duoc goi la Hoang Hau khi no lon nhat tren dong, tren cot va hai duong cheo qua no.
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
bool TestHoangHau(int mat[][MAX], int m, int n, int dong, int cot);
void ListedHoangHau(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	
	ListedHoangHau(mat, m, n);
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

	/*Test phan tu co phai hoang hau khong*/
bool TestHoangHau(int mat[][MAX], int m, int n, int dong, int cot) {
	int x = mat[dong][cot];
	
		//Kiem tra dong
	for(int i=0; i<n; i++)
		if(mat[dong][i] > x)
			return false;
	
		//Kiem tra cot
	for(int j=0; j<m; j++)
		if(mat[j][cot] > x)
			return false;
	
		//Kiem tra duong cheo thu nhat
	int row = dong+1;
	int col = cot+1;
	while(col+1 < n && row < dong) {
		if(mat[col][row] > x)
			return false;
		row++;		col++;
	}
	
	row = dong-1;
	col = cot-1;
	while(col-1 >= 0 && row >= 0) {
		if(mat[col][row] > x)
			return false;
		row--;		col--;
	}
	
		//Kiem tra duong cheo thu hai
	row = dong+1;
	col = cot-1;
	while(col-1 >= 0 && row < dong) {
		if(mat[col][row] > x)
			return false;
		row++;		col--;
	}
	
	row = dong-1;
	col = cot+1;
	while(col-1 >= 0 && col < n) {
		if(mat[col][row] > x)
			return false;
		row--;		col++;
	}
	return true;
}

	/*Liet ke gia tri "Hoang Hau" tren ma tran.*/
void ListedHoangHau(int mat[][MAX], int m, int n) {
	printf("\nLiet ke: ");
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(TestHoangHau(mat, m, n, i, j) == true)
				printf("%5d", mat[i][j]);
}
