#include<stdio.h>
/*
	Viet ham tìm mot vi trí mà giá tri tai vi trí dó là mot giá tri nho nhat trong mang mot chieu các so nguyên.
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int ViTriMinArray(int arr[], int n);

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
	
	printf("\nVi tri chua phan tu nho nhat la %d", ViTriMinArray(arr, n));
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

	//Vi tri phan tu nho nhat cua mang
int ViTriMinArray(int arr[], int n) {
	int min = arr[0], viTri;
	for(int i=0; i<n; i++)
		if(arr[i] < min) {
			min = arr[i];
			viTri = i;
		}
	return viTri;	
}
