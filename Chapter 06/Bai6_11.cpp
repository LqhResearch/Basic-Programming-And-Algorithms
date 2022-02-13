/*****************************************************
 * Author: QHung
 * Create Date: 14/12/2020
 * Modify Date: 15/12/2020
 *****************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

#define MAX 100
using namespace std;
/*
	Hay khai bao kieu du lieu SINHVIEN de bieu dien thong tin cua mot sinh vien.
	Sinh vien bao gom cac thong tin: ma sinh vien la so nguyen 4 chu so, ho va ten day du, tuoi, gioi tinh, diem.
	Diem bao gom: Diem toan, van, anh va trung binh 3 mon nay.
	Viet ham nhap vao thong tin cho 1 sinh vien va tra ve sinh vien vua nhap. Hay tao mang 100 sinh vien va thuc hien.

	a)	Them moi sinh vien vao danh sach sinh vien.
	b)	Hien thi danh sach sinh vien hien co. Thong tin cua moi sinh vien phai hien tren 1 dong.
	c)	Sap xep danh sach sinh vien theo ten a->z.
	d)	Sap xep danh sach sinh vien theo diem trung binh 3 mon giam dan.
	e)	Tim sinh vien co ma so duoc nhap tu ban phim.
	f)	Ghi thong tin sinh vien trong danh sach hien co vao file.
*/
typedef struct Point {	//Diem toan, van, anh va trung binh 3 mon nay.
	float toan;
	float van;
	float anh;
	float dtb;
} Point;

typedef struct SinhVien { // Cau truc sinh vien
	int code;
	char fullName[40];
	int age;
	char gender[6];
	Point diem;
} SinhVien;

SinhVien list[100];		int end = -1;

	/*Kiem tra ma so sinh vien ton tai chua*/
bool TestCode(int code) {
	for(int i=0; i<=end; i++)
		if(list[i].code == code)
			return true;
	return false;
}

	/*Nhap thong tin sinh vien*/
SinhVien InputSV() {
	SinhVien sv;
	cout << "\n**********Nhap thong tin sinh vien**********" << endl;
	do {
		cout << "- Ma so: ";
		cin >> sv.code;
		if(TestCode(sv.code) == true)
			cout << "Vui long nhap ma so khac" << endl;
		if(sv.code < 1000 || sv.code > 9999)
			cout << "Vui long nhap ma so co 4 chu so" << endl;
	}while(sv.code < 1000 || sv.code > 9999 || TestCode(sv.code) == true);
	cout << "- Ho va ten: ";
	fflush(stdin);	gets(sv.fullName);
	do {
		cout << "- Tuoi: ";
		cin >> sv.age;
		if(sv.age <= 17)
			cout << "Vui long tuoi >= 18" << endl;
	}while(sv.age <= 17);
	cout << "- Gioi tinh: ";
	fflush(stdin);	gets(sv.gender);
	do {
		cout << "- Diem toan: ";
		cin >> sv.diem.toan;
		if(sv.diem.toan < 0 || sv.diem.toan > 10)
			cout << "Vui long diem toan 0 <= x <= 10" << endl;
	}while(sv.diem.toan < 0 || sv.diem.toan > 10);
	do {
		cout << "- Diem van: ";
		cin >> sv.diem.van;
		if(sv.diem.van < 0 || sv.diem.van > 10)
			cout << "Vui long diem van 0 <= x <= 10" << endl;
	}while(sv.diem.van < 0 || sv.diem.van > 10);
	do {
		cout << "- Diem anh van: ";
		cin >> sv.diem.anh;
		if(sv.diem.anh < 0 || sv.diem.anh > 10)
			cout << "Vui long diem anh van 0 <= x <= 10" << endl;
	}while(sv.diem.anh < 0 || sv.diem.anh > 10);
	sv.diem.dtb = (sv.diem.toan + sv.diem.van + sv.diem.anh) / 3;
	return sv;
}

	/*Xuat thong tin sinh vien*/
