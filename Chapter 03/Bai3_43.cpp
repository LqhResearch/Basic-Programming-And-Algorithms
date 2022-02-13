#include<stdio.h>
/*
	Hay liet ke cac gia tri xuat hien dung 1 lan trong mang so nguyen.
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
void LietKeTanXuat1Lan(int arr[], int n);

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
	
	LietKeTanXuat1Lan(arr, n);
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

	//Liet ke cac gia tri xuat hien dung 1 lan trong mang
void LietKeTanXuat1Lan(int arr[], int n) {
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
			if(count==1) printf("\nGia tri %d xuat hien %d lan", arr[i], count);
		}
	}
}
