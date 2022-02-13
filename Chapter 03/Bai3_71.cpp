#include<stdio.h>
/*
	Hay xoa tat ca cac so lon nhat trong mang so thuc
*/
	//Xuat mang so thuc
void OutArray(float arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%f\t", arr[i]);
}

	//Nhap mang so thuc
void InpArray(float arr[], int &n) {
	do{
		printf("Nhap so phan tu = ");
		scanf("%d", &n);
		if(n<=0)
			printf("So phan tu phai lon hon 0\n");
	}while(n<=0);
	
	printf("\n===Nhap mang===\n");
	for(int i=0; i<n; i++) {
		printf("Phan tu thu %d: ", i);
		scanf("%f", &arr[i]);
	}
	OutArray(arr, n);
}

	//Ham xoa 1 phan tu so thuc
void DeleteElement(float arr[], int &n, int k) {
	for(int i=k; i<n; i++)
		arr[i]=arr[i+1];
	n--;	//Sao khi thuc hien xoa 1 phan tu --> So luong phan tu n-1 so voi truoc khi xoa
	
}

	//Tim va xoa gia tri max
void SearchMax(float arr[], int &n) {
	int max=arr[0];
	for(int i=1; i<n; i++)		//Tim phan tu lon nhat
		if(arr[i]>max)
			max=arr[i];
	//Xoa phan tu max
	for(int i=0; i<n; i++)
		if(arr[i] == max) {
			DeleteElement(arr, n, i);
			i--;	//Vi khi xoa phan tu i thi phan tu i+1 se duyet thay the. Neu phai duyet la phan tu i
		}
	printf("\nSau khi xoa vi tri %d: ", max);
	OutArray(arr, n);	
}

int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	SearchMax(arr, n);
	return 0;
}

