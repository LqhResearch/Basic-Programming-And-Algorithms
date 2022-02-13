#include<stdio.h>
/*
	Cho mang mot chieu cac so nguyen. Hay tim gia tri x sao cho doan [-x, x] chua tat ca cac gia tri trong mang
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void SearchValueX(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchValueX(arr, n);
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

	/*Khong cach cua 2 so*/
int KCTwoNum(int a, int b) {
	if(a > b) return a-b;
	else return b-a;
}

	/*Tim gia tri x sao cho doan [-x, x] chua tat ca cac gia tri trong mang*/
void SearchValueX(int arr[], int n) {
	int min = arr[0], max = arr[0];
	for(int i=0; i<n; i++) {
		if(arr[i] > max) max = arr[i];
		if(arr[i] < min) min = arr[i];
	}
	
	int x = (KCTwoNum(max, 0) > KCTwoNum(min, 0)) ? KCTwoNum(max, 0) : KCTwoNum(min, 0);
	printf("\nDoan [-x, x] = [%d, %d]", -x, x);
}
