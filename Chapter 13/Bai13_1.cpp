/**************************************************************
 * Author: QHung
 * Create Date: 01/02/2022
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * Kiem tra so nguyen to
 **************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cout << "Nhap so can kiem tra: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " la so nguyen to";
    } else {
        cout << n << " khong phai la so nguyen to";
    }
    return 0;
}
