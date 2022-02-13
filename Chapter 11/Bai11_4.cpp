#include <iostream>
using namespace std;
/*
	Viet chuong trinh nhap vao mot chuoi toi da 255 ky tu. Dem so tu co trong chuoi biet giua cac tu co ki tu " ", "."
	hoac ",", khong co ki tu dac biet.
*/

	/*Main function*/
int main() {
	string str;
	cout << "Nhap chuoi: ";
	getline(cin, str);
	
	int count = 0;
	for(int i=0; i<str.length(); i++)
		if(str[i] == ' ')
			count++;
	cout << "\nChuoi co " << count+1 << " tu";
	return 0;
}

