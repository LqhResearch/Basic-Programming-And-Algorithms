#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
/*
	Viet chuong trinh co hai chuc nang: ma hoa noi dung mot tap tin va giai ma noi dung tap tin duoc ma hoa.
	Luat ma hoa: 
		+	Ky tu nao co ma ASCII nho hon 64 thi chuyen ma thanh: ma ky tu do + 64
		+	Ky tu nao co ma ASCII lon hon 64 thi chuyen ma thanh: ma ky tu do - 64
*/
void OriginToEncode() {		//Ma hoa
	string str;
	ifstream ifs("Bai04_Origin.txt");	//Doc tap tin goc
	fflush(stdin); getline(ifs, str);
	ifs.close();
	
	for(int i=0; i<str.length(); i++)	//Ma hoa
		if(str[i] > 64)
			str[i]-=64;
		else
			str[i]+=64;
			
	ofstream ofs("Bai04_Encode.txt");	//Ghi vao tap tin ma hoa
	ofs << str;
	ofs.close();
}

void EncodeToOrigin() {		//Giai ma
	string str;
	ifstream ifs("Bai04_Encode.txt");	//Doc tap tin ma hoa
	fflush(stdin); getline(ifs, str);
	ifs.close();
	
	for(int i=0; i<str.length(); i++)	//Giai ma
		if(str[i] > 64)
			str[i]+=64;
		else
			str[i]-=64;
			
	ofstream ofs("Bai04_Origin.txt");	//Ghi vao tap tin goc
	ofs << str;
	ofs.close();
}

	/*Main function*/
int main() {
	int choice;
	do{
		cout << "\n1. Ma hoa.";
		cout << "\n2. Giai ma.";
		cout << "\n >> Hay chon (1 hoac 2): ";
		cin >> choice;
		if(choice != 1 && choice != 2)
			cout << "\nChuc nang nay khong ton tai";
	}while(choice != 1 && choice != 2);
	
	switch(choice) {
		case 1:{
			OriginToEncode();
			break;
		}
		case 2:{
			EncodeToOrigin();
			break;
		}
	}
	return 0;
}

