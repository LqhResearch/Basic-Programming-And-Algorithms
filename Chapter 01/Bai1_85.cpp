#include <iostream>
#include <cmath>
using namespace std;
/*
	Viet chuong trinh nhap vao toa do cac dinh cua tam giac ABC va cua diem M.
	Xac dinh diem M nam trong, nam tren canh hay nam ngoai tam giac ABC.
	Biet luan bang cach so sanh tong dien tich: MAB + MBC + MCA voi dien tich ABC.
*/
float Area(float xA, float yA, float xB, float yB, float xC, float yC) {
	return 0.5 * fabs(xA * yB - xB * yA + xB * yC - xC * yB + xC * yA - xA * yC);
}

	/*Main function*/
int main() {
	float xA, yA, xB, yB, xC, yC, xM, yM;
	cout << "A (x, y) = ";
	cin >> xA >> yA;
	cout << "B (x, y) = ";
	cin >> xB >> yB;
	cout << "C (x, y) = ";
	cin >> xC >> yC;
	cout << "M (x, y) = ";
	cin >> xM >> yM;
	
	float S = Area(xM, yM, xA, yA, xB, yB) + Area(xM, yM, xA, yA, xC, yC) 
			+ Area(xM, yM, xB, yB, xC, yC) - Area(xA, yA, xB, yB, xC, yC);
	
	if(S > 0)
		cout << "M nam ngoai tam giac ABC\n";
	else if(Area(xM, yM, xA, yA, xB, yB) == 0 || Area(xM, yM, xA, yA, xC, yC) == 0 || Area(xM, yM, xB, yB, xC, yC) == 0)
		cout << "M nam tren tam giac ABC\n";
	else cout << "M nam trong tam giac ABC\n";
	return 0;
}

