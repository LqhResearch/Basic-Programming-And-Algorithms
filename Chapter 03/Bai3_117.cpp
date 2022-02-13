#include<stdio.h>
/*
	Tim gia tri dau tien thoa dieu kien la so ganh
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
bool TestSoGanh(int n);
void SearchFirstValue(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchFirstValue(arr, n);
	return 0;
}

	/*Nhap mang so nguyen*/
void InpArray(int arr[], int &n) {
	do{
		printf("Nhap so phan tu = ");
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

	/*Xuat mang so nguyen*/
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	/*Kiem tra so ganh*/
bool TestSoGanh(int n) {
	int nDao = 0, tmp = n;
	while(tmp!=0) {
		nDao=nDao*10 + tmp%10;
		tmp/=10;
	}
	if(nDao == n) return true;
	else return false;
}

	/*Tim gia tri dau tien thoa dieu kien la so ganh*/
void SearchFirstValue(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(TestSoGanh(arr[i]) == true) {
			printf("\nGia tri ganh dau tien la %d", arr[i]);
			return;
		}
	printf("\nKhong tim thay");
}
