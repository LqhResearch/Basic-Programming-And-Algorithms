#include<stdio.h>
/*
	Hay xuat mang theo yeu cau: 
	-	cac phan tu chan nam tren mot dong
	-	cac phan tu le nam tren dong tiep theo
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

/*	-	cac phan tu chan nam tren mot dong
	-	cac phan tu le nam tren dong tiep theo */
void OutChanLe(int arr[], int n) {
	printf("\nPhan tu chan: ");
	for(int i=0; i<n; i++)
		if(arr[i]%2==0)
			printf("%5d", arr[i]);
	printf("\nPhan tu le: ");
	for(int i=0; i<n; i++)
		if(arr[i]%2!=0)
			printf("%5d", arr[i]);
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	OutChanLe(arr, n);
	return 0;
}

