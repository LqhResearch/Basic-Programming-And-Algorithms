#include<stdio.h>

#define MAX 100
/*
	Cho 2 mang so nguyen a, b. Dem va liet ke cac phan tu chi xuat hien 1 trong 2 mang
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool CheckExist(int k, int arr[], int n);
void DemVaLietKe(int arr1[], int arr2[], int n1, int n2);

int main()
{
	int n1, n2, arr1[MAX], arr2[MAX];
	do{
		printf("\nNhap so phan tu = ");
		scanf("%d", &n1);
		if(n1 <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n1 <= 0);
	NhapMang(arr1, n1);
	
	do{
		printf("\nNhap so phan tu = ");
		scanf("%d", &n2);
		if(n2 <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n2 <= 0);
	NhapMang(arr2, n2);
	
	XuatMang(arr1, n1);
	XuatMang(arr2, n2);
	
	DemVaLietKe(arr1, arr2, n1, n2);
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

	//Kiem tra phan tu co ton tai trong mang con lai hay khong?
bool CheckExist(int k, int arr[], int n) {
	for(int i=0; i<n; i++)
		if(arr[i] == k)
			return true;
	return false;
}

	//Liet ke cac phan tu chi xuat hien cac phan tu trong mot mang
void DemVaLietKe(int arr1[], int arr2[], int n1, int n2) {
	int count = 0;
	printf("\nCac phan tu chi xuat hien trong mang a: ");
	for(int i=0; i<n1; i++) //Xu li mang a
		if(CheckExist(arr1[i], arr2, n2) == false)
		{
			printf("%5d", arr1[i]);
			count++;
		}
	printf("\nCac phan tu chi xuat hien trong mang b: ");
	for(int i=0; i<n2; i++) //Xu li mang b
		if(CheckExist(arr2[i], arr1, n1) == false)
		{
			printf("%5d", arr2[i]);
			count++;
		}
	printf("\n%d phan tu chi xuat hien mot trong hai mang", count);
}
