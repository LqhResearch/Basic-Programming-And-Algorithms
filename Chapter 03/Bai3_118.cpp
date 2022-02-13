#include<stdio.h>
/*
	Hay tim gia tri dau tien trong mang mot chieu cac so nguyen co chu so dau tien la chu so le.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay".
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void SearchFirstValue(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchFirstValue(arr, n);
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

	/*Kiem tra chu so le dau tien*/
bool ChuSoLe(int n) {
	while(n >= 10) {
		n/=10;
	}
	if(n%2==1) return true;
	else return false;
}

	/*Tim gia tri dau tien trong mang mot chieu cac so nguyen co chu so dau tien la chu so le*/
void SearchFirstValue(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(ChuSoLe(arr[i]) == true) {
			printf("\nGia tri co chu so le dau tien la %d", arr[i]);
			return;
		}
	printf("\nKhong tim thay");
}
