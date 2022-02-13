/**************************************************************
 * Author: QHung
 * Create Date: 01/02/2022
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * Tim chu so khac 0 cuoi cung cua n! (giai thua)
 **************************************************************/
#include <iostream>

using namespace std;

int LastDigitDiffZero(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
        while (res % 10 == 0) res /= 10;
        res = res % 100;
    }
    while (res % 10 == 0) res /= 10;
    return res % 10;
}

int main() {
    int n;
    cout << "Nhap so can kiem tra: ";
    cin >> n;

    cout << "Ket qua la " << LastDigitDiffZero(n);
    return 0;
}