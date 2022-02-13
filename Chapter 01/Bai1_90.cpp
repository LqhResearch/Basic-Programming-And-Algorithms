#include <iostream>
using namespace std;
/*
	Viet chuong trinh tao lich cho 5 ban: A, B, C, D, E.
	Sau do nhap mot thang trong nam va in lich truc cua thang do.
	Luu y 5 ban truc lan luat theo thu tu tren, ngay Chu nhat khong truc va ban A se truc ngay dau tien cua thang.
*/
	/*So ngay cua thang*/
int DayOfMonth(int m, int y) {
	if(m==4 || m==6 || m==9 || m==11)
		return 30;
	else if(m==2) {
		if(y%400==0 || (y%4==0 && y%100!=0))
			return 29;
		else return 28;
	}
	else return 31;
}

	/*Tinh so thu tu tu ngay 1/1/1*/
int DayOfAD(int day, int month, int year) {
	if(month < 3) {
		year--;
		month+=12;
	}
	return 365*year+year/4-year/100+year/400+(153*month - 457)/5+day-306;
}

	/*Main function*/
int main() {
	string Ban = "ABCDE";	int local = 0;
	int day, month, year;	//Ngay / thang / nam
	cout << "Thang = ";
	cin >> month;
	cout << "Nam = ";
	cin >> year;
	
	int thu = DayOfAD(1, month, year)%7;	//Thu dau tien cua 1/month/year
	cout << "=====Lich thang " << month << " nam " << year << "=====" << endl;
	int max = DayOfMonth(month, year);	//So luong ngay cua thang
	cout << "     T2     T3     T4     T5     T6     T7     CN" << endl;
	for(int i=1; i<thu; i++)
		cout << "       ";
	for(int j=1; j<=max; j++) {
		if(thu == 7) thu = 0;
		if(thu == 1) cout << endl;
		if(local == 5) local = 0;
		
		if(thu != 0) {
			if(j < 10) cout << "   " << j << "[" << Ban[local++] << "]";
			else cout << "  " << j << "[" << Ban[local++] << "]";
		}
		else {
			if(j < 10) cout << "      " << j;
			else cout << "     " << j;
		}
		thu++;
	}
	return 0;
}

