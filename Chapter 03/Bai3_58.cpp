#include<stdio.h>
/*
	Liet ke cac vi tri ma tai do la so nguyen to trong mang mot chieu so nguyen
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

	//Kiem tra so nguyen to?
bool CheckSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)	count++;
	if(count==2) return true;
	else return false;
}

	//Liet ke cac vi tri ma tai do la so nguyen to
void LocatListed(int arr[], int n) {
	printf("\nVi tri chua so nguyen to: ");
	for(int i=0; i<n; i++)
		if(CheckSNT(arr[i])==true)
			printf("%5d", i);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	LocatListed(arr, n);
	return 0;
}