void OutputSV(SinhVien sv) {
	cout << sv.code << "\t" << sv.fullName << "\t" << sv.age << "\t" << sv.gender << "\t"
		 << sv.diem.toan << "\t" << sv.diem.van << "\t" << sv.diem.anh << "\t" << sv.diem.dtb << endl;
}

	/*Xuat danh sach thong tin sinh vien*/
void OutputDSSV() {
	cout << "Ma so\tHo ten\t\tTuoi\tG_tinh\tToan\tVan\tAnh van\tDiem TB" << endl;
	if(end == -1)
		cout << "Danh sach sinh vien trong." << endl;
	for(int i=0; i<=end; i++)
		OutputSV(list[i]);
}

	/*Doc file SinhVien.dat*/
void ReadToFile() {
	ifstream ifs("SinhVien.dat", ios::binary);
	while(!ifs.eof()) {
		SinhVien sv;
		ifs.read((char*) &sv, sizeof(SinhVien));
		if(ifs.good())
			list[++end] = sv;
	}
	ifs.close();
}

	/*Ghi file SinhVien.dat*/
void WriteToFile() {
	remove("SinhVien.dat");
	ofstream ofs("SinhVien.dat", ios::binary);
	for(int i=0; i<=end; i++)
		ofs.write((char*) &list[i], sizeof(SinhVien));
	ofs.close();
}

	/*Hoan vi hai sinh vien*/
void Swap(SinhVien &sv1, SinhVien &sv2) {
	SinhVien tmp = sv1;
	sv1 = sv2;
	sv2 = tmp;
}

	/*Sap xep danh sach sinh vien theo ten a->z*/
void SortName() {
	for(int i=0; i<end; i++)
		for(int j=i+1; j<=end; j++)
			if(strcmp(list[i].fullName, list[j].fullName) > 0)
				Swap(list[i], list[j]);
	OutputDSSV();
}

	/*Sap xep danh sach sinh vien theo diem trung binh*/
void SortDTB() {
	for(int i=0; i<end; i++)
		for(int j=i+1; j<=end; j++)
			if(list[i].diem.dtb < list[j].diem.dtb)
				Swap(list[i], list[j]);
	OutputDSSV();
}

	/*Tim sinh vien co ma so*/
void SearchSVCode() {
	int code;
	do {
		cout << "- Ma so can tim: ";
		cin >> code;
		if(code < 1000 || code > 9999)
			cout << "Vui long nhap ma so co 4 chu so" << endl;
	}while(code < 1000 || code > 9999);
	
	for(int i=0; i<=end; i++)
		if(list[i].code == code) {
			OutputSV(list[i]);
			return;
		}
	cout << "Khong tim thay sinh vien co ma so " << code << endl;
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
		cout << "*************************Quan li Sinh vien*************************" << endl;
		cout << "**  1. Them sinh vien.                                           **" << endl;
		cout << "**  2. Hien thi danh sach sinh vien.                             **" << endl;
		cout << "**  3. Sap xep danh sach sinh vien theo ten a->z.                **" << endl;
		cout << "**  4. Sap xep danh sach sinh vien theo diem trung binh.         **" << endl;
		cout << "**  5. Tim sinh vien co ma so.                                   **" << endl;
		cout << "**  0. Thoat.                                                    **" << endl;
		cout << "*******************************************************************" << endl;
		cout << "** Hay lua chon: ";
		cin >> choice;
		if(choice < 0 || choice > 5)
			cout << "Chuc nang nay khong ton tai." << endl;
	}while(choice < 0 || choice > 5);
	
	switch(choice) {
		case 1:
			list[++end] = InputSV();
			break;
		case 2:
			OutputDSSV();
			break;
		case 3:
			SortName();
			break;
		case 4:
			SortDTB();
			break;
		case 5:
			SearchSVCode();
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
