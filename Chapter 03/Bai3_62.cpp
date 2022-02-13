#include<stdio.h>
/*
	Liet ke cac vi tri bang vi tri chan lon nhat trong mang mot chieu so nguyen
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

	//Liet ke cac vi tri bang vi tri chan lon nhat
void LocatListed(int arr[], int n) {
	//Tim vi tri chan lon nhat
	int viTri;
	for(int i=n-1; i>=0; i++)
		if(i%2==0) {
			viTri=i;
			break;
		}
	printf("\nVi tri gia tri chan lon nhat: %d", viTri);
	//Liet ke vi tri bang vi tri chan lon nhat
	printf("\nVi tri: ");
	for(int i=0; i<n; i++)
		if(arr[i]==arr[viTri])
			printf("%5d", i);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	LocatListed(arr, n);
	return 0;
}

