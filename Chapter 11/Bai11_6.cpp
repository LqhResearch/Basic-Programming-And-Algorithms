#include <iostream>
using namespace std;
/*
	Viet chuong trinh yeu cau nhap vao chuoi ky tu co chieu dai toi da la 80 ky tu.
	Nhap vao hai so nguyen duong n va p, trong chuoi tren tien hanh xoa n ky tu bat dau tai vi tri p.
*/

	/*Main function*/
int main() {
	string str;
	int n, p;
	cout << "Nhap chuoi: ";	cin >> str;
	cout << "So ki tu can xoa: ";	cin >> n;
	cout << "Vi tri bat dau: ";	cin >> p;
	str.erase(p, n);
	cout << "\nChuoi: " << str;
	return 0;
}

