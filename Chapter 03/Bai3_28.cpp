#include<stdio.h>
/*
	Cho hai mang so nguyen a, b. Hay cho biet mang b co phai la hoan vi cua mang a khong?
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
void SapXepArray(int arr[], int n);
bool KiemTraHoanVi(int a[], int b[], int numA, int numB);

int main() {
	int a[50], b[50], numA, numB;
	do{
		printf("Nhap so phan tu mang a = ");
		scanf("%d", &numA);
		if(numA <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(numA <= 0);
	NhapMang(a, numA);
	
	do{
		printf("Nhap so phan tu mang b = ");
		scanf("%d", &numB);
		if(numB <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(numB <= 0);
	NhapMang(b, numB);
	printf("\nMang a = ");
	XuatMang(a, numA);
	printf("\nMang b = ");
	XuatMang(b, numB);
	if(KiemTraHoanVi(a, b, numA, numB) == true)
		printf("\nMang b la hoan vi cua mang a");
	else
		printf("\nMang b khong phai la hoan vi cua mang a");
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

	//Sap xep mang tang dan
void SapXepArray(int arr[], int n) {
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}

	//Kiem tra xem mang b co phai la hoan vi cua mang a khong?
bool KiemTraHoanVi(int a[], int b[], int numA, int numB) {
	if(numA != numB)	//Hoan vi la so phan tu cua 2 mang phai bang nhau
		return false;
	SapXepArray(a, numA);
	SapXepArray(b, numB);
	for(int i=0; i<numA; i++)
		if(a[i] != b[i])
			return false;
	return true;
}
