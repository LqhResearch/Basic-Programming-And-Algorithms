#include<stdio.h>
/*
	Liet ke cac gia tri duong. Liet ke cac gia tri am
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

	//Liet ke cac gia tri duong.
void ListedDuong(int arr[], int n) {
	printf("\nCac gia tri duong = ");
	for(int i=0; i<n; i++)
		if(arr[i] > 0)
			printf("%5d", arr[i]);
}

	//Liet ke cac gia tri am.
void ListedAm(int arr[], int n) {
	printf("\nCac gia tri am = ");
	for(int i=0; i<n; i++)
		if(arr[i] < 0)
			printf("%5d", arr[i]);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	ListedDuong(arr, n);
	ListedAm(arr, n);
	return 0;
}

