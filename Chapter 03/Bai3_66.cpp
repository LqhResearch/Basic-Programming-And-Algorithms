#include<stdio.h>
/*
	Liet ke tat ca cac cap gia tri gan nhau nhat trong mang so nguyen
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

	//Tinh khoang cach cac cap so
int KCCapSo(int a, int b) {
	if(a < b)
		return b-a;
	else return a-b;
}

	//Liet ke tat ca cac cap gia tri gan nhau nhat
void Listed(int arr[], int n) {
	//Tim khoang cach gan nhat
	int ganNhat=KCCapSo(arr[0], arr[1]);
	for(int i=1; i<n-1; i++)
		if(KCCapSo(arr[i], arr[i+1]) < ganNhat)
			ganNhat=KCCapSo(arr[i], arr[i+1]);
	printf("\nKhoang cach gan nhat = %d", ganNhat);
	printf("\nLiet ke: ");
	for(int i=0; i<n-1; i++)
		if(KCCapSo(arr[i], arr[i+1]) == ganNhat)
			printf("\nCap: %5d%5d", arr[i], arr[i+1]);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	Listed(arr, n);
	return 0;
}

