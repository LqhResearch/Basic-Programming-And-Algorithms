#include<stdio.h>
/*
	Hay cho biet mang so nguyen co lap thanh cap so cong hay khong?
	Neu co hay chi ra cong sai d
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

	//Kiem tra cap so cong
int TestCapSoCong(int arr[], int n, int &d) {
	int flag=1;
	d=arr[1]-arr[0];
	for(int i=1; i<n-1; i++)
		if(arr[i+1]-arr[i] != d) {
			flag=0;
			break;
		}
	return flag;
}

int main() {
	int arr[50], n, d;	//d la cong sai
	InpArray(arr, n);
	
	if(TestCapSoCong(arr, n, d) == 1)
		printf("\nMang cap so cong. Cong sai d = %d", d);
	else
		printf("\nMang khong phai cap so cong");
	return 0;
}

