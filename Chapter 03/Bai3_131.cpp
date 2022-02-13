#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;
/*
	Tao ngau nhien mang n phan tu nguyen co gia tri chua trong doan [-100, 100] va xuat mang.
	a.	Dem so phan tu chia het cho 4 va co chu so tan cung la 6.
	b.	Thay cac phan tu le bang 2 lan gia tri cua no.
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

	/*Dem so phan tu chia het cho 4 va co chu so tan cung la 6*/
int Count(int arr[], int n) {
	int count = 0;
	for(int i=0; i<n; i++)
		if(arr[i]%4==0 && (arr[i]%10==6 || arr[i]%10==-6))
			count++;
	return count;
}

	/*Thay cac phan tu le bang 2 lan gia tri cua no*/
void Replace(int arr[], int n) {
	for(int i=0; i<n; i++)
		if(arr[i]%2!=0)
			arr[i]*=2;
	cout << "\nThay cac phan tu le bang 2 lan gia tri cua no: ";
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
	cout << endl << Count(arr, n) << " phan tu chia het cho 4 va co tan cung la 6" << endl;
	Replace(arr, n);
	return 0;
}

