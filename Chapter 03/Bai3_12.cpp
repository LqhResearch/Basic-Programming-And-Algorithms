#include<stdio.h>
/*
	Tong cac gia tri co chu so dau tien la so le trong mang 1 chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool CheckEle(int n);
int Sum(int arr[], int n);

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
	
	printf("\nTong cac gia tri co chu so dau tien la so le = %d", Sum(arr, n));
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

	//Kiem tra chu so dau tien cua 1 gia tri trong mang
bool CheckEle(int n) {
	while(n >= 10) 
		n/=10;
	if(n%2!=0)	return true;
	else return false;
}

	//Tong cac gia tri co chu so dau tien la so le trong mang 1 chieu so nguyen
int Sum(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++)
		if(CheckEle(arr[i]) == true)
			sum+=arr[i];
	return sum;
}
