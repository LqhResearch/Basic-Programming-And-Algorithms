#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
/*
	Viet chuong trinh khi chay se chuyen doi tat ca ky tu thuong cua mot tap tin thanh ky tu hoa chua vao mot tap tin khac.
*/

	/*Main function*/
int main() {
	string str;
	ifstream ifs("Bai03_Lower.txt");	//Doc file
	fflush(stdin); getline(ifs, str);
	ifs.close();
	
	for(int i=0; i<str.length(); i++)	//Xu li chuyen doi
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i]-=32;
			
	ofstream ofs("Bai03_Upper.txt");	//Ghi file
	ofs << str;
	ofs.close();
	return 0;
}

