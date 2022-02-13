#include<stdio.h>
/*
	Trung binh cong cua cac so nguyen to trong mang mot chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool CheckNguyenTo(int n);
float SumNguyenTo(int arr[], int n);

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
	
	printf("\nTrung binh cong cua cac so nguyen to = %f", SumNguyenTo(arr, n));
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

	//Kiem tra xem phan tu cua mang co phai la so nguyen to hay không?
bool CheckNguyenTo(int n) {
	int count = 0;
	for(int i=1; i<=n; i++)
		if(n%i==0)
			count++;
	if(count == 2)	return true;
	else return false;
}

	//Trung binh cong cua cac so nguyen to
float SumNguyenTo(int arr[], int n) {
	float sum = 0, count = 0;
	for(int i=0; i<n; i++)
		if(CheckNguyenTo(arr[i]) == true) {
			sum+=arr[i];
			count++;
		}	
	return sum/count;
}
