#include<stdio.h>
/*
	Hay kiem tra mang so nguyen co ton tai 2 gia tri 0 lien tiep hay khong?
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

	//Kiem tra gia tri 0 lien tiep?
bool CheckNumZero(int arr[], int n) {
	bool flag=false;
	for(int i=0; i<n-1; i++)
		if(arr[i]==0 && arr[i+1]==0)
			return true;
	return flag;
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	if(CheckNumZero(arr, n) == true)
		printf("\nMang co chua gia tri 0 lien tiep");
	else
		printf("\nMang khong co chua gia tri 0 liep tiep");
	return 0;
}

