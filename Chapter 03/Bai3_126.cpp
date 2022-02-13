#include<stdio.h>
/*
	Cho mang mot chieu cac so nguyen duong. Tim uoc so chung lon nhat cua tat ca cac phan tu trong mang.
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void USCLNArray(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	USCLNArray(arr, n);
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

	/*Kiem tra uoc so*/
bool Test(int arr[], int n, int us) {
	for(int i=0; i<n; i++)
		if(arr[i]%us!=0)
			return false;
	return true;
}

	/*Tim uoc so chung lon nhat cua tat ca cac phan tu trong mang*/
void USCLNArray(int arr[], int n) {
	int min = arr[0];
	for(int i=0; i<n; i++)
		if(arr[i] < min)
			min = arr[i];
	
	int us;
	for(int i=1; i<=min; i++)
		if(Test(arr, n, i) == true)
			us = i;
	printf("\nUoc so chung lon nhat cua mang: %d", us);
}
