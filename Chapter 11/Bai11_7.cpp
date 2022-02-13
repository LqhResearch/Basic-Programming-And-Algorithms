#include <iostream>
using namespace std;
/*
	Viet chuong trinh nhap mot chuoi va mot ky tu. Tim tat ca cac vi tri xuat hien cua ky tu c trong mot chuoi s.
*/

	/*Main function*/
int main() {
	string str;
	char c;
	cout << "Nhap chuoi: ";	cin >> str;
	cout << "Ky tu can tim: "; cin >> c;
	cout << "Vi tri xuat hien: ";
	for(int i=0; i<str.length(); i++)
		if(str[i] == c)
			cout << i << "  ";
	return 0;
}

