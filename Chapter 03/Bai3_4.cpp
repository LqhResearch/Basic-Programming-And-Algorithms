#include<stdio.h>
/*
	Viet ham dem so luong so nguyen to trong mang
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int CountSNT(int arr[], int n);

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
	
	printf("\nSo luong so nguyen to trong mang la %d", CountSNT(arr, n));
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

	//Dem so luong so nguyen to trong mang
int CountSNT(int arr[], int n) {
	int count = 0, countSNT = 0;
	for(int i=0; i<n; i++) {
		int count = 0;
		for(int j=1; j<=arr[i]; j++)
			if(arr[i]%j==0)
				count++;
		if(count == 2) countSNT++;
	}
	return countSNT;
}
