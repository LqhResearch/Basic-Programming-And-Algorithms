#include<stdio.h>
/*
	Liet ke cac gia tri chan co it nhat mot lan can la gia tri chan
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

	//Liet ke cac gia tri chan co it nhat mot lan can la gia tri chan
void Listed(int arr[], int n) {
	printf("\nLiet ke: ");
	for(int i=0; i<n; i++) {
		if(i==0 && arr[i]%2==0 && arr[i+1]%2==0)
			printf("%5d", arr[i]);
		if(i==n-1 && arr[i]%2==0 && arr[i-1]%2==0)
			printf("%5d", arr[i]);
		if(i!=0 && i!=n-1 && arr[i]%2==0 && (arr[i+1]%2==0 || arr[i-1]%2==0))
			printf("%5d", arr[i]);
	}
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	Listed(arr, n);
	return 0;
}

