#include<stdio.h>
/*
	Tong cac gia tri co chu so dau tien la so chan trong mang mot chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool CheckFirstNum(int n);
int SumFirstNum(int arr[], int n);

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
	
	printf("\nTong cac gia tri co chu so dau tien la so chan = %d", SumFirstNum(arr, n));
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

	//Kiem tra xem phan tu co chu so dau tien la so chan hay khong?
bool CheckFirstNum(int n) {
	while(n >= 10)
		n/=10;
	if(n%2==0)	return true;
	else return false;
}
	//Tong cac gia tri co chu so dau tien la so chan
int SumFirstNum(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++)
		if(CheckFirstNum(arr[i]) == true)
			sum+=arr[i];
	return sum;
}
