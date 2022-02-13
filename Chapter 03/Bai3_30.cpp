#include<stdio.h>
/*
	Hay sap xep cac so chan trong mang so nguyen tang dan, cac so le giam dan
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
void Swap(int &a, int &b);
void SapXep(int arr[], int n);

int main() {
	int arr[50], n;
	do{
		printf("Nhap so phan tu = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n <= 0);
	
	NhapMang(arr, n);
	XuatMang(arr, n);
	printf("\nSau khi sap xep: ");
	SapXep(arr, n);
	XuatMang(arr, n);
	return 0;
}

	//Nhap mang
void NhapMang(int arr[], int n) {
	for(int i=0; i<n; i++) {
		printf("Phan tu thu A[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

	//Xuat mang
void XuatMang(int arr[], int n) {
	printf("Xuat mang: ");
	for(int i=0; i<n; i++)
		printf("%d\t", arr[i]);
}

	//Hoan vi 2 gia tri
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

	//Sap xep cac so chan trong mang so nguyen tang dan, cac so le giam dan
void SapXep(int arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]%2==0 && arr[j]%2==0 && arr[i] > arr[j])
				Swap(arr[i], arr[j]);
			if(arr[i]%2!=0 && arr[j]%2!=0 && arr[i] < arr[j])
				Swap(arr[i], arr[j]);	
		}
}
