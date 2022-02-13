#include<stdio.h>
/*
	Cho mang mot chieu cac so thuc. Hay tim gia tri thoa hai dieu kien sau:
	+	Co hai gia tri lan can.
	+	Gia tri tai vi tri do bang tich hai gia tri lan can.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay"
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
void SearchValue(float arr[], int n);

	//Chuong trinh chinh
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	SearchValue(arr, n);
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

	/*Co hai gia tri lan can va gia tri tai vi tri do bang tich hai gia tri lan can.*/
void SearchValue(float arr[], int n) {
	int count = 0;
	printf("\n");
	for(int i=1; i<n-1; i++)
		if(arr[i] == arr[i-1] * arr[i+1]) {
			printf("%f\t", arr[i]);
			count++;
		}
	if(count == 0) printf("\nKhong tim thay");
}
