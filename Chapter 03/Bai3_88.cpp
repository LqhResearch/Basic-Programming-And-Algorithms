#include<stdio.h>
/*
	Tim "so chan chan cuoi cung" trong mang mot chieu so nguyen
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

	//Tim gia tri chan cuoi cung cua mang
int SoChanCuoiCung(int arr[], int n) {
	int lastNum;
	for(int i=n-1; i>=0; i--)
		if(arr[i]%2==0) {
			lastNum=arr[i];
			break;
		}
	return lastNum;
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	printf("\nSo chan cuoi cung cua mang la %d", SoChanCuoiCung(arr, n));
	return 0;
}


