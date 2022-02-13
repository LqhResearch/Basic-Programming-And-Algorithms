#include<stdio.h>
/*
	Viet ham sap sep mang mot chieu so thuc giam dan
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
void SapXepGiam(float arr[], int n);

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
	printf("\nSap xep giam dan: ");
	SapXepGiam(arr, n);
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

	//Sap xep mang so thuc giam dan
void SapXepGiam(float arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i] < arr[j])
			{
				float temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	XuatMang(arr, n);
}
