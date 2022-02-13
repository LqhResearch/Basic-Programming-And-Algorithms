#include<stdio.h>
/*
	Hay cho biet su tuong quan giua so luong so chan va so luong luong so le.
	Ham nay se tra ve -1, 0, 1
		-Gia tri -1 so luong so chan nhieu hon so le
		-Gia tri 0 so luong so chan bang so le
		-Gia tri 1 so luong so chan it hon so le
*/
void NhapMang(int arr[], int n);
void XuatMang(int arr[], int n);
int DemChanLe(int arr[], int n);

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
	
	if(DemChanLe(arr, n) == -1)
		printf("\nSo luong so chan nhieu hon so le");
	else if(DemChanLe(arr, n) == 0)
		printf("\nSo luong so chan bang so le");
	else
		printf("\nSo luong so chan it hon so le");
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

	//Dem so luong so chan, so le
int DemChanLe(int arr[], int n) {
	int countLe = 0, countChan = 0;
	for(int i=0; i<n; i++) {
		if(arr[i]%2==0)
			countChan++;
		else
			countLe++;
	}
	if(countChan > countLe)	return -1;
	else if(countChan == countLe)	return 0;
	else return 1;
}
