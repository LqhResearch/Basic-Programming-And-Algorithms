/*****************************************************
 * Author: QHung
 * Create Date: 15/12/2020
 * Modify Date: 15/12/2020
 *****************************************************/
 
/**************************************************************************************************************************
 *	Hay khai bao kieu du lieu HOCSINH de bieu dien thong tin cua mot hoc sinh.
 *	Moi hoc sinh co ma (day 5 ki tu chu va so, VD: 10A11, 12A30), ho ten day du, ngay sinh, diem trung binh, lop, xep loai.
 *
 *	a)	Nhap mot hoc sinh vao danh sach.
 *	b)	Hien thi danh sach hoc sinh hien co, moi hoc sinh hien thong tin tren 1 dong.
 *	c)	Tim hoc sinh theo ma.
 *	d)	Tim hoc sinh theo ten.
 *	e)	Tim hoc sinh theo diem trung binh.
 *	f)	Xoa hoc sinh theo ma cho truoc.
 *	g)	Sap xep danh sach hoc sinh theo diem trung binh mon giam dan.
 *	h)	Sap xep hoc sinh theo ten tang dan a->z.
 *	i)	Xep loai hoc luc cho hoc sinh va hien thi ra man hinh theo tieu chi:
 *		Xuat sac: diem tb tu 9.0 tro lên.
 *		Gioi: diem tb tu 8.0 den duoi 9.0.
 *		Kha: diem tb tu 6.5 den duoi 8.0.
 *		Trung binh: diem tb tu 4.0 den duoi 6.5.
 *		Yeu: diem tb duoi 4.0.
 *	j)	Ghi thong tin danh sach hoc sinh vao file.
 *************************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

#define MAX 100
using namespace std;

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

typedef struct HocSinh {
	char code[6];
	char fullname[40];
	Date birthday;
	float dtb;
	char lop[6];
	char xepLoai[12];
} HocSinh;

HocSinh list[100];		int end = -1;

	/*Kiem tra ma so sinh vien ton tai chua*/
bool TestCode(char code[]) {
	for(int i=0; i<=end; i++)
		if(strcmp(list[i].code, code) == 0)
			return true;
	return false;
}

	/*Kiem tra ngay thang nam co hop le hay khong?*/
