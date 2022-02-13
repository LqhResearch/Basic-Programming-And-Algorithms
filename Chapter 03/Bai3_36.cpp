#include<stdio.h>
/*
	Dem gia tri doi xung trong mang so nguyen
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool TestDoiXung(int n);
int DemDoiXung(int arr[], int n);

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
	
	printf("\n%d gia tri doi xung trong mang", DemDoiXung(arr, n));
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

	//Kiem tra xem mot so co doi xung khong?
bool TestDoiXung(int n) {
	int nDao=0, tmp=n;
	while(tmp!=0) {
		nDao=nDao*10+tmp%10;
		tmp/=10;
	}
	if(n==nDao)	return true;
	else return false;
}

	//Dem gia tri doi xung trong mang
int DemDoiXung(int arr[], int n) {
	int count=0;
	for(int i=0; i<n; i++)
		if(TestDoiXung(arr[i]) == true)
			count++;
	return count;
}
