#include<stdio.h>

#define MAX 50
/*
	De quy: Kiem tra mang co thoa tinh chat "toan gia tri am" hay khong?
*/
void InpArr(int *arr, int n);
void OutArr(int *arr, int n);
int ToanAm(int *arr, int n);

int main() {
	int arr[MAX], n;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	
	InpArr(arr, n);
	printf("\nXuat mang: ");
	OutArr(arr, n);
	if(ToanAm(arr, n) == true)
		printf("\nMang toan am");
	else printf("\nMang khong toan am");
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

int ToanAm(int *arr, int n) {
	if(n==0) return -1;
	if(n==1) {
		if(*arr < 0) return 1;
		else return 0;
	}
	if(ToanAm(arr, n-1)==1 && *(arr+n-1) < 0)
		return 1;
	return 0;
}
