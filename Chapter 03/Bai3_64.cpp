#include<stdio.h>
/*
	Liet ke cac gia tri toan la chu so le trong mang mot chieu so nguyen
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

	//Kiem tra toan chu so le?
bool CheckToanLe(int n) {
	while(n!=0) {
		if((n%10)%2==0)
			return false;
		n/=10;
	}
	return true;
}

	//Liet ke cac gia tri toan la chu so le
void Listed(int arr[], int n) {
	printf("\nLiet ke: ");
	for(int i=0; i<n; i++)
		if(CheckToanLe(arr[i])==true)
			printf("%5d", arr[i]);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	Listed(arr, n);
	return 0;
}

