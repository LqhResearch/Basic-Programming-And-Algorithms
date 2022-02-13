#include<stdio.h>
/*
	Liet ke cac gia tri chan trong mang mot chieu so nguyen thuoc doan [x, y]
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

	//Liet ke gia tri thuoc doan [x, y] cho truoc
void Listed(int arr[], int n) {
	int x, y;
	printf("\nNhap doan [x, y] = ");
	scanf("%d%d", &x, &y);
	printf("\nCac gia tri thuoc doan [x, y] = ");
	for(int i=0; i<n; i++)
		if(arr[i]>=x && arr[i]<=y)
			printf("%5d", arr[i]);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	Listed(arr, n);
	return 0;
}

