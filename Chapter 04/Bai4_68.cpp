#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;
/*
	Nhap va xuat ma tran:
	-	Ma tran goi la "thua" (sparse matrix) neu so phan tu co gia tri 0 nhieu so phan tu co gia tri khac 0.
	Kiem tra xem ma tran tren co "thua" hay khong?
	-	Thuc hien cac phep bien doi so cap hang tren ma tran (phep khu Gauss) de dua ma tran tro thanh ma tran tam giac tren.
*/
void InpMat(int mat[][MAX], int &m, int &n);
void OutMat(int mat[][MAX], int m, int n);
void SparseMatrix(int mat[][MAX], int m, int n);

	//Chuong trinh chinh
int main() {
	int mat[MAX][MAX], m, n;
	InpMat(mat, m, n);
	SparseMatrix(mat, m, n);
	return 0;
}

	//Nhap ma tran so nguyen
void InpMat(int mat[][MAX], int &m, int &n) {
	do{
		cout << "Nhap so dong = ";
		cin >> m;
		if(m<=0)
			cout << "So dong phai lon hon 0" << endl;
	}while(m<=0);
	do{
		cout << "Nhap so cot = ";
		cin >> n;
		if(n<=0)
			cout << "So cot phai lon hon 0" << endl;
	}while(n<=0);
	
	cout << endl << "===Nhap ma tran===" << endl;
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) {	//So cot
			cout << "Phan tu thu [" << i << "][" << j << "] = ";
			cin >> mat[i][j];
		}
		cout << endl;
	}
	OutMat(mat, m, n);
}

	//Xuat ma tran so nguyen
void OutMat(int mat[][MAX], int m, int n) {
	cout << "===Xuat ma tran===" << endl;
	for(int i=0; i<m; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			cout << mat[i][j] << "   ";
		cout << endl;
	}
}

	/*Kiem tra xem ma tran tren co "thua" hay khong?*/
void SparseMatrix(int mat[][MAX], int m, int n) {
	int zero = 0;
	for(int i=0; i<m; i++) 	//So dong
		for(int j=0; j<n; j++) 	//So cot
			if(mat[i][j] == 0)
				zero++;
	if(zero > (m*n - zero))
		cout << "Ma tran thua" << endl;
	else cout << "Ma tran khong thua" << endl;
}

