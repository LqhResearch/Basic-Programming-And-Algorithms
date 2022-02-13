#include<stdio.h>
/*
	Tinh tong tung mang con tang dan trong mang mot chieu so nguyen
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

	//Tong tung mang con tang dan
void SumChildArray(int arr[], int n) {
	int sum=0, row=-1;
	for(int i=0; i<n; i++) {
		if(arr[i-1] > arr[i]) {
			if(i != 0) {
				printf(" = %d", sum);	
				sum=0;	//Reset lai bien sum
			}
			printf("\nDong %d: %5d", ++row, arr[i]);
			sum+=arr[i];
		}
		else {
			printf("%5d", arr[i]);
			sum+=arr[i];
		}	
	}
	printf(" = %d", sum);
}


int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	SumChildArray(arr, n);
	return 0;
}

