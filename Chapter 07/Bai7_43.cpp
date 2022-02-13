#include<stdio.h>

#define MAX 50
/*
	De quy: Dem gia tri duong trong mang
*/
void InpArr(int *arr, int n);
void OutArr(int *arr, int n);
int CountDuong(int *arr, int n);

int main() {
	int arr[MAX], n;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	
	InpArr(arr, n);
	printf("\nXuat mang: ");
	OutArr(arr, n);
	printf("\nSo gia tri duong: %d", CountDuong(arr, n));
	return 0;
}

void InpArr(int *arr, int n) {
	if(n==0)
		return;
	else {
		printf("Nhap a[%d] = ", n-1);
		scanf("%d", arr+n-1);
		InpArr(arr, n-1);
	}
}

void OutArr(int *arr, int n) {
	if(n==0)
		return;
	else {
		printf("%5d", *(arr+n-1));
		OutArr(arr, n-1);
	}
}

int CountDuong(int *arr, int n) {
	if(n == -1)
		return 0;
	int count=CountDuong(arr, n-1);
	if(arr[n] > 0)
		count++;
	return count;
}
