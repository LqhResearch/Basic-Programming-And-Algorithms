#include <iostream>
#include <cmath>

using namespace std;
/*
	Author: LQH
	Date: 22/11/20 16:40
	Description: Viet cac ham sau:
	-	Ham kiem tra 3 so thuc co phai la 3 canh cua tam giac hay khong? bool isTriangle(double a, double b, double c)
	-	Ham tinh dien tich tam giac khi biet do dai 3 canh: double area(double a, double b, double c)
	Sau do su dung 3 ham nay vao cac cong viec sau:
	-	Nhap tu ban phim 3 so thuc.
	-	Kiem tra 3 so thuc do co phai la do dai cua 3 canh tam giac hay khong?
	Neu co thi in ra dien tich, chu vi cua tam giac ra man hinh, neu khong xuat thong bao 
	"Day khong phai la 3 canh cua tam giac"
*/
	/*Nhap 3 canh cua tam giac*/
void input(double &a, double &b, double &c) {
	do{
		cout << "Nhap a = ";
		cin >> a;
		if(a <= 0)
			cout << "Vui long nhap so lon hon 0" << endl;
	}while(a <= 0);
	do{
		cout << "Nhap b = ";
		cin >> b;
		if(b <= 0)
			cout << "Vui long nhap so lon hon 0" << endl;
	}while(b <= 0);
	do{
		cout << "Nhap c = ";
		cin >> c;
		if(c <= 0)
			cout << "Vui long nhap so lon hon 0" << endl;
	}while(c <= 0);
}

	/*Kiem tra 3 canh co lap thanh tam giac hay khong?*/
bool isTriangle(double a, double b, double c) {
	if(a+b>c && b+c>a && a+c>b) {
		cout << "\nBa canh lap thanh tam giac ";
		if(a==b && b==c)
			cout << "deu." << endl;
		else if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
				cout << "vuong." << endl;
		else if(a==b || a==c)
				cout << "can." << endl;
		else cout << "thuong." << endl;
		return true;
	}
	else {
		cout << "Ba canh khong lap thanh tam giac";
		return false;
	}
}

	/*Chu vi tam giac*/
double perimeter(double a, double b, double c) {
	return a + b + c;
}

	/*Dien tich tam giac*/
double area(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p-a) * (p-b) * (p-c));
}

	/*Main function*/
int main() {
	double a, b, c;
	input(a, b, c);
	if(isTriangle(a, b, c) == true) {
		cout << "Chu vi = " << perimeter(a, b, c) << endl;
		cout << "Dien tich = " << area(a, b, c) << endl;
	}
	return 0;
}

