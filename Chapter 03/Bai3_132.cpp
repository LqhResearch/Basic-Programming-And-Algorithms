#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 50

using namespace std;
/*
	Viet chuong trinh cho phep nguoi nhap n so tuy y, nhap cho den khi nhat Ctrl+Z.
	Hay luu cac so nay thanh mot tap hop chua cac phan tu co tri phan biet.
*/
	/*Xuat mang*/
void OutArray(int arr[], int n) {
	cout << endl << "Tap hop A = { ";
	for(int i=0; i<n; i++)
		if(i != n-1) cout << arr[i] << ", ";
		else cout << arr[i] << " }";
}

	/*Kiem tra so nguyen k bat ki co ton tai trong mang hay khong?*/
bool IsMember(int arr[], int n, int k) {
	for(int i=0; i<=n; i++)
		if(arr[i] == k)
			return false;
	return true;
}

	/*Nhap mang*/
void InpArray(int arr[], int &n) {
	int temp;
	cout << "Nhap cac phan tu: ";
	for(n=0; cin >> temp && n<=MAX; )
		if(IsMember(arr, n, temp) == true) {
			arr[n] = temp;
			n++;
		}
	OutArray(arr, n);
}

	/*Main function*/
int main() {
	int arr[MAX], n;
	InpArray(arr, n);
	return 0;
}

