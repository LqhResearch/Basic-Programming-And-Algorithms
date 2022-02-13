#include<stdio.h>
/*
	Tong cac gia tri co hang chuc la chu so 5 trong mang 1 chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int Sum(int arr[], int n);

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
	
	printf("\nTong cac gia tri co hang chuc la chu so 5 = %d", Sum(arr, n));
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

	//Tong cac gia tri co hang chuc la chu so 5 trong mang
int Sum(int arr[], int n) {
	int temp, sum = 0;
	for(int i=0; i<n; i++)
	{
		temp = (arr[i]/10)%10;
		if(temp == 5)
			sum+=arr[i];
	}
	return sum;
}
