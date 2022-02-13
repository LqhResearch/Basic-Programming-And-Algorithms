#include<stdio.h>
/*
	Dem so lan xuat hien cua gia tri x trong mang so thuc
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
int DemX(float arr[], int n, float x);

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
	printf("\nNhap gia tri thuc can dem = ");
	scanf("%f", &x);
	
	printf("\n%d lan xuat hien %.3f", DemX(arr, n, x), x);
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

	//Dem so lan xuat hien cua gia tri x trong mang so thuc
int DemX(float arr[], int n, float x) {
	int count=0;
	for(int i=0; i<n; i++)
		if(arr[i]==x)
			count++;
	return count;
}
