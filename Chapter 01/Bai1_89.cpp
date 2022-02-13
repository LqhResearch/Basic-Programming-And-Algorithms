#include <iostream>
#include <cstdlib>
using namespace std;
/*
	Viet chuong trinh in lich cua mot thang trong nam hoac in lich cua tat ca thang trong mot nam do.
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

	/*In ra lich mot nam*/
void OutputOfYear() {
	int day, month, year;	//Ngay / thang / nam
	cout << "Nam = ";
	cin >> year;
	
	int thu = DayOfAD(1, 1, year)%7;	//Thu dau tien cua 1/1/year
	cout << "=====Lich nam " << year << "=====";
	for(int i=1; i<=12; i++) { //12 thang trong nam
		int max = DayOfMonth(i, year);	//So luong ngay cua thang
		cout << "\nThang " << i << " : " << endl;
		cout << "  T2  T3  T4  T5  T6  T7  CN" << endl;
		for(int j=1; j<thu; j++)
			cout << "    ";
		for(int k=1; k<=max; k++) {
			if(thu == 7) thu = 0;
			if(thu == 1) cout << endl;
			
			if(k < 10) cout << "   " << k;
			else cout << "  " << k;
			thu++;
		}
	}
}

	/*In ra lich mot thang*/
void OutputOfMonth() {
	int day, month, year;	//Ngay / thang / nam
	cout << "Thang = ";
	cin >> month;
	cout << "Nam = ";
	cin >> year;
	
	int thu = DayOfAD(1, month, year)%7;	//Thu dau tien cua 1/month/year
	cout << "=====Lich thang " << month << " nam " << year << "=====" << endl;
	int max = DayOfMonth(month, year);	//So luong ngay cua thang
	cout << "  T2  T3  T4  T5  T6  T7  CN" << endl;
	for(int i=1; i<thu; i++)
		cout << "    ";
	for(int j=1; j<=max; j++) {
		if(thu == 7) thu = 0;
		if(thu == 1) cout << endl;
		
		if(j < 10) cout << "   " << j;
		else cout << "  " << j;
		thu++;
	}
}

	/*menu*/
void menu() {
	int choice;
	cout << endl;
	cout << "1. In ra lich mot nam" << endl;
	cout << "2. In ra lich mot thang" << endl;
	cout << "0. Thoat" << endl;
	cout << " >> Hay lua chon: ";
	cin >> choice;
	
	switch(choice) {
		case 1:{
			OutputOfYear();
			break;
		}
		case 2:{
			OutputOfMonth();
			break;
		}
		case 0: exit(0);
	}
}

	/*Main function*/
int main() {
	do{
		menu();
	}while(true);
	return 0;
}

