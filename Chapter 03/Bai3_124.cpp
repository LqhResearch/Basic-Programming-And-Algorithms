#include<stdio.h>
/*
	Viet ham tim chu so xuat hien it nhat trong mang mot chieu so nguyen
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void CountChuSo(int n);
void SearchChuSo(int arr[], int n);
int ChuSo[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchChuSo(arr, n);
	return 0;
}

	/*Nhap mang so nguyen*/
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

	/*Xuat mang so nguyen*/
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	/*Dem chu so cua mot phan tu*/
void CountChuSo(int n) {
	while(n!=0) {
		ChuSo[n%10]++;
		n/=10;
	}
}

	/*Tim chu so xuat hien it nhat trong mang mot chieu so nguyen*/
void SearchChuSo(int arr[], int n) {
	for(int i=0; i<n; i++)
		CountChuSo(arr[i]);
	
	int min = ChuSo[0];
	for(int i=0; i<=9; i++)
		if(ChuSo[i] < min)
			min = i;
	printf("\nChu so xuat hien it nhat: %d", min);
}
