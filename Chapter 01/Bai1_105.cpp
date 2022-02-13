/**************************************************************
 * Author: QHung
 * Create Date: 15/12/2020
 * Modify Date: 15/12/2020
 **************************************************************/

/**************************************************************
 * Viet ham kiem tra mot so co phai la so phong phu hay khong?
 * Biet rang: So phong phu la so nguyen ma tong cac uoc so cua do (khong ke chinh no) lon hon so do.
 * Vi du: 12 co tong uoc so (khong ke 12) la 1 + 2 + 3 + 4 + 6 = 16 > 12.
 **************************************************************/
#include <iostream>
using namespace std;

	/*Tong uoc so cua n (khong ke chinh no)*/
int SumUocSo(int n) {
	int sum;
	for(int i=1; i<n; i++)
		if(n%i==0)
			sum+=i;
	return sum;
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
	
	if(SumUocSo(n) > n)
		cout << n << " la so phong phu";
	else cout << n << " khong phai la so phong phu";
	return 0;
}

