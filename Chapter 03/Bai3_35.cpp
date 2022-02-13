#include<stdio.h>
/*
	Dem so luong gia tri duong va chia het cho 7 trong mang mot chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int DemDuongMod7(int arr[], int n);

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
	
	printf("\n%d gia tri duong va chia het cho 7 trong mang", DemDuongMod7(arr, n));
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

	//Dem so luong gia tri duong va chia het cho 7 trong mang
int DemDuongMod7(int arr[], int n) {
	int count=0;
	for(int i=0; i<n; i++)
		if(arr[i]>0 && arr[i]%7==0)
			count++;
	return count;
}
