#include<stdio.h>
/*
	Cho mang mot chieu cac so thuc. Hay tim trong doan [a, b] chuc tat ca cac gia tri trong mang
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
void SearchChildArray(float arr[], int n);

	//Chuong trinh chinh
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	SearchChildArray(arr, n);
	return 0;
}

	/*Nhap mang so thuc*/
void InpArray(float arr[], int &n) {
	do{
		printf("Nhap so phan tu = ");
		scanf("%d", &n);
		if(n<=0)
			printf("So phan tu phai lon hon 0\n");
	}while(n<=0);
	
	printf("\n===Nhap mang===\n");
	for(int i=0; i<n; i++) {
		printf("Phan tu thu %d: ", i);
		scanf("%f", &arr[i]);
	}
	OutArray(arr, n);
}

	/*Xuat mang so thuc*/
void OutArray(float arr[], int n) {
	printf("\n===Xuat mang===\n");
	for(int i=0; i<n; i++)
		printf("%f\t", arr[i]);
}

	/*Kiem tra phan tu bat ki co ton hay truoc do hay chua*/
bool Exist(float arr[], int pre) {
	for(int i=0; i<pre; i++)
		if(arr[i] == arr[pre])
			return false;
	return true;
}

	/*Kiem tra doan [a, b]*/
bool TestDoanAB(float arr[], int start, int end, float arrB[], int vt) {
	for(int i=0; i<vt; i++)	{ //Mang arrB 
		int count = 0;
		for(int j=start; j<=end; j++)
			if(arrB[i] == arr[j])
				count++;
		if(count == 0) return false;
	}
	return true;
}

	/*Tim trong doan [a, b] chuc tat ca cac gia tri trong mang*/
void SearchChildArray(float arr[], int n) {
	//Tao cac gia tri duy nhat trong mang a
	float arrB[n];
	int vt=0;
	for(int i=0; i<n; i++)
		if(Exist(arr, i) == true) {
			arrB[vt] = arr[i];
			vt++;
		}
	OutArray(arrB, vt);
	
	//Tim trong doan [a, b]
	printf("\nDoan chua tat ca gia tri: ");
	for(int i=vt; i<=n; i++)
		for(int j=0; j<=n-i; j++)
			if(TestDoanAB(arr, j, j+i-1, arrB, vt) == true)
				printf("\n[%d, %d]", j, j+i-1);
}
