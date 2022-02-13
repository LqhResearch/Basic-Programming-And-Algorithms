#include<stdio.h>
/*
	Hay xoa tat ca cac phan tu co tan suat xuat hien nhieu hon mot lan
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

	//Dem tan xuat xuat hien
int Count(int arr[], int n, int k) {
	int count=0;
	for(int i=0; i<n; i++)
		if(arr[i] == k)
			count++;
	return count;
}

	//Tim va xoa phan tu co tan xuat xuat hien hon 1 lan
void SearchSNT(int arr[], int &n) {
	for(int i=0; i<n; i++)
		if(Count(arr, n, arr[i]) > 1) {
			int k=arr[i];
			for(int j=i; j<n; j++)
				if(arr[j] == k) {
					DeleteElement(arr, n, j);
					j--;	//Vi khi xoa phan tu j thi phan tu j+1 se duyet thay the. Neu phai duyet la phan tu j
				}
		}
	printf("\nSau khi xoa: ");
	OutArray(arr, n);	
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchSNT(arr, n);
	return 0;
}

