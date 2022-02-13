#include <iostream>
using namespace std;
/*
	Viet chuong trinh nhap vao so gio, xuat ra so tuong duong tinh theo tuan, theo ngay va theo gio.
*/

	/*Main function*/
int main() {
	int week = 0, day = 0, hour;
	cout << "So gio: ";
	cin >> hour;
	
	week = hour/168;
	day = (hour - (week*168)) / 24;
	hour -= (week*168 + day*24);
	cout << week << " tuan, " << day << " ngay, " << hour << " gio";
	return 0;
}

