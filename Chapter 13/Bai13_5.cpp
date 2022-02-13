/**************************************************************
 * Author: QHung
 * Create Date: 06/02/2022
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * Tim so luong cac chu so dung de danh so trang quyen sach
 **************************************************************/
#include <iostream>
#include <sstream> // ostringstream
#include <string>
#include <cmath>
using namespace std;

int PagesNumbering(int n) {
	ostringstream ost;
	ost << n;
	int m = ost.str().length();
    int k = 1;
    int v1 = 0;
    int v2 = 0;

    if (n < 10 && n > 0) {
        v1 = n;
        v2 = 0;
    } else {
        for (int i = 1; i <= m - 1; i++) {
            v1 = (n - (int) pow(10, i) + 1) * m;
            v2 = v2 + (9 * i) * k;
            k = k * 10;
        }
    }
    return (v1 + v2);
}

int main() {
	int n;
    cout << "Nhap so trang: ";
    cin >> n;

    cout << "Ket qua la " << PagesNumbering(n);
    return 0;
}

