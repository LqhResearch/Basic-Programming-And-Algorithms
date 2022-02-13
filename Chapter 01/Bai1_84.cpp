#include <iostream>
#include <cmath>
using namespace std;
/*
	Nhap vao toa do 2 diem A (xA, yA) va B (xB, yB). Tinh khoang cach AB.
	|AB|= sqrt((xB-xA)^2+(yB-yA)^2)
*/

	/*Main function*/
int main() {
	float xA, yA, xB, yB;
	cout << "Nhap diem A (x, y): ";
	cin >> xA >> yA;
	cout << "Nhap diem B (x, y): ";
	cin >> xB >> yB;
	
	float range = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
	cout << "Khoang cach AB: " << range;
	return 0;
}

