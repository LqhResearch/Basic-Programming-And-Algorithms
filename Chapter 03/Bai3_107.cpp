#include<stdio.h>
/*
	Cho mang mot chieu so nguyen a. Hay tao mang b tu mang a, mang b chua so nguyen to cua mang a
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void CreateArrayLe(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	CreateArrayLe(arr, n);
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

	/*Kiem tra so nguyen to?*/
bool TestSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)
			count++;
	if(count==2) return true;
	else return false;
}

	/*Tao mang so nguyen to tu mang cho truoc*/
void CreateArrayLe(int arr[], int n) {
	int arrB[n], vt=0;
	for(int i=0; i<n; i++)	//Duyet mang a
		if(TestSNT(arr[i]) == true) {
			arrB[vt] = arr[i];
			vt++;
		}
	printf("\nMang so nguyen to: ");
	OutArray(arrB, vt);
}
