#include<stdio.h>
/*
	Hay xoa tat ca cac phan tu co gia tri trung voi x(x la so nguyen)
*/
	//Xuat mang so nguyen
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	//Nhap mang so nguyen
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

	//Ham xoa 1 phan tu
void DeleteElement(int arr[], int &n, int k) {
	for(int i=k; i<n; i++)
		arr[i]=arr[i+1];
	n--;	//Sao khi thuc hien xoa 1 phan tu --> So luong phan tu n-1 so voi truoc khi xoa
}

	//Tim va xoa gia tri x
void SearchX(int arr[], int &n) {
	int x;
	printf("\nNhap gia tri can xoa = ");
	scanf("%d", &x);
	for(int i=0; i<n; i++)
		if(arr[i]==x) {
			DeleteElement(arr, n, i);
			i--;	//Vi khi xoa phan tu i thi phan tu i+1 se duyet thay the. Neu phai duyet la phan tu i
		}
	printf("\nSau khi xoa gia tri %d: ", x);
	OutArray(arr, n);	
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchX(arr, n);
	return 0;
}


