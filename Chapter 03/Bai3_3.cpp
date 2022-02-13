#include<stdio.h>
/*
	Viet hàm kiem tra trong mang các so nguyên có ton tai giá tri chan nho hon 100 hay không?
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool Check(int arr[], int n);

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
	if(Check(arr, n) == true)
		printf("\nMang chua phan tu chan va nho hon 100");
	else
		printf("\nMang khong chua phan tu chan va nho hon 100");
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

	//Kiem tra xem mang co ton tai gia tri chan hon hon 100 hay khong?
bool Check(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(arr[i]%2==0 && arr[i] < 100)
			return true;
	return false;
}
