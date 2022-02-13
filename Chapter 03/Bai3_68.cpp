#include<stdio.h>
/*
	Hay tao mang b tu mang a cac gia tri 0, 1 de mang tinh chan, le
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

	//Tao mang b tu mang a voi gia tri 0, 1 mang tinh chan le
void CreateArray(int arr[], int n) {
	int b[n];
	for(int i=0; i<n; i++)
		if(arr[i]%2==0)
			b[i]=0;
		else b[i]=1;
	printf("\nMang b: ");
	OutArray(b, n);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	CreateArray(arr, n);
	return 0;
}

