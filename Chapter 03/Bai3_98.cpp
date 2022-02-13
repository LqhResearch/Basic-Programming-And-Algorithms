#include<stdio.h>
/*
	Liet ke cac mang con co gia tri lon nhat
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

	//Xuat mang con
void OutChildArray(int arr[], int n, int cols) {
	//Kiem tra mang con co chua gia tri max khong?
	printf("\nDong %d: ", cols);
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	//Tim max
int MaxArray(int arr[], int n) {
	int max=arr[0];
	for(int i=1; i<n; i++)
		if(arr[i] > max)
			max=arr[i];
	return max;
}

	//Kiem tra mang con
bool TestMax(int arr[], int n, int max) {
	for(int i=0; i<n; i++)
		if(arr[i] == max)
			return true;
	return false;
}

	//Liet ke mang con co chua gia tri lon nhat
void ChildArrayListed(int arr[], int n) {
	int newArr[n], nA=-1;
	int cols=0;
	int max=MaxArray(arr, n);
	for(int i=0; i<n; i++) {
		if(arr[i] > arr[i+1]) {
			newArr[++nA] = arr[i];
			if(TestMax(newArr, nA+1, max) == true) {
				OutChildArray(newArr, nA+1, ++cols);
			}
			//Reset lai gia tri
			nA=-1;
			continue;	
		}
		if(arr[i] < arr[i+1])
			newArr[++nA] = arr[i];
	}
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	ChildArrayListed(arr, n);
	return 0;
}

