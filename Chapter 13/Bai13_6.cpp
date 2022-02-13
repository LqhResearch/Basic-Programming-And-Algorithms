/**************************************************************
 * Author: QHung
 * Create Date: 01/02/2022
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * Tinh tong cac so nguyen to nho hon hoac bang n
 **************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

bool a[10000001];

void snt(int n) {
    for (int i = 2; i <= n; i++)
        a[i] = 1;
    a[0] = a[1] = 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (a[i])
            for (int j = 2 * i; j <= n; j += i)
                a[j] = 0;
}

int PrimeSum(int n) {
    int mod = 22082018;
    snt(n);
    int d = 0;
    for (int i = 2; i <= n; i++)
        if (a[i]) d = (d + i % mod) % mod;
    return d;
}

int main() {
	int n;
    cout << "Nhap so: ";
    cin >> n;

    cout << "Ket qua la " << PrimeSum(n);
    return 0;
}

