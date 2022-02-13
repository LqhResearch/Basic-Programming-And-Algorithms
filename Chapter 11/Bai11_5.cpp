#include <iostream>
using namespace std;
/*
	Viet chuong trinh yeu cau nhap vao hai chuoi ky tu, moi chuoi co chieu dai toi da 80 ky tu. 
	Chen chuoi 2 vao chuoi 1 tai vi tri thu k.
*/

	/*Main function*/
int main() {
	string str1, str2, temp;
	int local;
	cout << "Nhap chuoi: ";
	getline(cin, str1);
	cout << "Nhap chuoi: ";
	getline(cin, str2);
	cout << "Nhap vi tri can chen: ";
	cin >> local;
	
	str1.insert(local, str2);
	cout << "\nGhep chuoi: " << str1;
	return 0;
}

