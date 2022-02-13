#include<stdio.h>
/*
	Mang duoc goi la co "dang song" khi mot phan tu trong lon hon hoac nho hon hai phan tu xung quanh no.
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

	//Kiem tra dang song cua mang?
int TestDangSong(int arr[], int n) {
	int flag=0;
	for(int i=1; i<n-1; i++)
		if((arr[i]>arr[i-1] && arr[i]>arr[i+1]) || (arr[i]<arr[i-1] && arr[i]<arr[i+1])) {
			flag=1;
			break;
		}
	return flag;
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	if(TestDangSong(arr, n) == 1)
		printf("\nMang co dang song");
	else
		printf("\nMang khong co dang song");
	return 0;
}


