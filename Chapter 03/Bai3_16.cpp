#include<stdio.h>
/*
	Tinh tong cac gia tri lon hon cac gia tri xung quanh trong mang 1 chieu.
	Luu y: Moi gia tri trong mang chua toi da 2 gia tri xung quanh

*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int SumAround(int arr[], int n);

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
	
	printf("\nTong cac gia tri lon hon cac gia tri xung quanh = %d", SumAround(arr, n));
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

	//Tong cac gia tri lon hon cac gia tri xung quanh
int SumAround(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		if(i==0 && arr[i] > arr[i+1])
			sum+=arr[i];
		else if(i==n-1 && arr[i] > arr[i-1])
			sum+=arr[i];
		else if(i!=0 && (arr[i] > arr[i+1]) && (arr[i] > arr[i-1]))
			sum+=arr[i];
		else sum+=0;
	}
	return sum;
}
