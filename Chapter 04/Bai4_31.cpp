#include<stdio.h>

#define MAX 50
/*
	Liet ke cuc tri trong ma tran.
	Biet rang: Mot phan tu duoc goi la cuc tri khi no lon nhat cac phan tu xung quanh hoac nho hon cac phan tu xung quanh.
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
bool TestCucTri(int mat[][MAX], int m, int n);
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

	/*Kiem tra mot phan tu co phai la cuc tri hay khong?*/
bool TestCucTri(int mat[][MAX], int m, int n, int dong, int cot) {
	bool cucDai = true, cucTieu = true;
	for(int i=-1; i<=1; i++)
		for(int j=-1; j<=1; j++)
			if(dong+i>=0 && cot+j>=0 && dong+i<m && cot+j<n && !(i==0 && j==0)) {
				if(mat[dong][cot] <= mat[dong+i][cot+j])
					cucDai = false;
				if(mat[dong][cot] >= mat[dong+i][cot+j])
					cucTieu = false;
				if(!cucDai && !cucTieu) break;	
			}
	if(!cucDai && !cucTieu)	return false;
	return true;
}

	/*Liet ke cuc tri*/
void Listed(int mat[][MAX], int m, int n) {
	printf("\nLiet ke cuc tri: ");
	for(int i=0; i<m; i++) 		//So dong
		for(int j=0; j<n; j++) 		//So cot
			if(TestCucTri(mat, m, n, i, j) == true)
				printf("%5d", mat[i][j]);
}
