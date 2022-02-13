#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141593
/*
	Nhap vao dien tich S cua mat cau. Tinh the tich V cua hinh cau nay.
	S = 4*PI*R^2
	V = 4/3*PI*R^3
	PI = 3.141593
*/

	/*Main function*/
int main() {
	float S, R;
	cout << "Nhap dien tich: ";
	cin >> S;
	
	R = sqrt(S/(4*PI));
	cout << endl << "The tich: " << (4.0/3*PI*R*R*R);
	return 0;
}

