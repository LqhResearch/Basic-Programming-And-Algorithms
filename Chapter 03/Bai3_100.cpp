#include<stdio.h>
/*
	Tim day con toan duong dai nhat
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

	//Tinh do dai mang con lon nhat
int MaxLengthChildArray(int arr[], int n) {
	int max=0, len=0;
	for(int i=0; i<n; i++)
		if(arr[i-1] > arr[i]) {
			len++;
			if(max < len)
				max=len;	//Gan max
			len=0;	//Reset len
		}
		else len++;
	return max;
}

	//Kiem tra mang co toan duong hay khong?
bool ToanDuong(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(arr[i] < 0)
			return false;
	return true;
}

	//Xuat mang con
void OutChildArray(int arr[], int n) {
	//Kiem tra mang con co chua gia tri max khong?
	printf("\nDong: ");
	for(int i=0; i<n; i++)
		printf("%5d", arr[i]);
}

void ChildArrayListed(int arr[], int n) {
	int max = MaxLengthChildArray(arr, n);
	int newArr[n], nA=-1;
	for(int i=0; i<n; i++) {
		if(arr[i] > arr[i+1]) {
			newArr[++nA] = arr[i];
			if(ToanDuong(newArr, nA+1) == true && nA+1==max) {
				OutChildArray(newArr, nA+1);
			}
			//Reset lai gia tri
			nA=-1;
			continue;	
		}
		if(arr[i] < arr[i+1])
			newArr[++nA] = arr[i];
	}
}

int main() {
	int arr[50], n;
	InpArray(arr, n);
	
	ChildArrayListed(arr, n);
	return 0;
}

