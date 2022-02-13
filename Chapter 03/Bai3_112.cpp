#include<stdio.h>
/*
	Cho mang mot chieu so thuc. Hay tim gia tri dau tien lon hon gia tri 10.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay"
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
void SearchFirstValue(float arr[], int n);

	//Chuong trinh chinh
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	SearchFirstValue(arr, n);
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

	/*Tim gia tri dau tien lon hon gia tri 10*/
void SearchFirstValue(float arr[], int n) {
	for(int i=0; i<n; i++)
		if(arr[i] > 10) {
			printf("\nGia tri lon hon 10 la %f", arr[i]);
			return;
		}
	printf("\nKhong tim thay");
}
