#include<stdio.h>
/*
	Viet ham tinh tong cac gia tri am trong mang 1 chieu so thuc
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
float SumMinus(float arr[], int n);

int main() {
	float arr[50];
	int n;
	do{
		printf("Nhap so phan tu n = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So phan tu mang phai > 0\n");
	}while(n <= 0);
	NhapMang(arr, n);
	XuatMang(arr, n);
	
	printf("\nTong cac so am cua mang = %f", SumMinus(arr, n));
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

	//Tong cac gia tri am trong mang 1 chieu so thuc
float SumMinus(float arr[], int n) {
	float sum = 0;
	for(int i=0; i<n; i++)
		if(arr[i] < 0)
			sum+=arr[i];
	return sum;
}
