#include <iostream>
using namespace std;
/*
	Nhap mot vao chuoi so nhi phan. Tim trong do chuoi con dai nhat chua toan cac so 0.
*/
int Count(string str, int start) {
	int count = 0;
	for(int i=start; i<str.length(); i++)
		if(str[i] == '0')
			count++;
		else return count;
}

	/*Tim chuoi nhi phan*/
void Search(string str) {
	int max = 0;
	for(int i=0; i<str.length(); i++)
		if(str[i]=='0') {
			int len = Count(str, i);
			max = (len > max) ? len : max;
		}
	cout << "Chuoi so 0 dai nhat: ";
	for(int i=1; i<=max; i++)
		cout << "0";		
}

	/*Main function*/
int main() {
	string str;
	cout << "Nhap so nhi phan: ";
	getline(cin, str);
	
	Search(str);
	return 0;
}

