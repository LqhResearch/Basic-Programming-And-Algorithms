#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
/*
	Tap tin van ban Bai02_Person.dat luu thong tin ca nhan thanh cac dong co dinh dang nhu sau:
		-	code(int)
		-	firstname lastname(char[32])
		-	address(char[32])
		-	birthday(mm/dd/yy)
	Viet chuong trinh doc tap tin Bai02_Person.dat, lay va hien thong tin luu tru ung voi tung ca nhan.
*/
typedef struct{
	int day;
	int month;
	int year;
} Date;

typedef struct{
	int code;
	char fullname[32];
	char address[32];
	Date birth;
} Person;

	/*Nhap thong tin cua person*/
Person Input() {
	Person p;
	cout << "\n\t==========Nhap thong tin==========" << endl;
	cout << "- Ma so: ";
	cin >> p.code;
	cout << "- Ho ten: ";
	fflush(stdin);	gets(p.fullname);
	cout << "- Dia chi: ";
	fflush(stdin);	gets(p.address);
	cout << "- Ngay / thang / nam: ";
	cin >> p.birth.day >> p.birth.month >> p.birth.year;
	return p;
}

	/*Xuat thong tin cua person*/
void Output(Person p) {
	cout << "\n Ma so: " << p.code;
	cout << "\n Ho ten: " << p.fullname;
	cout << "\n Dia chi: " << p.address;
	cout << "\n Ngay / thang / nam: " << p.birth.day << " / " << p.birth.month << " / " << p.birth.year;
}

	/*Ghi vao tap tin*/
void writeToFile(Person p, char path[]) {
	ofstream ofs(path, ios::app);
	if(ofs.good()) {
		ofs.write((char*) &p, sizeof(Person));
		cout << "\nGhi file thanh cong";
	}
	ofs.close();
}

	/*Doc tap tin*/
void readToFile(char path[]) {
	ifstream ifs(path, ios::binary);
	cout << "\nDoc file: ";
	Person p;
	while(true) {
		ifs.read((char*) &p, sizeof(Person));
		if(ifs.eof()) break; // Neu doc den cuoi tap tin thi dung lai
		Output(p);
	}
	ifs.close();
}

	/*Main function*/
int main() {
	char path[50] = "Bai02_Person.dat";
	Person p = Input();
	Output(p);
	
	writeToFile(p, path);
	readToFile(path);
	return 0;
}

