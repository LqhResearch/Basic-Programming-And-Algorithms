#include<stdio.h>
/*
	Liet ke va dem tat ca cac mang con tang dan co do dai lon hon 2 trong mang 1 chieu so nguyen
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

int CountChildArray(int arr[], int n, int head, int &tail) {
	for(int i=head; i<n; i++)
		if(arr[i] > arr[i+1]) {	//Vi tri ngung tang dan mang con
			tail=i+1;
			break;
		}
	return tail-head;	//So phan tu tang dan
}

	//Liet ke cac mang con
void ChildArrayListed(int arr[], int n) {
	int child=0, tail=0;
	for(int i=0; i<n; i++) {
		if(i == tail) {
			int kc = CountChildArray(arr, n, i, tail);	//Tim vi tri truoc khi het mang tang dan
			if(kc == 1) continue;		
			printf("\nMang con %d: ", ++child);
		}
		if(i < tail) printf("%5d", arr[i]);
	}
}

	//Chuong trinh chinh
int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	ChildArrayListed(arr, n);
	return 0;
}

