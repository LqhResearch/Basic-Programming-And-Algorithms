#include<stdio.h>
#include<math.h>
/*
	Liet ke cac gia tri thoa dieu kien lon hon tri tuyet doi cua gia tri dung lien sau.
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

	//Liet ke cac gia tri thoa dieu kien lon hon tri tuyet doi cua gia tri dung lien sau
void Listed(int arr[], int n) {
	printf("\nCac gia tri lon hon tri tuyet doi cua gia tri dung lien sau = ");
	for(int i=0; i<n-1; i++)
		if(arr[i] > abs(arr[i+1]))
			printf("%5d", arr[i]);
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	Listed(arr, n);
	return 0;
}

