#include <iostream>
using namespace std;
/*
	Nhap vao mot chuoi ky tu va kiem tra xem chuoi co bao nhieu so am
*/
int CountInString(string str) {
	int count = 0;
	for(int i=0; i<str.length(); i++)
		if(str[i] == '-' && str[i+1] >= '0' && str[i+1] <= '9')
			count++;
	return count;
}

	/*Main function*/
int main() {
	string str;
	cout << "Nhap chuoi: ";
	fflush(stdin);	getline(cin, str);
	
	cout << "\nXuat chuoi: " << str << endl;
	cout << CountInString(str) << " so am.";
	return 0;
}

