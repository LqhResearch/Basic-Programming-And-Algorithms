#include<stdio.h>
/*
	Nhap vao n so nguyen tu ban phim sao khi nhap xong mang duoc sap xep theo thu tu tang dan.
	Hay nthem mot gia tri x vao trong mang tang danma van giu nguyen mang tang dan.
*/
	//Xuat mang so nguyen
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	//Hoan vi hai so nguyen
void Swap(int &a, int &b) {
	int temp=a;
	a=b;
	b=temp;
}

	//Sap xep tang dan
void Sort(int arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i] > arr[j])
				Swap(arr[i], arr[j]);
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
	Sort(arr, n);
	OutArray(arr, n);
}

	//Them phan tu x vao mang so nguyen
void AddElement(int arr[], int n) {
	int x, viTri;
	printf("\n\t===Them Phan Tu===\n");
	printf("Nhap phan tu = ");
	scanf("%d", &x);
	//Tim vi tri
	for(int i=0; i<n; i++)
		if(arr[i] > x){
			viTri=i;
			break;
		}
	if(arr[n-1] < x) viTri=n;	
	//Them phan tu x
	for(int i=n; i>viTri; i--)
		arr[i]=arr[i-1];
	arr[viTri]=x;
	printf("\nMang sau khi chen phan tu %d: ", x);
	OutArray(arr, n+1);	
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	AddElement(arr, n);
	return 0;
}

