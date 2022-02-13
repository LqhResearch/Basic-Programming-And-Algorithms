#include<stdio.h>
/*
	Hay sap xep cac gia tri tai cac vi tri le tang dan cac vi tri khac giu nguyen trong mang 1 chieu so thuc
VD:		
	Chi so	0		1		2		3		4		5
	Giá tri	14.0	-5.7	23.0	13.5	43.1	-12.7
Sau khi sap xep:
	Chi so	0		1		2		3		4		5
	Giá tri	14.0	-12.7	23.0	-5.7	43.1	13.5
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
void SapXep(float arr[], int n);

int main() {
	int n;
	float arr[50];
	do{
		printf("Nhap so phan tu n = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So phan tu mang phai > 0\n");
	}while(n <= 0);
	
	NhapMang(arr, n);
	XuatMang(arr, n);
	printf("\nSau khi sap xep: ");
	SapXep(arr, n);
	XuatMang(arr, n);
	return 0;
}

	//Nhap mang 1 chieu
void NhapMang(float arr[], int n) {
	for(int i=0; i<n; i++) {
		printf("Phan tu thu A[%d] = ", i);
		scanf("%f", &arr[i]);
	}
}

	//Xuat mang 1 chieu
void XuatMang(float arr[], int n) {
	printf("Xuat mang: ");
	for(int i=0; i<n; i++)
		printf("%.3f\t", arr[i]);
}

	//Sap xep
void SapXep(float arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(i%2!=0 && j%2!=0)
				if(arr[i] > arr[j])
				{
					float temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
}
