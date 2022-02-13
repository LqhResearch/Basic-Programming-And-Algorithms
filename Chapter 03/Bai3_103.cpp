#include<stdio.h>
/*
	Tim mang con toan duong co tong lon nhat trong mang mot chieu so thuc
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
float SumChildArray(float arr[], int n, int start, int end);
bool TestChildArratToanDuong(float arr[], int n, int start, int end);
void SearchMaxChildArray(float arr[], int n);

	//Chuong trinh chinh
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	SearchMaxChildArray(arr, n);
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

	/*Kiem tra mang con co toan duong hay khong*/
bool TestChildArrayToanDuong(float arr[], int n, int start, int end) {
	for(int i=start; i<=end; i++)
		if(arr[i] < 0) //So am
			return false;
	return true;
}

	/*Tong mang con so thuc*/
float SumChildArray(float arr[], int n, int start, int end) {
	float sum = 0;
	for(int i=start; i<=end; i++)
		sum+=arr[i];
	return sum;
}

	/*Xuat mang con*/
void OutChild(float arr[], int n, int start, int end) {
	printf("\n");
	for(int i=start; i<=end; i++)
		printf("%f\t", arr[i]);
}

	/*Tim mang con toan duong co tong lon nhat trong mang mot chieu so thuc*/
void SearchMaxChildArray(float arr[], int n) {
	float max;
	for(int i=1; i<=n; i++)		//So phan tu cua mang con
		for(int j=0; j<=n-i; j++)	//Duyet mang
			if(TestChildArrayToanDuong(arr, n, j, j+i-1) == true) {
				float sum = SumChildArray(arr, n, j, j+i-1);
				if(sum>max || (i==1 && j==0))
					max = sum;
			}
	
	printf("\nMang con co tong lon nhat: ");
	for(int i=1; i<=n; i++)		//So phan tu cua mang con
		for(int j=0; j<=n-i; j++) 	//Duyet mang
			if(TestChildArrayToanDuong(arr, n, j, j+i-1) == true)
				if(max == SumChildArray(arr, n, j, j+i-1))
					OutChild(arr, n, j, j+i-1);
}
