#include<stdio.h>
/*
	Hay liet ke tan suat xuat hien cac gia tri xuat hien trong mang so nguyen.
	Luu y: Moi gia tri chi liet ke 1 lan.
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
void LietKeTanXuat(int arr[], int n);

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
	
	LietKeTanXuat(arr, n);
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

	//Liet ke tan suat xuat hien cac gia tri xuat hien trong mang
void LietKeTanXuat(int arr[], int n) {
	for(int i=0; i<n; i++) {
		int exist=0;
		for(int j=0; j<i; j++)
			if(arr[i] == arr[j])
				exist++;
		if(exist==0)
		{
			int count=0;
			for(int j=i; j<n; j++)
				if(arr[i] == arr[j])
					count++;
			printf("\nGia tri %d xuat hien %d lan", arr[i], count);
		}
	}
}
