#include<stdio.h>
/*
	Tim mang con co tong lon nhat trong mang mot chieu so nguyen
*/
#include<stdio.h>
/*
	Viet ham nhap, xuat mang mot chieu so nguyen.
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
int SumChildArray(int arr[], int n, int start, int end);
void SearchMaxChildArray(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchMaxChildArray(arr, n);
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

	/*Tong mang con*/
int SumChildArray(int arr[], int n, int start, int end) {
	int sum = 0;
	for(int i=start; i<=end; i++)
		sum+=arr[i];
	return sum;
}

	/*Xuat mang con*/
void OutChild(int arr[], int n, int start, int end) {
	printf("\n");
	for(int i=start; i<=end; i++)
		printf("%5d", arr[i]);
}

	/*Tim mang con co tong lon nhat trong mang mot chieu so nguyen*/
void SearchMaxChildArray(int arr[], int n) {
	int max;
	for(int i=1; i<=n; i++)		//So phan tu cua mang con
		for(int j=0; j<=n-i; j++) {	//Duyet mang
			int sum = SumChildArray(arr, n, j, j+i-1);
			if(sum>max || (i==1 && j==0))
				max = sum;
		}
	
	printf("\nMang con co tong lon nhat: ");
	for(int i=1; i<=n; i++)		//So phan tu cua mang con
		for(int j=0; j<=n-i; j++) 	//Duyet mang
			if(max == SumChildArray(arr, n, j, j+i-1))
				OutChild(arr, n, j, j+i-1);
}
