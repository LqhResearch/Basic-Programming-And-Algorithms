#include<stdio.h>

#define MAX 50
/*
	De quy: Tim vi tri chua gia tri lon nhat trong mang
*/
void InpArr(int *arr, int n);
void OutArr(int *arr, int n);
int Max(int *arr, int n, int max, int vt);

int main() {
	int arr[MAX], n;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	
	InpArr(arr, n);
	printf("\nXuat mang: ");
	OutArr(arr, n);
	
	int max = arr[0], vt=0;
	printf("\nVi tri gia tri lon nhat: %d", Max(arr, n, max, vt));
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

int Max(int *arr, int n, int max, int vt) {
	if(n == -1)
		return vt;
	else {
		if(arr[n] > max) {
			max = arr[n];
			vt=n;
		}
		Max(arr, n-1, max, vt);
	}
}
