#include<stdio.h>
/*
	Hay bien doi bang cac thay cac gia tri lon nhat bang gia tri nho nhat va nguoc lai
*/
	//Xuat mang so nguyen
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	//Nhap mang so nguyen
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

	//Bien doi max va min
void ChangeElement(int arr[], int n) {
	int max = arr[0], min = arr[0];
	//Tim max va min cua mang
	for(int i=1; i<n; i++) {
		if(arr[i] > max)	max=arr[i];
		if(arr[i] < min)	min=arr[i];	
	}
	printf("\nMax = %d\tMin = %d", max, min);
	//Bien doi max va min
	for(int i=0; i<n; i++) {
		if(arr[i] == max) {
			arr[i]=min;
			continue;
		}	
		if(arr[i] == min)
			arr[i]=max;
	}
	printf("\nSau khi bien doi: ");
	OutArray(arr, n);
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	ChangeElement(arr, n);
	return 0;
}

