#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
using namespace std;
/*
	Tro choi doan so duoc mo ta nhu sau: Co hai nguoi choi.
	-	Nguoi choi thu nhat nghi ta mot so ngau nhien tu 1...100 va yeu cau nguoi thu hai doan trung so minh da nghi.
	Nguoi thu hai duoc quyen doan nhieu lan nhung khong vuot qua n lan (n xac dinh truoc).
	-	Mot lan nguoi thu nhat doan sai, nguoi thu nhat se thong bao cho nguoi thu hai biet la so x lon hon hay nho hon so cua nguoi thu hai da doan.
	-	Tro choi ket thuc khi nguoi thu hai doan trung so x hoac nguoi thu hai khong doan trung so x sau n lan doan.
	
	a)	Viet chuong trinh the hien tro choi doan so giua nguoi va may. Voi may dong vai tro la nguoi thu hai (nguoi doan).
	b)	Viet chuong trinh the hien tro choi doan so giua nguoi va may. Voi may dong vai tro la nguoi thu nhat (nguoi nghi ra so).
*/
	/*Nguoi choi se doan so*/
void ComputerVsHuman(int times) {
	srand(time(NULL));
	int com = rand()%101;

	while(times != 0) {
		cout << "\tBan con " << times << " lan choi." << endl;
		int human;
		do{
			cout << "- Ban doan: ";
			cin >> human;
			if(human < 1 || human > 100)
				cout << "\tNhap so trong khoang [1, 100]" << endl;
		}while(human < 1 || human > 100);
		
		if(human < com)
			cout << "So ban doan nho hon so may tinh." << endl;
		else if(human > com)
			cout << "So ban doan lon hon so may tinh." << endl;
		else {
			cout << "Ban thang." << endl;
			return;
		}
		times--;
	}
	cout << "Ban thua." << endl;
}

	/*May tinh se doan so*/
void HumanVsComputer(int times) {
	int human;
	do{
		cout << "- Ban hay chon: ";
		cin >> human;
		if(human < 1 || human > 100)
			cout << "\tNhap so trong khoang [1, 100]" << endl;
	}while(human < 1 || human > 100);
	
	while(times != 0) {
		sleep(3);		//Wait 3 second
		cout << "\tMay tinh con " << times << " lan choi." << endl;
		srand(time(NULL));
		int com = rand()%101;
		cout << "May doan la: " << com << endl;
		if(com == human) {
			cout << "Ban thua." << endl;
			return;
		}
		times--;
	}
	cout << "Ban thang." << endl;
}

	/*Thuat toan luon chien thang*/
void HumanVsComputer() {
	int human;
	do{
		cout << "- Ban hay chon: ";
		cin >> human;
		if(human < 1 || human > 100)
			cout << "\tNhap so trong khoang [1, 100]" << endl;
	}while(human < 1 || human > 100);
	
	int times = 8, start = 0, end = 100;
	while(times != 0) {
		sleep(2);		//Wait 2 second
		cout << "\tMay tinh con " << times << " lan choi." << endl;
		int com = (start + end)/2;
		cout << "May doan la: " << com << endl;
		if(com < human)	start = com;
		else if(com > human) end = com;	
		if(com == human) {
			cout << "Ban thua." << endl;
			return;
		}
		times--;
	}
	cout << "Ban thang." << endl;
}

	/*Main function*/
int main() {
	int choice, times = 7;
	do {
		cout << "**********Che do choi**********" << endl;
		cout << "** 1. May tinh doan.         **" << endl;
		cout << "** 2. Nguoi choi doan.       **" << endl;
		cout << "** 0. Thoat.                 **" << endl;
		cout << "*******************************" << endl;
		cout <<  " >> Hay lua chon: ";
		cin >> choice;
		if(choice < 0 || choice > 2)
			cout << "\tChuc nang nay khong ton tai." << endl;
	}while(choice < 0 || choice > 2);
	
	switch(choice) {
		case 1:{
			HumanVsComputer(times);
			break;
		}
		case 2:{
			ComputerVsHuman(times);
			break;
		}
		case 0: exit(0);
	}
	return 0;
}

