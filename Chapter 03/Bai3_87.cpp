#include<stdio.h>
/*
	Hay cho biet tat ca cac phan tu trong mang a co ton tai trong mang b hay khong?
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
		printf("\nNhap so phan tu = ");
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

	//Kiem tra phan tu a trong mang b
bool CheckElement(int arr[], int n, int ele) {
	for(int i=0; i<n; i++)	//Mang b
		if(arr[i] == ele)
			return true;
	return false;
}

	//Kiem tra 2 mang
void TestArray(int arr1[], int arr2[], int n1, int n2) {
	bool check=true;
	for(int i=0; i<n1; i++)	//Mang a
		if(CheckElement(arr2, n2, arr1[i]) == false) {
			check=false;
			break;
		}
	if(check==true)
		printf("\nTat ca cac phan tu a ton tai trong mang b");
	else
		printf("\nTat ca cac phan tu a khong ton tai trong mang b");
}

int main() {
	int arr1[50], arr2[50], n1, n2;
	InpArray(arr1, n1);
	InpArray(arr2, n2);
	
	TestArray(arr1, arr2, n1, n2);
	return 0;
}

