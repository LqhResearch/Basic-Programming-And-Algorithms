#include<stdio.h>
/*
	Kiem tra mang co ton tai gia tri 0 hay không? Tra ve gia true hoac false
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

	//Kiem tra gia tri 0?
bool CheckNumZero(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(arr[i]==0)
			return true;
	return false;
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	if(CheckNumZero(arr, n) == true)
		printf("\nMang co chua gia tri 0");
	else
		printf("\nMang khong co chua gia tri 0");
	return 0;
}

