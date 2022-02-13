#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;
/*
	Author: LQH
	Date: 22/11/20 19:09
	Description: Bài 12.6 :	Xet chuong trinh do ve so.
*/
void input();
int lastNum(int n);
void readToFile();
int stringToInt(string str);
bool lotteryTickets();
int giaiKhuyenKhich(string s);

int n;
string veSo[20];

	/*Main function*/
int main() {
	do{
		input();
	readToFile();
	if(lotteryTickets() == true)
		cout << "Chuc ban may man lan sau." << endl;
	}while(true);
	
	return 0;
}

	/*Nhap so*/
void input() {
	cout << "- Nhap so: ";
	cin >> n;
}

	/*Lay cac chu so cuoi*/
int lastNum(int chuSo) {
	int lt = pow(10, n);
	return n%lt;
}

	/*Lay du lieu tu file ra*/
void readToFile() {
	int i = 0;
	ifstream ifs("Bai06.txt");
	while(!ifs.eof()) {
		fflush(stdin);
		getline(ifs, veSo[i]);
		i++;
	}
	ifs.close();
}

	/*Ep kieu chuoi thanh so nguyen*/
int stringToInt(string str) {
	int sum = 0, vt = 0, len = str.length();
	while(vt < len) sum = sum*10 + (str[vt++] - 48);
	return sum;
}

	/*Do ve so*/
bool lotteryTickets() {
	if(stringToInt(veSo[0]) == n%100)
		cout << "Trung Giai tam: 100.000 d" << endl;
	else if(stringToInt(veSo[1]) == n%1000)
		cout << "Trung Giai bay: 200.000 d" << endl;
	else if((stringToInt(veSo[2]) == n%10000) || (stringToInt(veSo[3]) == n%10000) || (stringToInt(veSo[4]) == n%10000))
		cout << "Trung Giai sau: 400.000 d" << endl;
	else if(stringToInt(veSo[5]) == n%10000) 
		cout << "Trung Giai nam: 1.000.000 d" << endl;
	else if((stringToInt(veSo[6]) == n%100000) || (stringToInt(veSo[7]) == n%100000) || (stringToInt(veSo[8]) == n%100000) ||
			(stringToInt(veSo[9]) == n%100000) || (stringToInt(veSo[10]) == n%100000) || (stringToInt(veSo[11]) == n%100000) ||
			(stringToInt(veSo[12]) == n%100000))
		cout << "Trung Giai tu: 3.000.000 d" << endl;
	else if((stringToInt(veSo[13]) == n%100000) || (stringToInt(veSo[14]) == n%100000))
		cout << "Trung Giai ba: 10.000.000 d" << endl;
	else if(stringToInt(veSo[15]) == n%100000)
		cout << "Trung Giai nhi: 15.000.000 d" << endl;
	else if(stringToInt(veSo[16]) == n%100000)
		cout << "Trung Giai nhat: 30.000.000 d" << endl;
	else if(stringToInt(veSo[17]) == n%1000000)
		cout << "Trung Giai dac biet: 2.000.000.000 d" << endl;
	else if(stringToInt(veSo[17])%100000 == n%100000)
		cout << "Trung Giai phu dac biet: 50.000.000 d" << endl;
	else if(giaiKhuyenKhich(veSo[17]) == 5) 
		cout << "Trung Giai khuyen khich: 6.000.000 d" << endl;
	else return true;
}

	/*Kiem tra co phai giai khuyen khich khong?*/
int giaiKhuyenKhich(string s) {
	char str[7];		
	int vt = 6, tmp = n;
	itoa(tmp, str, 10);

	int count = 0;
	for(int i=0; i<6; i++)
		if(str[i] == s[i])
			count++;
	return count;
}
