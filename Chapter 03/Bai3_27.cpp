#include<stdio.h>
/*
	Hay sap xep cac so hoan hao trong mang 1 chieu so nguyen giam dan cac vi tri con lai giu nguyen gia tri va vi tri
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
bool CheckSHH(int n);
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

	//Kiem tra phan tu co phai la so nguyen to hay khong?
bool CheckSHH(int n) {
	int sum = 0;
	for(int i=1; i<n; i++)
		if(n%i==0)	sum+=i;
	if(sum == n)	return true;
	else return false;
}

	//Sap xep
void SapXep(int arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if((CheckSHH(arr[i]) == true) && (CheckSHH(arr[j]) == true))
				if(arr[i] < arr[j])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
}
