#include<stdio.h>
/*
	Liet ke cac gia tri trong mang mot chieu so thuc thuoc doan [x, y] cho truoc.
*/
	//Xuat mang so thuc
void OutArray(float arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%f\t", arr[i]);
}

	//Nhap mang so thuc
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

	//Liet ke gia tri thuoc doan [x, y] cho truoc
void Listed(float arr[], int n) {
	float x, y;
	printf("\nNhap doan [x, y] = ");
	scanf("%f%f", &x, &y);
	printf("\nCac gia tri thuoc doan [x, y] = ");
	for(int i=0; i<n; i++)
		if(arr[i]>=x && arr[i]<=y)
			printf("%f\t", arr[i]);
}

int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	Listed(arr, n);
	return 0;
}

