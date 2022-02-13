#include<stdio.h>
/*
	Cho mang mot chieu cac so nguyen. Hay viet ham tim so nguyen to nho nho va lon hon moi gia tri trong mang.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay".
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
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

	/*Kiem tra mot so co phai la so nguyen to hay khong*/
bool TestSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)
			count++;
	if(count==2) return true;
	else return false;
}

	/*Tim so nguyen to nho nho va lon hon moi gia tri trong mang*/
void SearchValue(int arr[], int n) {
	int minSNT, count=0;
	for(int i=0; i<n; i++)
		if(TestSNT(arr[i]) == true && (arr[i] < minSNT || count==0)) {
			minSNT = arr[i];
			count++;
		}
	
	bool flag = true;
	for(int i=0; i<n; i++)
		if(minSNT < arr[i]) {
			flag = false;
			break;
		}
	if(flag == true) printf("\nSo nguyen to nho nhat va lon hon moi gia tri: %d", minSNT);
	else printf("\nKhong tim thay");
}