int TestDMY(Date d) {
	if(d.month == 2) {
		if(d.year%400==0 || (d.year%4==0 && d.year%100!=0))
			return 29;
		else return 28;
	}
	else if(d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
		return 30;
	else return 31;
}

	/*Nhap thong tin ngay thang nam*/
Date InputDMY() {
	Date d;
	bool test;
	do {
		cout << "\t- Ngay: ";
		cin >> d.day;
		do {
			cout << "\t- Thang: ";
			cin >> d.month;
			if(d.month < 1 || d.month > 12)
				cout << "Vui long nhap thang 1 - 12" << endl;
		}while(d.month < 1 || d.month > 12);
		do {
			cout << "\t- Nam: ";
			cin >> d.year;
			if(d.year < 1)
				cout << "Vui long nhap nam tu 1 den nay" << endl;
		}while(d.year < 1);
		
		test = (d.day <= TestDMY(d));
		if(test == false)
			cout << "Ngay/thang/nam nay khong hop le." << endl;
	}while(test == false);
	return d;
}

	/*Kiem tra hoc sinh xep loai gi?*/
char* TestXepLoai(float dtb) {
	if(dtb >= 9)
		return (char*)"Xuat sac";
	else if(dtb >= 8)
		return (char*)"Gioi";
	else if(dtb >= 6.5)
		return (char*)"Kha";
	else if(dtb >= 4.0)
		return (char*)"Trung binh";
	else return (char*)"Yeu";
}

	/*Nhap thong tin cua hoc sinh*/
HocSinh InputHS() {
	HocSinh hs;
	cout << "\n**********Nhap thong tin hoc sinh**********" << endl;
	do {
		cout << "- Ma so: ";
		cin >> hs.code;
		if(TestCode(hs.code) == true)
			cout << "Vui long nhap ma so khac" << endl;
		if(strlen(hs.code) !=  5)
			cout << "Vui long nhap ma so co 5 ki tu" << endl;
	}while(TestCode(hs.code) == true || strlen(hs.code) !=  5);
	cout << "- Ho va ten: ";
	fflush(stdin);	gets(hs.fullname);
	cout << "- Ngay sinh: " << endl;
	hs.birthday = InputDMY();
	do {
		cout << "- Diem trung binh: ";
		cin >> hs.dtb;
		if(hs.dtb < 0 || hs.dtb > 10)
			cout << "Vui long diem trung binh 0 <= x <= 10" << endl;
	}while(hs.dtb < 0 || hs.dtb > 10);
	cout << "- Lop: ";
	fflush(stdin);	gets(hs.lop);
	strcpy(hs.xepLoai, TestXepLoai(hs.dtb));
	return hs;
}

	/*Xuat thong tin cua hoc sinh*/
void OutputHS(HocSinh hs) {
	cout << hs.code << "\t" << hs.fullname << "\t" << hs.birthday.day << "/" << hs.birthday.month << "/"
		 << hs.birthday.year << "\t" << hs.dtb << "\t" << hs.lop << "\t" << hs.xepLoai << endl;
}

	/*Xuat danh sach thong tin sinh vien*/
void OutputDSHS() {
	cout << "Ma so\tHo ten\t\tNgay sinh\tDiem TB\tLop\tXep loai" << endl;
	if(end == -1)
		cout << "Danh sach hoc sinh trong." << endl;
	for(int i=0; i<=end; i++)
		OutputHS(list[i]);
}

	/*Doc file HocSinh.dat*/
void ReadToFile() {
	ifstream ifs("HocSinh.dat", ios::binary);
	while(!ifs.eof()) {
		HocSinh hs;
		ifs.read((char*) &hs, sizeof(HocSinh));
		if(ifs.good())
			list[++end] = hs;
	}
	ifs.close();
}

	/*Ghi file SinhVien.dat*/
void WriteToFile() {
	remove("HocSinh.dat");
	ofstream ofs("HocSinh.dat", ios::binary);
	for(int i=0; i<=end; i++)
		ofs.write((char*) &list[i], sizeof(HocSinh));
	ofs.close();
}

	/*Tim hoc sinh theo ma so*/
void SearchCode() {
	char code[6];
	bool check = false;
	cout << "- Nhap ma so can tim: ";
	fflush(stdin);	gets(code);
	
	if(strlen(code) != 5) {
		cout << "Ma " << code << " nay khong ton tai vi khac 5 ki tu." << endl;
		return;
	}
	
	cout << "Ma so\tHo ten\t\tNgay sinh\tDiem TB\tLop\tXep loai" << endl;
	for(int i=0; i<=end; i++)
		if(strcmp(list[i].code, code) == 0) {
			OutputHS(list[i]);
			check = true;
		}
	if(check == false)
		cout << "Ma " << code << " nay khong ton tai." << endl;
}

	/*Tim hoc sinh theo ten*/
void SearchFullName() {
	char fullname[40];
	bool check = false;
	cout << "- Nhap ten can tim: ";
	fflush(stdin);	gets(fullname);
	
	cout << "Ma so\tHo ten\t\tNgay sinh\tDiem TB\tLop\tXep loai" << endl;
	for(int i=0; i<=end; i++)
		if(strcmp(list[i].fullname, fullname) == 0) {
			OutputHS(list[i]);
			check = true;
		}
	if(check == false)
		cout << "Ten " << fullname << " nay khong ton tai." << endl;
}

	/*Tim hoc sinh theo diem trung binh*/
void SearchDTB() {
	float dtb;
	bool check = false;
	do {
		cout << "- Nhap diem trung binh can tim: ";
		cin >> dtb;
		if(dtb < 0 || dtb > 10)
			cout << "Vui long nhap diem trung binh 0 <= x <= 10." << endl;
	}while(dtb < 0 || dtb > 10);
	
	cout << "Ma so\tHo ten\t\tNgay sinh\tDiem TB\tLop\tXep loai" << endl;
	for(int i=0; i<=end; i++)
		if(list[i].dtb == dtb) {
			OutputHS(list[i]);
			check = true;
		}
	if(check == false)
		cout << "Diem trung binh " << dtb << " nay khong hoc sinh nao." << endl;
}

	/*Xoa hoc sinh theo ma cho truoc*/
void DeleteByCode() {
	char code[6];
	bool check = false;
	cout << "- Nhap ma so can xoa: ";
	fflush(stdin);	gets(code);
	if(strlen(code) != 5) {
		cout << "Ma " << code << " nay khong ton tai vi khac 5 ki tu." << endl;
		return;
	}
	
	int local = -1;
	for(int i=0; i<=end; i++)
		if(strcmp(list[i].code, code) == 0) {
			check = true;
			local = i;
			break;
		}
		
	if(check == false)
		cout << "Ma " << code << " nay khong ton tai." << endl;
	else {
		for(int i=local; i<end; i++)
			list[i] = list[i+1];
		end--;
		cout << "Xoa ma so " << code << " thanh cong." << endl;
	}
}

	/*Hoan vi hai sinh vien*/
void Swap(HocSinh &sv1, HocSinh &sv2) {
	HocSinh tmp = sv1;
	sv1 = sv2;
	sv2 = tmp;
}

	/*Sap xep danh sach hoc sinh theo ten a->z*/
void SortName() {
	for(int i=0; i<end; i++)
		for(int j=i+1; j<=end; j++)
			if(strcmp(list[i].fullname, list[j].fullname) > 0)
				Swap(list[i], list[j]);
	OutputDSHS();
}

	/*Sap xep danh sach hoc sinh theo diem trung binh*/
void SortDTB() {
	for(int i=0; i<end; i++)
		for(int j=i+1; j<=end; j++)
			if(list[i].dtb < list[j].dtb)
				Swap(list[i], list[j]);
	OutputDSHS();
}


	/*Nhap mot phim bat ki*/
void PressAnyKey() {
	cout << "\nNhan mot phim bat ki de tiep tuc ... ";
	getch();
	system("cls");
}

	/*Danh sach chuc nang quan li sinh vien*/
void menu() {
	int choice;
	do {
		cout << "**********************Quan li Hoc sinh**********************" << endl;
		cout << "**  1. Them hoc sinh.                                     **" << endl;
		cout << "**  2. Hien thi danh sach hoc sinh.                       **" << endl;
		cout << "**  3. Tim hoc sinh theo ma so.                           **" << endl;
		cout << "**  4. Tim hoc sinh theo ten.                             **" << endl;
		cout << "**  5. Tim hoc sinh theo diem trung binh.                 **" << endl;
		cout << "**  6. Xoa hoc sinh theo ma cho truoc.                    **" << endl;
		cout << "**  7. Sap xep danh sach hoc sinh theo diem trung binh.   **" << endl;
		cout << "**  8. Sap xep hoc sinh theo ten tang dan a->z.           **" << endl;
		cout << "**  0. Thoat.                                             **" << endl;
		cout << "************************************************************" << endl;
		cout << "** Hay lua chon: ";
		cin >> choice;
		if(choice < 0 || choice > 8)
			cout << "Chuc nang nay khong ton tai." << endl;
	}while(choice < 0 || choice > 8);
	
	switch(choice) {
		case 1:
			list[++end] = InputHS();
			break;
		case 2:
			OutputDSHS();
			break;
		case 3:
			SearchCode();
			break;
		case 4:
			SearchFullName();
			break;
		case 5:
			SearchDTB();
			break;
		case 6:
			DeleteByCode();
			break;
		case 7:
			SortDTB();
			break;
		case 8:
			SortName();
			break;
		case 0:
			WriteToFile();
			exit(0);
	}
	PressAnyKey();
}

	/*Main function*/
int main() {
	ReadToFile();
	while(true)
		menu();
	return 0;
}

