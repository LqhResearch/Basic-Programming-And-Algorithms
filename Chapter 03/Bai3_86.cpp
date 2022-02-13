#include<stdio.h>
/*
	Hay dem so luong cac gia tri thoa tinh chat "lon hon tat ca cac gia tri dung truoc no"
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

	//Lon hon tat ca cac phan tu dung truoc no
bool TestArray(int arr[], int n, int vt) {
	for(int i=vt-1; i>=0; i--)
		if(arr[i] >= arr[vt])
			return false;
	return true;
}

	//Dem so luong phan tu thoa tinh chat tren.
void CountElement(int arr[], int n) {
	int count=0;
	for(int i=1; i<n; i++)
		if(TestArray(arr, n, i) == true)
			count++;
	if(count != 0)
		printf("\n%d phan tu lon hon tat cac phan tu truoc no", count);
	else
		printf("\nKhong co phan tu nao thoa dieu kien");
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	CountElement(arr, n);
	return 0;
}

