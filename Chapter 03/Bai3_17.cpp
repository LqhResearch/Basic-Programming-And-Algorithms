#include<stdio.h>
#include<math.h>
/*
	Tong cac gia tri chinh phuong trong mang 1 chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool CheckChinhPhuong(int n);
int SumChinhPhuong(int arr[], int n);

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
	
	printf("\nTong cac gia tri chinh phuong = %d", SumChinhPhuong(arr, n));
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

	//Kiem tra 1 so co phai la so chinh phuong hay khong?
bool CheckChinhPhuong(int n) {
	if(pow((int)sqrt(n), 2) == n)
		return true;
	return false;
}

	//Tong cac gia tri chinh phuong trong mang 1 chieu so nguyen
int SumChinhPhuong(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++)
		if(CheckChinhPhuong(arr[i]) == true)
			sum+=arr[i];
	return sum;
}
