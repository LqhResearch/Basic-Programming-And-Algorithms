#include <iostream>
#include <string.h>
using namespace std;
/*
		Ung dung May ATM.
	Tao ung dung cho phep nguoi nhap thuc hien rut tien, kiem tra tai khoan va nap tien vao tai khoan (gia lap). 
	SO tien cho phep rut ban duoc tuy y lua chon hoac co cac muc tuy chon san nhu 200k, 500k.
	May chu cho rut khi ban da dang nhap vao tai khoan ngan hang cua ban.
	So tien rut la boi so cua 10k va nho hon tien trong tai khoan hien co.
*/
char user[] = "admin", pass[] = "12345678";
int money = 1200;

void LogIn() {
	char user1[10], pass1[10];
	bool test;
	do {
		cout << "- Ten tai khoan: ";
		fflush(stdin);	gets(user1);
		cout << "- Mat khau: ";
		fflush(stdin);	gets(pass1);
		
		test = (strcmp(user, user1) == 0 && strcmp(pass, pass1) == 0);
		if(test == false)
			cout << "Tai khoan hoac mat khau khong hop le." << endl;
	}while(test == false);
}

void ATMMachine() {
	int money1;
	do {
		cout << "- So tien muon rut: ";
		cin >> money1;
		if(money1 % 10 != 0)
			cout << "Tien la boi so cua 10" << endl;
	}while(money1 % 10 != 0);
	
	if(money1 > money)
		cout << "Tien tai khoan ban it hon tien muon rut" << endl;
	else {
		cout << "Ban rut thanh cong: " << money1 << " dong" << endl;
		money-=money1;
		cout << "So du con lai la " << money << " dong" << endl;
	}
}

	/*Main function*/
int main() {
	LogIn();
	while(true)
	ATMMachine();
	return 0;
}

