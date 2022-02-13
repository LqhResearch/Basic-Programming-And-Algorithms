#include<stdio.h>
/*
	Them mot phan tu x vao vi tri k
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

	//Them mot phan tu x vao vi tri k
void AddElement(int arr[], int n) {
	int x, k;
	printf("\nNhap gia tri phan tu = ");
	scanf("%d", &x);
	printf("Nhap vi tri can chen = ");
	scanf("%d", &k);
	
	arr[n+1];
	for(int i=n; i>k; i--)
		arr[i]=arr[i-1];
	arr[k]=x;
	OutArray(arr, n+1);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	AddElement(arr, n);
	return 0;
}

