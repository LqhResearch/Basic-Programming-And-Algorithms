#include<stdio.h>
/*
	Xoa mot phan tu co chi so k trong mang so nguyen
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
	printf("\nSau khi xoa vi tri %d: ", k);
	OutArray(arr, n);
}

int main() {
	int arr[50], n, k;
	InpArray(arr, n);
	
	printf("\nNhap vi tri can xoa: ");
	scanf("%d", &k);
	DeleteElement(arr, n, k);
	return 0;
}

