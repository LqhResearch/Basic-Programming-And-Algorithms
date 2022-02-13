#include<stdio.h>
/*
	Tinh khoang cach trung binh giua cac gia tri trong mang
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
float KhoangCachTB(float arr[], int n);

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
	
	printf("\nKhoang cach trung binh giua cac gia tri la %f", KhoangCachTB(arr, n));
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

	//Khoang cach trung binh
float KhoangCachTB(float arr[], int n) {
	float range = 0;
	for(int i=1; i<n; i++)	//Voi n phan tu se co n-1 khoang cach
		range+=(arr[i]) > arr[i-1] ? (arr[i] - arr[i-1]) : (arr[i-1] - arr[i]);
	return (range/(n-1));
}
