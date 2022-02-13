#include<stdio.h>
/*
	Tim "vi tri so hoan thien cuoi cung" trong mang mot chieu so nguyen
*/
	//Xuat mang so nguyen
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	//Nhap mang so nguyen
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

	//Kiem tra mot phan tu co phai la so hoan thien hay khong?
bool TestSHT(int n) {
	int sum=0;
	for(int i=1; i<n; i++)
		if(n%i==0)
			sum+=i;
	if(sum==n)	return true;
	else return false;
}

	//Tim so hoan thien cuoi cung cua mang
int LastNumSHT(int arr[], int n) {
	int viTri;
	for(int i=n-1; i>=0; i--)
		if(TestSHT(arr[i]) == true) {
			viTri=i;
			break;
		}
	return viTri;
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	printf("\nVi tri so hoan thien cuoi cung = %d", LastNumSHT(arr, n));
	return 0;
}
