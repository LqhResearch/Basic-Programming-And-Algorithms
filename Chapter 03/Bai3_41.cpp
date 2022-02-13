#include<stdio.h>
/*
	Dem so luong gia tri lon nhat trong mang so thuc
*/
void NhapMang(float arr[], int n);
void XuatMang(float arr[], int n);
float MaxArray(float arr[], int n);
int DemMax(float arr[], int n, float max);

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
	float max = MaxArray(arr, n);
	
	printf("\nGia tri lon nhat la %.3f xuat hien %d lan", max, DemMax(arr, n, max));
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

	//Tim phan tu lon nhat trong mang
float MaxArray(float arr[], int n) {
	float max=arr[0];
	for(int i=0; i<n; i++)
		if(arr[i] > max)
			max=arr[i];
	return max;
}

	//Dem so luong phan tu max
int DemMax(float arr[], int n, float max) {
	int count=0;
	for(int i=0; i<n; i++)
		if(arr[i] == max)
			count++;
	return count;
}
