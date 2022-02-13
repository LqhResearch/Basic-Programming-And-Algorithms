#include<stdio.h>
/*
	Trung binh cong cac so duong trong mang 1 chieu so thuc
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
float TBCDuong(float arr[], int n);

int main() {
	int n;
	float arr[50];
	do{
		printf("Nhap so phan tu n = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So phan tu mang phai > 0\n");
	}while(n <= 0);
	
	NhapMang(arr, n);
	XuatMang(arr, n);
	
	printf("\nTrung binh cong cac so duong %.3f", TBCDuong(arr, n));
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

	//Trung binh cong cac so duong trong mang 1 chieu so thuc
float TBCDuong(float arr[], int n) {
	int count = 0;
	float sum = 0;
	for(int i=0; i<n; i++)
		if(arr[i] > 0) {
			sum+=arr[i];
			count++;
		}
	return sum/count;
}
