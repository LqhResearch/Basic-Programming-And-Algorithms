#include<stdio.h>
/*
	Cho mang mot chieu so nguyen. Hay tim gia tri dau tien trong doan [x, y].
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay"
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void SearchFirstValue(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchFirstValue(arr, n);
	return 0;
}

	/*Nhap mang so nguyen*/
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

	/*Xuat mang so nguyen*/
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	/*Tim gia tri dau tien trong doan [x, y]*/
void SearchFirstValue(int arr[], int n) {
	int x, y;
	printf("\nNhap x = ");
	scanf("%d", &x);
	printf("Nhap y = ");
	scanf("%d", &y);
	
	for(int i=0; i<n; i++)
		if(arr[i] >= x && arr[i] <= y) {
			printf("Gia tri dau tien trong doan [%d, %d] la %d", x, y, arr[i]);
			return;
		}
	printf("Khong tim thay");	
}
