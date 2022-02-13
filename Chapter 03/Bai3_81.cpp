#include<stdio.h>
/*
	Hay kiem tra mang so nguyen co ton tai so nguyen to hay khong?
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

	//Kiem tra 1 so co phai so nguyen to hay khong?
bool CheckSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)	count++;
	if(count==2) return true;
	else return false;
}

	//Kiem tra so nguyen to?
bool ExistSNT(int arr[], int n) {
	bool flag=false;
	for(int i=0; i<n; i++)
		if(arr[i]%2==0)
			return true;
	return flag;
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	if(ExistSNT(arr, n) == true)
		printf("\nMang co chua so nguyen to");
	else
		printf("\nMang khong co chua so nguyen to");
	return 0;
}
