#include<stdio.h>
#include<math.h>
/*
	Cho mang mot chieu cac so nguyen. Hay tim gia tri dau tien co dang 5^k.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay".
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
bool Test5k(int n);
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

	/*Kiemtra mot so nguyen co dang 5^k hay khong*/
bool Test5k(int n) {
	int tmp = n, k=0;
	while(tmp > 1) {
		k++;
		tmp/=5;
	}
	if(pow(5, k) == n) return true;
	else return false;
}

	/*Tim gia tri dau tien co dang 5^k*/
void SearchFirstValue(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(Test5k(arr[i]) == true) {
			printf("\nGia tri co dang 5^k dau tien la %d", arr[i]);
			return;
		}
	printf("\nKhong tim thay");
}
