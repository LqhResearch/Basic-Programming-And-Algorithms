#include<stdio.h>
/*
	Viet ham tim phan tu lon nhat trong mang 1 chieu so thuc.
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
float MaxArray(float arr[], int n);

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
	
	printf("\nPhan tu lon nhat la %.3f", MaxArray(arr, n));
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

	//Gia tri lon nhat cua mang
float MaxArray(float arr[], int n) {
	float max = arr[0];
	for(int i=0; i<n; i++)
		if(arr[i] > max)
			max = arr[i];	
	return max;
}
