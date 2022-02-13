#include<stdio.h>
/*
	Hay sap xep cac gia tri duong tang dan trong mang mot chieu so thuc, cac gia tri am giu nguyen vi tri.
	VD: 	14.0	-45.7	23.0	13.5	43.1	-12.9
			13.5	-45.7	14.0	23.0	43.1	-12.9
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
void SapXepDuong(float arr[], int n);

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
	printf("\nSau khi sap xep: ");
	SapXepDuong(arr, n);
	XuatMang(arr, n);
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

	//Sap xep
void SapXepDuong(float arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i]>0 && arr[j]>0 && arr[i]>arr[j])
			{
				float temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}
