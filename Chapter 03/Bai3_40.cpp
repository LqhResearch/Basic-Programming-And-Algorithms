#include<stdio.h>
/*
	Dem so luong cac phan tu xung quanh lon nhat, nho nhat trong mang
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int MaxAround(int arr[], int n);
int MinAround(int arr[], int n);

int main() {
	int n, arr[50];
	do{
		printf("\nNhap so phan tu = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n <= 0);
	NhapMang(arr, n);
	XuatMang(arr, n);
	
	printf("\n%d phan tu lon nhat xung quang", MaxAround(arr, n));
	printf("\n%d phan tu nho nhat xung quang", MinAround(arr, n));
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

	//Lon nhat xung quanh
int MaxAround(int arr[], int n) {
	int count=0;
	for(int i=0; i<n; i++) {
		if(i==0 && arr[i] > arr[i])
			count++;
		if(i==n-1 && arr[i] > arr[i-1])
			count++;
		if(i!=0 && i!=n-1 && arr[i]>arr[i-1] && arr[i]>arr[i+1])
			count++;
	}
	return count;
}

	//Nho nhat xung quanh
int MinAround(int arr[], int n) {
	int count=0;
	for(int i=0; i<n; i++) {
		if(i==0 && arr[i] < arr[i])
			count++;
		if(i==n-1 && arr[i] < arr[i-1])
			count++;
		if(i!=0 && i!=n-1 && arr[i]<arr[i-1] && arr[i]<arr[i+1])
			count++;
	}
	return count;
}
