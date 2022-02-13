#include<stdio.h>
/*
	Hay xoa tat ca cac "so nguyen to" trong mang so nguyen
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

	//Ham xoa 1 phan tu
void DeleteElement(int arr[], int &n, int k) {
	for(int i=k; i<n; i++)
		arr[i]=arr[i+1];
	n--;	//Sao khi thuc hien xoa 1 phan tu --> So luong phan tu n-1 so voi truoc khi xoa
}

	//Kiem tra so chinh phuong?
bool CheckSNT(int n) {
	int count=0;
	for(int i=1; i<=n; i++)
		if(n%i==0)	count++;
	if(count == 2) return true;
	else return false;
}

	//Tim va xoa so nguyen to
void SearchSNT(int arr[], int &n) {
	//Xoa gai tri la so nguyen to
	for(int i=0; i<n; i++)
		if(CheckSNT(arr[i]) == true) {
			DeleteElement(arr, n, i);
			i--;	//Vi khi xoa phan tu i thi phan tu i+1 se duyet thay the. Neu phai duyet la phan tu i
		}
	printf("\nSau khi xoa so nguyen to: ");
	OutArray(arr, n);	
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchSNT(arr, n);
	return 0;
}

