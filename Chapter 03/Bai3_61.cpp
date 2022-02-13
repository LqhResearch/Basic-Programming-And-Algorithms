#include<stdio.h>
/*
	Liet ke cac vi tri tai do bang gia tri duong nho nhat trong mang mot chieu so nguyen
*/
	//Xuat mang so nguyen
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	//Nhap mang so nguyen
void InpArray(int arr[], int &n) {
	do{
		printf("Nhap so phan tu = ");
		scanf("%d", &n);
		if(n<=0)
			printf("So phan tu phai lon hon 0\n");
	}while(n<=0);
	
	printf("\n===Nhap mang===\n");
	for(int i=0; i<n; i++) {
		printf("Phan tu thu %d: ", i);
		scanf("%d", &arr[i]);
	}
	OutArray(arr, n);
}

	//Liet ke cac vi tri tai do bang gia tri duong nho nhat
void LocatListed(int arr[], int n) {
	printf("\nVi tri chua so gia tri duong nho nhat: ");
	//Tim gia tri am dau tien
	int minDuong=arr[0];
	for(int i=0; i<n; i++)
		if(arr[i]<minDuong && arr[i]>0)
			minDuong=arr[i];
	//Liet ke vi tri duong nho nhat
	for(int i=0; i<n; i++)
		if(arr[i]==minDuong)
			printf("%5d", i);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	LocatListed(arr, n);
	return 0;
}

