#include<stdio.h>
/*
	Hay dua so 1 ve dau mang.
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

	//Dua so 1 ve dau mang
void ChangeNum(int arr[], int n) {
	int newArr[n], vt=-1;
	for(int i=0; i<n; i++)	//Mang newArr[]
		if(arr[i] == 1)
			newArr[++vt]=1;
			
	for(int i=0; i<n; i++)	//Mang newArr[]
		if(arr[i] != 1)
			newArr[++vt]=arr[i];
	OutArray(newArr, n);
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	ChangeNum(arr, n);
	return 0;
}
