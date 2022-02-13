#include<stdio.h>
/*
	Dem so luong gia tri tan cung la 5 trong mang mot chieu so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool TestTanCung5(int n);
int DemTanCung5(int arr[], int n);

int main() {
	int n, arr[50];
	do{
		printf("\nNhap so phan tu = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n <= 0);
	NhapMang(arr, n);
	XuatMang(arr, n);
	
	printf("\n%d gia tri tan cung la 5", DemTanCung5(arr, n));
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

	//Kiem tra mot so co tan cung la 5 hay khong?
bool TestTanCung5(int n) {
	int lastNum = n%10;
	if(lastNum==5)	return true;
	else return false;
}

	//Dem so luong gia tri tan cung la 5 trong mang
int DemTanCung5(int arr[], int n) {
	int count=0;
	for(int i=0; i<n; i++)
		if(TestTanCung5(arr[i]) == true)
			count++;
	return count;
}
