#include <iostream>
#include <cmath>
using namespace std;
/*
	Viet chuong trinh nhap lai xuat nam r (%), tien von p va thoi han goi tien n (nam).
	In ra von tich luy a cua tung nam. Chuong trinh co kiem tra nhap thieu hoac nhap loi.
				a=p(1+r)^n
	Trong do, a (mount) la von tich luy duoc, p (principal) la von goc, r(rate) lai suat va n la so nam dau tu.
*/

	/*Main function*/
int main() {
	float a, p, r, n;
	do{
		cout << "So von ban dau (dong): ";
		cin >> p;
		if(p <= 0)
			cout << "So von ban dau > 0" << endl;
	}while(p <= 0);
	do{
		cout << "Lai suat (%): ";
		cin >> r;
		if(r <= 0 || r > 100)
			cout << "Lai suat 0 < x <= 100" << endl;
	}while(r <= 0 || r > 100);
	do{
		cout << "So nam dau tu: ";
		cin >> n;
		if(n <= 0)
			cout << "So nam dau tu > 0" << endl;
	}while(n <= 0);
	
	
	cout << "Nam   Von" << endl;
	for(int i=0; i<=n; i++)
		cout << i << "  =  " << (p*pow(1+r/100, i)) << endl;
	return 0;
}

