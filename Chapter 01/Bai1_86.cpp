#include <iostream>
#include <cmath>
using namespace std;
/*
	Viet chuong trinh nhap vao so x xho so do cua mot goc, tinh bang phut. 
	Cho biet no thuoc goc vuong thu bao nhieu cua vong tron luong giac.
	Tinh cos(x), dung ham cmath cung cap.
*/

	/*Main function*/
int main() {
	float angle;
	cout << "Nhap vao so do x cua goc (tinh bang phut) = ";
	cin >> angle;
	
	angle /= 60;	//doi phut thanh do
	cout << "x thuoc goc vuong thu " << (int)ceil(angle/90)%4 << endl;
	cout << "cos (x) = " << cos(angle * M_PI / 180);
	return 0;
}

