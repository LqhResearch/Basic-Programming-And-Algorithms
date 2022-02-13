#include<stdio.h>
/*
	Cho mang mot chieu cac so nguyen. Hay tim gia tri thoa dieu kien sau:
	-	Toan chu so le va gia tri lon nhat.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay".
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
bool TestToanLe(int n);
void SearchValue(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchValue(arr, n);
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

	/*Kiem tra mot so bat ki toan le*/
bool TestToanLe(int n) {
	while(n != 0) {
		if(n%2==0)
			return false;
		n/=10;
	}
	return true;
}

	/*Toan chu so le va gia tri lon nhat*/
void SearchValue(int arr[], int n) {
	int max = 0;
	for(int i=0; i<n; i++)
		if(TestToanLe(arr[i]) == true && arr[i] > max)
			max = arr[i];
	printf("\nGia tri lon nhat va toan chu so le: %d", max);
}
