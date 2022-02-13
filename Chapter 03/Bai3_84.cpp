#include<stdio.h>
/*
	Hay cho biet cac phan tu trong mang co bang nhau khong?
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

	//Kiem tra cac phan tu mang
int TestArray(int arr[], int n) {
	int flag=1;
	for(int i=0; i<n-1; i++)
		if(arr[i] != arr[i+1]) {
			flag=0;
			break;
		}
	return flag;
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	if(TestArray(arr, n) == 1)
		printf("\nTat ca phan tu mang deu bang nhau");
	else
		printf("\nPhan tu mang khong mang nhau");
	return 0;
}

