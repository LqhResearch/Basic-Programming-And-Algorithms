#include<stdio.h>
/*
	Trung binh cong cac gia tri lon hon x trong mang mot chieu so thuc
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
float BiggerX(float arr[], int n, float x);

int main() {
	int n;
	float arr[50], x;
	do{
		printf("Nhap so phan tu n = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So phan tu mang phai > 0\n");
	}while(n <= 0);
	
	NhapMang(arr, n);
	XuatMang(arr, n);
	printf("\nNhap gia tri x = ");
	scanf("%f", &x);
	printf("\nTrung binh cong cac gia tri lon hon %.3f = %.3f", x, BiggerX(arr, n, x));
	return 0;
}

	//Nhap mang 1 chieu
void NhapMang(float arr[], int n) {
	for(int i=0; i<n; i++) {
		printf("Phan tu thu A[%d] = ", i);
		scanf("%f", &arr[i]);
	}
}

	//Xuat mang 1 chieu
void XuatMang(float arr[], int n) {
	printf("Xuat mang: ");
	for(int i=0; i<n; i++)
		printf("%.3f\t", arr[i]);
}

	//Trung binh cong cac gia tri lon hon x trong mang mot chieu so thuc
float BiggerX(float arr[], int n, float x) {
	int count = 0;
	float sum = 0;
	for(int i=0; i<n; i++)
		if(arr[i] > x) {
			sum+=arr[i];
			count++;
		}
	return sum/count;
}
