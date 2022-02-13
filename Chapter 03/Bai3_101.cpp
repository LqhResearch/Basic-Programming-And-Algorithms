#include<stdio.h>
/*
	Cho mang mot chieu cac so nguyen cac so nguyen va mot so nguyen M. 
	Hay tim mang con sao cho cac phan tu trong mang con bang gia tri M.
*/
int row=0;
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

	//Tong mang con
bool SumChildArray(int arr[], int n, int M) {
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=arr[i];
	if(sum==M) return true;
	else return false;
}

	//Xuat mang con
void OutChildArray(int arr[], int n, int M) {
	if(SumChildArray(arr, n, M) == true)
	{
		printf("\nDong %d: ", ++row);
		for(int i=0; i<n; i++)
			printf("%5d", arr[i]);
	}
}

	//Liet cac mang con bang gia tri M
void ChildArrayListed(int arr[], int n) {
	int newArr[n], vt=-1, child=0, M;
	printf("Nhap gia tri M: ");
	scanf("%d", &M);
	for(int i=0; i<n; i++)
	{
		if(i==0 || arr[i] < arr[i-1])
		{
			OutChildArray(newArr, vt, M);
			vt=-1;	//Reset lai vi tri
			newArr[++vt]=arr[i];
			printf("\nDong %d: %5d", ++child, arr[i]);
		}
		else {
			newArr[++vt]=arr[i];
			printf("%5d", arr[i]);	
		}
	}
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	ChildArrayListed(arr, n);
	return 0;
}

