/**************************************************************
 * Author: QHung
 * Create Date: 01/02/2022
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * 
 **************************************************************/
#include <iostream>

using namespace std;

int FactorSum(int n) {
    int sum = 0;
    int m = n;
    for (int i = 2; i <= m; i++) {
        while (m % i == 0) {
            sum += i;
            m /= i;
        }
    }
    if (sum == n) return n;
    return FactorSum(sum);
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    cout << "n = " << n << " la " << FactorSum(n);
    return 0;
}