#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
	Viet chuong trinh nhap vao chuoi ky tu co dai toi 80 ky tu. Khong phan biet chu hoa, chu thuong:
	a.	Kiem tra xem chuoi co doi xung hay khong?
	b.	Nhap vao mot chuoi ky tu roi tien hanh xoa het cac ky tu giong voi ky tu do trong chuoi tren.
	Vd: Input: Nhap chuoi: Stressed No tips Spit on desserts
       Output: Chuoi doi xung
				Xoa ky tu nao? s
				treed? No tip? pit on deert!
*/
bool Compare(string str, string temp) {
	int len1 = str.length();
	int len2 = temp.length();
	int len = len1 > len2 ? len1 : len2;
	for(int i=0; i<len; i++)
		if((str[i] != temp[i]) && (str[i] != temp[i]+32) && (str[i] != temp[i]-32))
			return false;
	return true;
}

void DeleteChar(string str) {
	char c;
	cout << "\n- Nhap ki tu can xoa: ";
	cin >> c;
	if(c >= 'A' && c <= 'Z') c-=32;
	for(int i=0; i<str.length(); i++) {
		if(str[i] >= 'A' && str[i] <= 'Z')
			if(str[i] == c || str[i] == c-32) {
				str.erase(str.begin()+i);
				i--;
			}
		if(str[i] == c) {
				str.erase(str.begin()+i);
				i--;
		}
	}
	cout << "Chuoi da xoa ki tu " << c << " = " << str;
}

	/*Main function*/
int main() {
	string str;
	cout << "- Nhap chuoi: ";
	getline(cin, str);
	
	string temp = str;
	reverse(temp.begin(), temp.end());	//Dao chuoi temp thuoc thu vien algorithm
	if(Compare(str, temp) == true)
		cout << "Chuoi doi xung";
	else cout << "Chuoi khong doi xung";
	
	DeleteChar(str);
	return 0;
}

