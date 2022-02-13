#include<stdio.h>
#include<math.h>
/*
	Tim so chinh phuong dau tien trong mang mot chieu cac so nguyen
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
bool TestSCP(int n);
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

	/*Kiem tra so chinh phuong*/
bool TestSCP(int n) {
	int tmp = sqrt(n);
	if(tmp*tmp == n) return true;
	else return false;
}

	/*Tim so chinh phuong dau tien trong mang mot chieu cac so nguyen*/
void SearchFirstValue(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(TestSCP(arr[i]) == true) {
			printf("\nGia tri chinh phuong dau tien la %d", arr[i]);
			return;
		}
	printf("\nKhong tim thay");
}
