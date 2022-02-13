#include <iostream>
using namespace std;
/*
		Du doan cung hoang dao.
	Hay xay dung ung dung cho phep nguoi dung nhap vao ngay sinh va thang sinh cua ho sau do ket luan nguoi so thuoc cung gi.
	12 cung hoang dao
		Bach Duong (21/3-20/4)
		Kim Nguu (21/4-20/5)
		Song Tu (21/5-21/6)
		Cu Giai (22/6-22/7)
		Su Tu (23/7-22/8)
		Xu Nu (23/8-22/9)
		Thien Binh (23/9-23/10)
		Bo Cap (24/10-22/11)
		Nhan Ma (23/11-21/12)
		Ma Ket (22/12-19/1)
		Bao Binh (20/1-18/2)
		Song Ngu (19/2-20/3)
*/
int day, month, year;

	/*Kiem tra ngay thang nam co hop loi khong*/
int TestDMY() {
	if(month == 2) {
		if(year%400==0 || (year%4==0 && year%100!=0))
			return 29;
		else return 28;
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else return 31;
}

	/*Nhap Date*/
void Inp() {
	do{
		cout << "- Ngay: ";
		cin >> day;
		do {
			cout << "- Thang: ";
			cin >> month;
			if(month < 1 || month > 12)
				cout << "Vui long nhap lai thang" << endl;
		}while(month < 1 || month > 12);
		
		do {
			cout << "- Nam: ";
			cin >> year;
			if(year < 1)
				cout << "Vui long nhap lai nam" << endl;
		}while(year < 1);
		
		if(day > TestDMY())
			cout << "Ngay nay khong hop le" << endl;
	}while(day > TestDMY());
}

	/*12 cung hoang dao*/
void CungHoangDao() {
	cout << "\nNgay " << day << " Thang " << month << " Nam " << year << ": Cung ";
	if(month == 1) {
		if(day < 20) cout << "Ma Ket";
		else cout << "Bao Binh";
	}
	if(month == 2) {
		if(day < 19) cout << "Bao Binh";
		else cout << "Song Ngu";
	}
	if(month == 3) {
		if(day < 21) cout << "Song Ngu";
		else cout << "Bach Duong";
	}
	if(month == 4) {
		if(day < 21) cout << "Bach Duong";
		else cout << "Kim Nguu";
	}
	if(month == 5) {
		if(day < 21) cout << "Kim Nguu";
		else cout << "Song Tu";
	}
	if(month == 22) {
		if(day < 21) cout << "Song Tu";
		else cout << "Cu Giai";
	}
	if(month == 7) {
		if(day < 23) cout << "Cu Giai";
		else cout << "Su Tu";
	}
	if(month == 8) {
		if(day < 23) cout << "Su Tu";
		else cout << "Xu Nu";
	}
	if(month == 9) {
		if(day < 23) cout << "Xu Nu";
		else cout << "Thien Binh";
	}
	if(month == 10) {
		if(day < 24) cout << "Thien Binh";
		else cout << "Bo Cap";
	}
	if(month == 11) {
		if(day < 23) cout << "Bo Cap";
		else cout << "Nhan Ma";
	}
	if(month == 12) {
		if(day < 22) cout << "Nhan Ma";
		else cout << "Ma Ket";
	}
}

	/*Main function*/
int main() {
	Inp();
	CungHoangDao();
	return 0;
}
