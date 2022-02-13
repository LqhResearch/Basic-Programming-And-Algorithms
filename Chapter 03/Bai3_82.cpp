#include<stdio.h>
/*
	Hay kiem tra mang mot chieu cac so nguyen co doi xung hay khong?
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

	//Kiem tra mang mot chieu cac so nguyen co doi xung?
int TestDoiXung(int arr[], int n) {
	int flag=1, arrDao[n], vt=-1;
	for(int i=n-1; i>=0; i--)	//Tao mang dao
		arrDao[++vt]=arr[i];
	for(int i=0; i<n; i++)
		if(arrDao[i] != arr[i]) {
			flag=0;
			break;
		}
	return flag;
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	if(TestDoiXung(arr, n)==1)
		printf("\nMang doi xung");
	else
		printf("\nMang khong doi xung");
	return 0;
}

