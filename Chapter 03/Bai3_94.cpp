#include<stdio.h>
#include<stdlib.h>
/*
	Hay "dich trai xoay vong" hoac "dich phai xoay vong" k lan cac phan tu trong mang so nguyen
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
		printf("\nNhap so phan tu = ");
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

	//Dinh dang vi tri [0, n-1]
int Location(int vt, int n, int k, char c) {
	if(c == 'l') {
		vt+=k;	//Tang vi tri len k lan
		if(vt>=n) vt-=n;	//Dinh dang vi tri trong khoang [0, n-1]
	}
	else {
		vt-=k;	//Giam vi tri len k lan
		if(vt<0) vt+=n;	//Dinh dang vi tri trong khoang [0, n-1]
	}
	return vt;
}

	//Dich trai xoay vong k lan
void DichTraiXoayVong(int arr[], int n) {
	int newArr[n], k;
	printf("\nNhap so lan dich trai phan tu = ");
	scanf("%d", &k);
	for(int i=0; i<n; i++)	//Mang newArr
	 	newArr[i] = arr[Location(i, n, k, 'l')];
	printf("\nSau khi dich trai xoay vong %d lan: ", k);
	OutArray(newArr, n);
}

	//Dich trai phai vong k lan
void DichPhaiXoayVong(int arr[], int n) {
	int newArr[n], k;
	printf("\nNhap so lan dich phai phan tu = ");
	scanf("%d", &k);
	for(int i=0; i<n; i++)	//Mang newArr
	 	newArr[i] = arr[Location(i, n, k, 'r')];
	printf("\nSau khi dich phai xoay vong %d lan: ", k);
	OutArray(newArr, n);
}

void Manage() {
	int arr[50], n, type;
	do{
		printf("\n\t===XOAY VONG====\n");
		printf("\n1. Dich trai xoay vong");
		printf("\n2. Dich phai xoay vong");
		printf("\n0. Thoat");
		printf("\n>> Hay lua chon: ");
		scanf("%d", &type);
		if(type<0 || type>2)
			printf("\nChuc nang nay khong ton tai");
	}while(type<0 || type>2);
	
	switch(type) {
		case 1:{
			InpArray(arr, n);
			DichTraiXoayVong(arr, n);
			break;
		}
		case 2:{
			InpArray(arr, n);
			DichPhaiXoayVong(arr, n);
			break;
		}
		case 0: exit(1);
	}
}

	//Chuong trinh chinh
int main() {
	do{
		Manage();
	}while(true);
	return 0;
}

