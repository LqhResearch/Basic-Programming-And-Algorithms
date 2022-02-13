#include <iostream>
using namespace std;
/*
	Viet chuong trinh cho phep nhap vao ma khach hang, so tai khoan. Cho nguoi dung chon 1 trong 3 loai Grab:
		1: Grab Car
		2: Grab SUV
		3: Grab Black
	Cho nguoi dung nhap vao so KM di duoc va thoi gian cho.
	1.	Tinh tong tien di duoc.
	2.	In hoa don chi tiet nhu bieu mau.
*/
int Grab[3][4] = {	{8500, 7500, 7000, 2000}, //Grab Car
					{9000, 8500, 8000, 3000}, //Grab SUV
					{10000, 9500, 9000, 3500}  //Grab Black
				};

	/*So KM di duoc va thoi gian cho*/
void NhapTT(float &km, int &minute) {
	cout << "So kw di duoc: ";	cin >> km;
	cout << "Thoi gian cho: ";	cin >> minute;
}

	/*In chi tiet*/
void Print(float km, int minute, int money, int reduce, int type) {
	cout << "km = " << km;
	cout << "\n\t==========HOA DON==========" << endl;
	cout << "Chi tiet\tKm\tHoa don\tThanh tien" << endl;
	if(km <= 1)
		cout << "Km dau tien\t" << km << "\t" << Grab[type][0] << "\t" << km*Grab[type][0] << endl;
	else cout << "Km dau tien\t" << 1 << "\t" << Grab[type][0] << "\t" << Grab[type][0] << endl;
	if(km > 1 && km < 19)
		cout << "Tu 1 den " << km << "\t" << km-1 << "\t" << Grab[type][1] << "\t" << (km-1)*Grab[type][1] << endl;
	if(km >= 19) {
		cout << "Tu 1 den 19\t" << 18 << "\t" << Grab[type][1] << "\t" << 18*Grab[type][1] << endl;
		cout << "Tu 19 den " << km << "\t" << km-19 << "\t" << Grab[type][2] << "\t" << (km-19)*Grab[type][2] << endl;
	}
	cout << "Thoi gian cho: -" << reduce << endl;
	cout << "\t\t\tTong tien = " << money-reduce << endl;
}

	/*Tinh tien cac loai grab*/
void SumMoney(int type) {
	float km, km1;
	int minute, money, reduce=0;
	NhapTT(km, minute);
	km1 = km;
	if(minute > 3)
		reduce = (minute-3)/3*Grab[type][3];
	if(km > 18) {
		money=(km-19)*Grab[type][2];
		km = 19;
	}
	if(km >= 1) {
		money+=(km-1)*Grab[type][1];
		km = 1;
	}
	money+=km*Grab[type][0];
	Print(km1, minute, money, reduce, type);
}

	/*Main function*/
int main() {
	int choice;
	do{
		cout << "\n\t==========Grab==========" << endl;
		cout << "1. Grab Car" << endl;
		cout << "2. Grab SUV" << endl;
		cout << "3. Grab Black" << endl;
		cout << " >> Hay chon: ";
		cin >> choice;
		if(choice < 1 && choice > 3)
			cout << "Khong co loai Grab nay" << endl;
	}while(choice < 1 && choice > 3);
	SumMoney(choice-1);
	return 0;
}

