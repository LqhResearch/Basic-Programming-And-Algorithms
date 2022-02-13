#include<stdio.h>
/*
	Cho mang mot chieu cac so nguyen. Hay viet ham tim so chan lon nhat va nho hon moi gia tri le trong mang.
	Neu khong co gia tri thoa dieu kien thi tra ve "Khong tim thay".
*/
void InpArray(int arr[], int &n);
void OutArray(int arr[], int n);
void SearchValue(int arr[], int n);

	/*Main function*/
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SearchValue(arr, n);
	return 0;
}

	/*Nhap mang so nguyen*/
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

	/*Xuat mang so nguyen*/
void OutArray(int arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

	/*Tim so chan lon nhat va nho hon moi gia tri le trong mang*/
void SearchValue(int arr[], int n) {
	int minSoLe, count=0, maxSoChan;
	for(int i=0; i<n; i++)	//Tim so le nho nhat
		if(arr[i]%2==1 && (arr[i] < minSoLe || count==0)) {
			minSoLe = arr[i];
			count++;
		}
			
	count=0;
	for(int i=0; i<n; i++)
		if(arr[i]%2==0 && arr[i] < minSoLe && (arr[i] > maxSoChan || count==0)) {
			maxSoChan = arr[i];
			count++;
		}
	if(count != 0)
		printf("\nGia tri lon nhat va nho hon moi gia tri le: %d", maxSoChan);
	else printf("\nKhong tim thay");
}
