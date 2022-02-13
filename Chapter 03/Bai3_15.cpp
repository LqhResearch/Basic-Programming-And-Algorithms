#include<stdio.h>
#include<math.h>
/*
	Tinh tong cac gia tri lon hon tri tuyet doi cua gia tri dung lien sau mang mot chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int AbsNum(int arr[], int n);

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
	
	printf("\nTong cac gia tri lon hon tri tuyet doi cua gia tri dung lien sau = %d", AbsNum(arr, n));
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
	
	//Tong cac gia tri lon hon tri tuyet doi cua gia tri dung lien sau
int AbsNum(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n-1; i++)
	{
		int temp = abs(arr[i+1]);
		if(arr[i] > temp)
			sum+=arr[i];
	}
	return sum;
}
