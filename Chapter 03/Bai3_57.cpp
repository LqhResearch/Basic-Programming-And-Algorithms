#include<stdio.h>
/*
	Liet ke cac vi tri ma tai do gia tri lon nhat trong mang mot chieu so thuc.
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

	//Liet ke cac vi tri ma tai do gia tri lon nhat
void LocatListed(float arr[], int n) {
	printf("\nVi tri chua gia tri lon nhat: ");
	float max=arr[0];
	for(int i=1; i<n; i++)
		if(arr[i]>max)
			max=arr[i];
	for(int i=0; i<n; i++)	//Liet ke vi tri
		if(arr[i]==max)
			printf("%5d", i);
}

int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	LocatListed(arr, n);
	return 0;
}

