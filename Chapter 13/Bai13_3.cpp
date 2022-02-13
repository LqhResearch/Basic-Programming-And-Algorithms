/**************************************************************
 * Author: QHung
 * Create Date: 01/02/2022
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * GCPD
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

int GreatestCommonPrimeDivisor(int a, int b) {
    int min = a < b ? a : b;
    int maxPrime = -1;
    for (int i = 2; i <= min; i++) {
        if (a % i == 0 && b % i == 0 && isPrime(i)) {
            maxPrime = i;
        }
    }
    return maxPrime;
}

int main() {
    int a, b;
    cout << "Nhap 2 so nguyen: ";
    cin >> a >> b;

    cout << "GCPD cua " << a << " va " << b << " la " << GreatestCommonPrimeDivisor(a, b);
    return 0;
}