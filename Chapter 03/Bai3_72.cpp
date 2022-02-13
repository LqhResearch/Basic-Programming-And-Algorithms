#include<stdio.h>
/*
	Hay xoa tat ca cac so am trong mang so thuc
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

	//Tim va xoa gia tri am
void SearchMinusNum(float arr[], int &n) {
	//Xoa phan tu gia tri am
	for(int i=0; i<n; i++)
		if(arr[i] < 0) {
			DeleteElement(arr, n, i);
			i--;	//Vi khi xoa phan tu i thi phan tu i+1 se duyet thay the. Neu phai duyet la phan tu i
		}
	printf("\nSau khi xoa gia tri am: ");
	OutArray(arr, n);	
}

int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	SearchMinusNum(arr, n);
	return 0;
}

