#include<stdio.h>

#define MAX 50
/*
	De quy: Tinh tong cac so chan trong mang
*/
void InpArr(int *arr, int n);
void OutArr(int *arr, int n);
int sumSoChan(int *arr, int n);

int main() {
	int arr[MAX], n;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	
	InpArr(arr, n);
	printf("\nXuat mang: ");
	OutArr(arr, n);
	printf("\nTong so chan cua mang: %d", sumSoChan(arr, n));
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

int sumSoChan(int *arr, int n) {
	if(n == -1)
		return 0;
	int sum=sumSoChan(arr, n-1);
	if(arr[n]%2==0)
		sum+=arr[n];
	return sum;
}
