#include<stdio.h>
/*
	Cho mang so thuc co nhieu hon hai gia tri va cac gia tri khac nhau liet ke thanh tung doi mot.
	Hay viet ham liet ke tat cac cac gia tri (a, b) trong mang thoa dieu kien a <= b
*/
void InpArray(float arr[], int &n);
void OutArray(float arr[], int n);
void Listed(float arr[], int n);

	/*Main function*/
int main() {
	int n;
	float arr[50];
	InpArray(arr, n);
	
	Listed(arr, n);
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

	/*Kiem tra su xuat hien cua phan tu*/
bool Exist(float arr[], int pre) {
	for(int i=0; i<pre; i++)
		if(arr[i] == arr[pre])
			return false;
	return true;
}

	/*Liet ke tat cac cac gia tri (a, b) trong mang thoa dieu kien a <= b*/
void Listed(float arr[], int n) {
	float arrB[n];
	int vt=0;
	for(int i=0; i<n; i++)
		if(Exist(arr, i) == true) {
			arrB[vt] = arr[i];
			vt++;
		}
	
	//Liet ke (a, b)
	printf("\nCac cap doi: ");
	for(int i=0; i<vt-1; i++)
		for(int j=i+1; j<vt; j++)
			printf("\n(%f\t%f)",arrB[i], arrB[j]);
}
