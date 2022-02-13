#include<stdio.h>
/*
	Cho mang mot chieu so thuc a. Hay tao mang b tu mang a, mang b chua cac phan tu am cua mang a
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
void CreateArrayMinus(float arr[], int n);

	//Chuong trinh chinh
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	CreateArrayMinus(arr, n);
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

	/*Tao mang am tu mang cho truoc*/
void CreateArrayMinus(float arr[], int n) {
	float arrB[n];
	int vt=0;
	for(int i=0; i<n; i++)	//Duyet mang a
		if(arr[i] < 0) {
			arrB[vt] = arr[i];
			vt++;
		}
	printf("\nMang so am: ");
	OutArray(arrB, vt);
}
