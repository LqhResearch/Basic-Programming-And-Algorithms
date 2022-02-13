#include <iostream>
using namespace std;
/*
	Viet chuong trinh de quy chuyen doi Dec => Hex, Bin
	Vd: Input: Nhap x: 123
  		Output: Bin: 1111011
				Hex: 7B
*/
char kiTu[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	/*Decimal to Binary*/
void ToBin(int n) {
	if(n >= 2)	ToBin(n/2);
	cout << kiTu[n%2];
}

	/*Decimal to Hexadecimal*/
void ToHex(int n) {
	if(n == 0)
		return;
	else {
		cout << kiTu[n%16];
		return ToHex(n/16);
	}
}

	/*Main function*/
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	
	cout << "\nBin: ";
	ToBin(n);
	cout << "\nHex: ";
	ToHex(n);
	return 0;
}

