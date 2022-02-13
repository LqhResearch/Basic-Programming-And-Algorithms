#include<stdio.h>
#include<math.h>
/*
	Tinh trung binh nhan cua cac gia tri duong trong mang mot chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
float mulAverage(int arr[], int n);

int main() {
	int arr[50], n;
	do{
		printf("Nhap so phan tu = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n <= 0);
	
	NhapMang(arr, n);
	XuatMang(arr, n);
	printf("\nTrung binh nhan cua mang la %f", mulAverage(arr, n));
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

	//Tinh trung binh nhan cua cac gia tri duong
float mulAverage(int arr[], int n) {
	int count = 0;
	float mulAver, mul = 1;
	for(int i=0; i<n; i++)
		if(arr[i] > 0)
		{
			mul*=arr[i];
			count++;
		}
	mulAver = pow(mul, 1.0/count);
	return mulAver;
}
