#include<stdio.h>
#include<math.h>
/*
	Tim ma tran nghich dao cap 3
*/
void InpMat(float mat[][3]);
void OutMat(float mat[][3]);
void MaTranNghichDao(float mat[][3]);
float DinhThuc(float mat[][3]);

	/*Main funtion*/
int main() {
	float mat[3][3];
	InpMat(mat);
	
	MaTranNghichDao(mat);
	return 0;
}

	/*Nhap ma tran vuong so thuc*/
void InpMat(float mat[][3]) {
	printf("\n===Nhap ma tran cap 3===\n");
	for(int i=0; i<3; i++) {	//So dong
		for(int j=0; j<3; j++) {	//So cot
			printf("Phan tu thu [%d][%d] = ", i, j);
			scanf("%f", &mat[i][j]);
		}
		printf("\n");
	}
	OutMat(mat);
}

	/*Xuat ma tran vuong so thuc*/
void OutMat(float mat[][3]) {
	printf("===Xuat ma tran===\n");
	for(int i=0; i<3; i++) {	//So dong
		for(int j=0; j<3; j++) 		//So cot
			printf("%f\t", mat[i][j]);
		printf("\n");
	}
}

	/*Tinh dinh thuc cap 3 (Quy tac cua Sarrus)*/
float DinhThuc(float mat[][3]) {
	float detMat = 0;
	detMat = detMat + mat[0][0]*mat[1][1]*mat[2][2] + mat[0][1]*mat[1][2]*mat[2][0] + mat[0][2]*mat[1][0]*mat[2][1];
	detMat = detMat - mat[0][2]*mat[1][1]*mat[2][0] - mat[0][0]*mat[1][2]*mat[2][1] - mat[0][1]*mat[1][0]*mat[2][2];
	return detMat;
}

	/*Su dung phu dai so cho tung phan tu*/
float PhuDaiSo(float mat[][3], int row, int col) {
	float newMat[2][2];
	int local=0;
	for(int i=0; i<3; i++) 		//So dong
		for(int j=0; j<3; j++) 		//So cot
			if(i!=row && j!=col)
			{
				newMat[local/2][local%2] = mat[i][j];
				local++;
			}
	float kq = newMat[0][0]*newMat[1][1] - newMat[0][1]*newMat[1][0];
	if((row+col)%2==0)
		return kq;
	else return -kq;
}

	/*Tim ma tran nghich dao*/
void MaTranNghichDao(float mat[][3]) {
	float newMat[3][3];
	float det = DinhThuc(mat);
	printf("\nDinh thuc cua ma tran la %f", det);
	//Ma tran khong kha nghich
	if(det == 0) {
		printf("\nMa tran khong kha nghich");
		return;
	}
	
	//Ma tran kha nghich
	for(int i=0; i<3; i++) 		//So dong
		for(int j=0; j<3; j++) 		//So cot
			newMat[i][j] = PhuDaiSo(mat, j, i);
			
	for(int i=0; i<3; i++) 		//So dong
		for(int j=0; j<3; j++) 		//So cot
			newMat[i][j]/=det;
			
	OutMat(newMat);
}
