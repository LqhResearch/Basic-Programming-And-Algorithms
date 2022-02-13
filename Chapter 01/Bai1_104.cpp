/**************************************************************
 * Author: QHung
 * Create Date: 15/12/2020
 * Modify Date: 15/12/2020
 **************************************************************/

/**************************************************************
 * Viet ham kiem tra mot so co phai la so tam hoa hay khong?
 * Biet rang: So tam hoa la so nguyen co 3 chu so sao cho tich cua 3 chu so bang tong cua 3 chu so.
 * Vi du: 1*2*3 = 1+2+3
 **************************************************************/
#include <iostream>
using namespace std;

	/*Dem so luong chu so*/
int CountCS(int n) {
	int count = 0;
	while(n != 0) {
		count++;
		n/=10;
	}
	return count;
}

	/*Tong cac chu so*/
int SumCS(int n) {
	int sum = 0;
	while(n != 0) {
		sum+=(n%10);
		n/=10;
	}
	return sum;
}

	/*Tich cac chu so*/
int MultiCS(int n) {
	int mul = 1;
	while(n != 0) {
		mul*=(n%10);
		n/=10;
	}
	return mul;
}

	/*Main function*/
int main() {
	int n;
	do {
		cout << "- Nhap so: ";
		cin >> n;
		if(n <= 0)
			cout << "Vui long nhap so nguyen duong." << endl;
	}while(n <= 0);
	
	if(CountCS(n) != 3) {
		cout << n << " khong phai la so tam hoa";
		return 0;
	}
	if(SumCS(n) == MultiCS(n))
		cout << n << " la so tam hoa";
	else cout << n << " khong phai la so tam hoa";
	return 0;
}

