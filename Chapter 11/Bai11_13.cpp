#include <iostream>
#include <cstring>
using namespace std;
/*
	Viet chuong trinh nhap hai chuoi va xac dinh xem chung co duoc tao ra voi cung cac ky tu hay khong.
	Nhu "dear" va "reader" la hai chuoi tao tu cung ki tu a, d, e, r.
	Vd: Input: Nhap chuoi a: dear
        		Nhap chuoi b: reader
       	Output:Tao tu cung cac ky tu
*/
	/*Nhap chuoi*/
void Input(string &a, string &b) {
	cout << "- Nhap chuoi a = ";
	getline(cin, a);
	cout << "- Nhap chuoi b = ";
	getline(cin, b);
}

	/*Kiem tra 1 phan tu co ton tai trong chuoi hay khong?*/
bool TestChar(char c, string str) {
	for(int i=0; i<str.length(); i++)
		if(str[i] == c)
			return true;
	return false;
}

	/*Kiem tra cac ki tu cua chuoi 1 co trong chuoi 2 hay khong*/
bool Test(string a, string b) {
	for(int i=0; i<a.length(); i++)
		if(TestChar(a[i], b) == false)
			return false;
	return true;
}

	/*Main function*/
int main() {
	string str1, str2;
	Input(str1, str2);
	
	if((Test(str1, str2)==true) && (Test(str2, str1)==true))
		cout << "Tao tu cung cac ky tu";
	else cout << "Tao tu khong cung cac ky tu";
	return 0;
}

