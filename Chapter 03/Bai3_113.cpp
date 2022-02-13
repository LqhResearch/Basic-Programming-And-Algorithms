#include<stdio.h>
/*
	Cho mang mot chieu so thuc. Hay tim gia tri am cuoi cung.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay"
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
void SearchLastValue(float arr[], int n);

	//Chuong trinh chinh
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	SearchLastValue(arr, n);
	return 0;
}

	/*Nhap mang so thuc*/
void InpArray(float arr[], int &n) {
	do{
		printf("Nhap so phan tu = ");
		scanf("%d", &n);
		if(n<=0)
			printf("So phan tu phai lon hon 0\n");
	}while(n<=0);
	
	printf("\n===Nhap mang===\n");
	for(int i=0; i<n; i++) {
		printf("Phan tu thu %d: ", i);
		scanf("%f", &arr[i]);
	}
	OutArray(arr, n);
}

	/*Xuat mang so thuc*/
void OutArray(float arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%f\t", arr[i]);
}

	/*Tim gia tri am cuoi cung*/
void SearchLastValue(float arr[], int n) {
	for(int i=n-1; i>=0; i--)
		if(arr[i] < 0) {
			printf("\nGia tri am cuoi cung la %f", arr[i]);
			return;
		}
	printf("\nKhong tim thay");
}
