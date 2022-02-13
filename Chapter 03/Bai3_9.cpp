#include<stdio.h>
/*
	Viet ham liet ke vi tri chua gia tri am trong mang 1 chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
void LietKeViTri(int arr[], int n);

int main() {
	int n, arr[50];
	do{
		printf("Nhap so phan tu n = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So phan tu mang phai > 0\n");
	}while(n <= 0);
	
	NhapMang(arr, n);
	XuatMang(arr, n);
	LietKeViTri(arr, n);
	return 0;
}

	//Nhap mang
void NhapMang(int arr[], int n) {
	for(int i=0; i<n; i++) {
		printf("Phan tu thu A[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

	//Xuat mang
void XuatMang(int arr[], int n) {
	printf("Xuat mang: ");
	for(int i=0; i<n; i++)
		printf("%d\t", arr[i]);
}

	//Liet ke vi tri chua gia tri am
void LietKeViTri(int arr[], int n) {
	printf("\nVi tri chua gia tri am = ");
	for(int i=0; i<n; i++)
		if(arr[i] < 0)
			printf("%d\t", i);
}
