#include<stdio.h>
#include<stdlib.h>

#define MAX 8
/*
	Cho ban co vua kich thuoc (8x8).
	Hay di chuyen quan ma tren khap ban co sao cho moi o di qua dung mot lan.
*/ 
int A[MAX][MAX] = { 0 };	//Khoi tao mang gia tri 0
int X[8] = {-2, -2, -1,-1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int count = 0;	//So buoc di
int n;
 
	//Xuat ma tran so nguyen
void OutMat() {
	for(int i=0; i<n; i++) {	//So dong
		for(int j=0; j<n; j++) 	//So cot
			printf("%5d", A[i][j]);
		printf("\n");
	}
	printf("\n");
}
 
void diChuyen(int x, int y) {
    count++;	//Tang gia tri buoc di
    A[x][y] = count; 	//Danh dau da di
    for(int i = 0; i < 8; i++) {
    	//Kiem tra xem ma da di het ban co chua
        if (count == n * n) {
        	printf("Cac buoc di la: \n");
        	OutMat();
            exit(0);
        }
        //Neu chua di het ban co thi tao buoc di moi
        int u = x + X[i];	//Tao mot vi tri x moi
        int v = y + Y[i];	//Tao mot vi tri y moi
        //Neu hop li thi tien hanh di chuyen
        if (u >= 0 && u < n && v >= 0 && v < n && A[u][v] == 0)
            diChuyen(u, v);
    }
    //Neu khong tim duoc buoc di thi ta phai tra loi cac gia tri ban dau
    count--;
    A[x][y] = 0;
}

int main() {
	int a, b;
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap vi tri ban dau: \n");
	printf("x: ");
	scanf("%d", &a);
	printf("y: ");
	scanf("%d", &b);
    diChuyen(a, b);
    //Neu khong tim duoc buoc di thi se thong bao
    printf("Khong tim thay duong di.");
    return 0;
}

