#include<stdio.h>
/*
	Cho mang mot chieu cac so nguyen duong. Tim boi so chung nho nhat cua tat ca cac phan tu trong mang.
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void BSCNNArray(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	BSCNNArray(arr, n);
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

	/*Kiem tra uoc so*/
bool Test(int arr[], int n, int us) {
	for(int i=0; i<n; i++)
		if(us%arr[i]!=0)
			return false;
	return true;
}

	/*Tim boi so chung nho nhat cua tat ca cac phan tu trong mang*/
void BSCNNArray(int arr[], int n) {
	int max = arr[0];
	for(int i=0; i<n; i++)
		if(arr[i] > max)
			max = arr[i];
	
	for(int i=max; ; i++)
		if(Test(arr, n, i) == true) {
			printf("\nBoi so chung nho nhat cua mang: %d", i);
			return;
		}
}
