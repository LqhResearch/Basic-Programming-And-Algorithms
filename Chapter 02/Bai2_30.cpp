#include <iostream>
using namespace std;
/*
	Nhap vao ngay thang nam, sau do viet ra man hinh do la ngay thu may trong tuan.
*/
	//Tinh so thu tu tu ngay 1/1/1
int DayOfAD(int day, int month, int year) {
	if(month < 3) {
		year--;
		month+=12;
	}
	return 365*year+year/4-year/100+year/400+(153*month - 457)/5+day-306;
}

	/*Main function*/
int main() {
	int day, month, year;
	cout << "Nhap vao ngay/thang/nam: ";
	cin >> day >> month >> year;
	
	int num = DayOfAD(day, month, year) % 7;
	cout << "\nNgay: " << day << " thang " << month << " nam " << year << " la: ";
	switch(num) {
		case 0: cout << "Chu nhat"; break;
		case 1: cout << "Thu 2"; break;
		case 2: cout << "Thu 3"; break;
		case 3: cout << "Thu 4"; break;
		case 4: cout << "Thu 5"; break;
		case 5: cout << "Thu 6"; break;
		case 6: cout << "Thu 7"; break;
	}
	return 0;
}

