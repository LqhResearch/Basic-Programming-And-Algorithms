#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;
/*
	Tao ngau nhien mang n phan tu nguyen duong co gia tri trong doan [10, 20] va xuat mang.
	a.	Kiem tra xem tung cac so chan o vi tri le co bang tong cac so le o vi tri chan hay khong?
	b.	Xac dinh xem mang cac cap so nguyen to cung nhau (coprime) nao khong?
	Biet rang: Hai so nguyen duong a va b duoc goi la hai so nguyen to cung nhau neu uoc so chung lon nhat cua hai so a va b la 1.
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
		arr[i] = rand()%11 + 10;	//Sinh so ngau nhien [-100, 100]
	OutArray(arr, n);
}

	/*Kiem tra xem tung cac so chan o vi tri le co bang tong cac so le o vi tri chan hay khong?*/
void TestEqual(int arr[], int n) {
	int soChanViTriLe = 0, soLeViTriChan = 0;
	for(int i=0; i<n; i++) {
		if(arr[i]%2==0 && i%2!=0)	//so chan vi tri le
			soChanViTriLe+=arr[i];
		if(arr[i]%2!=0 && i%2==0)	//so le vi tri chan
			soLeViTriChan+=arr[i];
	}
	if(soLeViTriChan == soChanViTriLe)
		cout << "\nTong so chan vi tri le (" << soChanViTriLe << ") bang Tong so le vi tri chan (" << soLeViTriChan << ")";
	else cout << "\nTong so chan vi tri le (" << soChanViTriLe << ") khac Tong so le vi tri chan (" << soLeViTriChan << ")";
}

	/*Uoc so chung lon nhat*/
int USCLN(int a, int b) {
	int us;
	for(int i=1; i<a; i++)
		if(a%i==0 && b%i==0)
			us = i;
	return us;
}

	/*Cac cap so nguyen to cung nhau*/
void Coprime(int arr[], int n) {
	cout << "\nCac cap so nguyen to cung nhau: ";
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(USCLN(arr[i], arr[j]) == 1)
				cout << endl << "(" << arr[i] << ", " << arr[j] << ")";
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
	TestEqual(arr, n);	
	Coprime(arr, n);
	return 0;
}

