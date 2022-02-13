#include<stdio.h>
/*
	Hay tim gia tri trong mang cac so thuc "xa gia tri x nhat"
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
float KCTowNum(float a, float b);
void XaXNhat(float arr[], int n);

	//Chuong trinh chinh
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	XaXNhat(arr, n);
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

	/*Khong cach cua 2 so*/
float KCTwoNum(float a, float b) {
	if(a > b) return a-b;
	else return b-a;
}

	/*Hay tim gia tri trong mang cac so thuc "xa gia tri x nhat"*/
void XaXNhat(float arr[], int n) {
	float x;
	printf("\nNhap x = ");
	scanf("%f", &x);
	
	float max = 0, value;
	for(int i=0; i<n; i++)
		if(KCTwoNum(arr[i], x) > max) {
			max = KCTwoNum(arr[i], x);
			value = arr[i];
		}
	printf("\nXa gia tri x nhat la %f", value);
}
