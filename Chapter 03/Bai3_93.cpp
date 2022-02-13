#include<stdio.h>
/*
	Hay dao nguoc thu tu cac so duong trong mang.
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

	//Hoan vi hai so nguyen
void Swap(int &a, int &b) {
	int tmp=a;
	a=b;
	b=tmp;
}

	//Dao nguoc thu tu so duong trong mang
void ReverseArray(int arr[], int n) {
	int head=0, tail=n-1;
	while(head < tail) {
		while(arr[head]<=0) head++;
		while(arr[tail]<=0) tail--;
		Swap(arr[head], arr[tail]);
		head++;		tail--;
	}
	OutArray(arr, n);
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	printf("\nSau khi dao gia tri duong: ");
	ReverseArray(arr, n);
	return 0;
}

