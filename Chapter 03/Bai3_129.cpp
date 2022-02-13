#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;
/*
	Tao ngau nhien mang n phan tu nguyen co gia tri chua trong doan [-100, 100] va xuat mang.
	a.	Tinh tong cac so nguyen duong co trong mang.
	b.	Xoa phan tu co chi so p (p nhap tu ban phim) trong mang.
*/
	/*Xuat mang*/
void OutArray(int arr[], int n) {
	cout << endl << "Xuat mang: ";
	for(int i=0; i<n; i++)
		cout << arr[i] << "   ";
}

	/*Tao mang ngau nhien*/
void CreateArray(int arr[], int n) {
	srand(time(NULL));
	for(int i=0; i<n; i++)
		arr[i] = rand()%201 - 100;	//Sinh so ngau nhien [-100, 100]
	OutArray(arr, n);
}

	/*Tinh tong cac so nguyen duong co trong mang*/
int SumDuong(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++)
		if(arr[i] > 0)
			sum+=arr[i];
	return sum;
}

	/*Xoa phan tu co chi so p (p nhap tu ban phim) trong mang*/
void DeleteEle(int arr[], int &n) {
	int p;
	do{
		cout << "Nhap vi tri can xoa [0, " << n-1 << "]: ";
		cin >> p;
		if(p < 0 || p > n-1)
			cout << "Vi tri nay khong ton tai" << endl;
	}while(p < 0 || p > n-1);
	
	for(int i=p; i<n-1; i++)
		arr[i] = arr[i+1];
	n--;	//Xoa 1 phan tu se giam di 1 don vi
	OutArray(arr, n);
}

	/*Main function*/
int main() {
	int arr[MAX], n;
	do{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if(n <= 0)
			cout << "So luong phan tu phai > 0" << endl;
	}while(n <= 0);
	
	CreateArray(arr, n);
	cout << endl << "Tong so cac so nguyen duong: " << SumDuong(arr, n) << endl;
	DeleteEle(arr, n);
	return 0;
}

