#include<stdio.h>

#define MAX 50
/*
	Hay tron 2 mang thanh so nguyen duong tang dan thanh 1 mang so nguyen tang dan
*/
	//Kiem tra mang tang dan
bool TestTangDan(int arr[], int n) {
	for(int i=1; i<n; i++)
		if(arr[i-1] >= arr[i])
			return false;
	return true;
}

	//Xuat mang
void XuatMang(int arr[], int n) {
	printf("Xuat mang: ");
	for(int i=0; i<n; i++)
		printf("%d\t", arr[i]);
}

	//Nhap mang
void NhapMang(int arr[], int &n) {
	do{
		printf("\nNhap so phan tu = ");
		scanf("%d", &n);
		if(n <= 0)
			printf("So luong phan tu la so nguyen duong\n");
	}while(n <= 0);
	
	do{
		for(int i=0; i<n; i++) {
			printf("Phan tu thu A[%d] = ", i);
			scanf("%d", &arr[i]);
		}
		if(TestTangDan(arr, n) == false)
			printf("\nVui long nhap mang tang dan\n");
	}while(TestTangDan(arr, n) == false);
	XuatMang(arr, n);
}

	//Tron hai mang thanh mot mang so nguyen tang dan
void MergeArray(int arr1[], int arr2[], int n1, int n2) {
	int merge[n1+n2], vt1=0, vt2=0;
	for(int i=0; i<(n1+n2); i++) {
		if(vt1>=n1)		//Doi voi truong mot mang a da het phan tu
		{
			merge[i]=arr2[vt2];
			vt2++;
			continue;
		}
		if(vt2>=n2) 	//Doi voi truong mot mang b da het phan tu
		{
			merge[i]=arr1[vt1];
			vt1++;
			continue;
		}
		//Gan phan tu nho vao mang merge
		if(arr1[vt1] <= arr2[vt2]) {
			merge[i]=arr1[vt1];
			vt1++;
		}
		else {
			merge[i]=arr2[vt2];
			vt2++;
		}
	}
	printf("\nMang sau khi duoc tron: ");
	XuatMang(merge, n1+n2);
}

int main() {
	int n1, n2, arr1[MAX], arr2[MAX];
	NhapMang(arr1, n1);
	NhapMang(arr2, n2);
	
	MergeArray(arr1, arr2, n1, n2);
	return 0;
}

