#include <iostream>
using namespace std;
/*
	So bao hiem xa hoi cua Canada (SIN - Canadian Social Insurance Number) la mot so co 9 chu so, duoc kiem tra tinh hop le nhu sau:
	-	So phai nhat (bi tri 1, tinh tu phai sang), la so kiem tra (check digit).
	-	Trong so duoc tinh tu phai qua trai (khong tinh check digit), bang s1 + s2:
		+	s1 la tong cac so co vi tri le.
		+	Cac so vi tri chan nhan doi. Neu ket qua nhan doi co hai chu so thi ket qua la tong cua hai chu so nay. s2 la tong cac ket qua.
		SIN hop le co tong trong so voi so kiem tra chia het cho 10.
*/
	/*Lay gia tri cuoi cung*/
int CheckDigit(string sin) {
	return sin[8] - '0';
}

	/*Tong cac so co vi tri le*/
int SumNumLe(string sin) {
	return (sin[0] - '0') + (sin[2] - '0') + (sin[4] - '0') + (sin[6] - '0');
}

	/*Tong cac chu so*/
int SumChuSo(int n) {
	int sum = 0;
	while(n != 0) {
		sum+=n%10;
		n/=10;
	}
	return sum;
}

	/*Tong cac so vi tri chan nhan doi*/
int SumNumChan(string sin) {
	int sum = 0;
	for(int i=0; i<8; i++)
		if(i%2!=0) {	//So le
			if(sin[i] - '0' >= 10)
				sum += SumChuSo(sin[i] - '0');
			else
				sum += sin[i] - '0';
		}
	return sum;
}

	/*Main function*/
int main() {
	string sin;
	do{
		cout << "\nNhap so bao hiem xa hoi (nhap 0 de thoat): ";
		fflush(stdin);	getline(cin, sin);
		if(sin[0] - '0' == 0) return 0;		//Neu nhap 0 thi dung chuong trinh
		if(sin.length() != 9) {		//Xuat thong bao khi nhap thieu hoac thua ky tu
			cout << "SIN khong hop le! vi SIN cua ban nhap " << sin.length() << " ky tu" << endl;
			cout << "Hay nhap SIN co 9 ky tu";
			continue;
		}
		cout << "So bao hiem xa hoi: " << sin << endl;
		
		int lastNum = CheckDigit(sin);
		int sum1 = SumNumLe(sin);
		int sum2 = SumNumChan(sin);
		
		if((lastNum + sum1 + sum2)%10 == 0)
			cout << "SIN hop le!";
		else cout << "SIN khong hop le!";
	}while(true);
	return 0;
}

