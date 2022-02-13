#include <iostream>
using namespace std;
/*
	Viet chuong trinh nhap vao thong tin cua 1 ca nhan (Ho ten, tong thu nhap nam, so nguoi phu thuoc).
	Tinh va xuat thue thu nhap ca nhan phai tra theo qui dinh sau:
	Thu nhap chiu thue = Tong thu nhap nam - 4 tr - So nguoi phu thuoc*1,6 tr
		Thu nhap chiu thue (trieu)				Thue xuat (%)
			Den 60									5
			Tren 60 den 120							10
			Tren 120 den 216						15
			Tren 216 den 384						20
			Tren 384 den 624						25
			Tren 624 den 960						30
			Tren 960								35
*/
	/*Nhap thong tin cua khach hang*/
void NhapTT(string &fullname, int &totalYear, int &numPer) {
	cout << "- Ho ten: ";
	getline(cin, fullname);
	cout << "- Tong thu nhap nam (trieu): ";
	cin >> totalYear;
	cout << "- So nguoi phu thuoc: ";
	cin >> numPer;
}

	/*Thue thu nhap*/
float PersonalTax(int totalYear, int numPer) {
	float tax = totalYear - 4 - numPer*1.6;
	
	if(tax > 0) {
		if(tax >= 60) return tax*0.05;
		else if(tax > 60 && tax <= 120) return tax*0.1;
		else if(tax > 120 && tax <= 216) return tax*0.15;
		else if(tax > 216 && tax <= 384) return tax*0.20;
		else if(tax > 384 && tax <= 624) return tax*0.25;
		else if(tax > 624 && tax <= 960) return tax*0.30;
		else return tax*0.35;
	}
	else return 0;
}

	/*Thue ca nhan*/
void XuatTT(string fullname, int totalYear, int numPer) {
	cout << "\n==========Thue Ca Nhan==========" << endl;
	cout << "- Ho ten: " << fullname << endl;
	cout << "- Tong thu nhap nam: " << totalYear*1000000 << " d" << endl;
	cout << "- So nguoi phu thuoc: " << numPer << " nguoi" << endl;
	cout << "- Thue ca nhan: " << PersonalTax(totalYear, numPer)*1000000 << " d" << endl;
}

	/*Main function*/
int main() {
	string fullname;
	int totalYear, numPer;
	NhapTT(fullname, totalYear, numPer);
	XuatTT(fullname, totalYear, numPer);
	return 0;
}

