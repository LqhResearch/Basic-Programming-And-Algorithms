/**************************************************************
 * Author: QHung
 * Create Date: 15/12/2020
 * Modify Date: 15/12/2020
 **************************************************************/

/**************************************************************
 * Ve tam giac Pascal
 **************************************************************/
#include <iostream>
using namespace std;

	/*So fibonacci*/
int factorial(int n) {
	int f = 1;
	while(n > 1) {
		f *= n;
		n--;
	}
	return f;
}

	/*Vi tri trong tam giac Pascal*/
int ncr(int n, int r) {
	return factorial(n) / (factorial(n-r) * factorial(r));
}

	/*Main function*/
int main() {
	int n;
	do {
		cout << "- Nhap so: ";
		cin >> n;
		if(n <= 0)
			cout << "Vui long nhap so nguyen duong." << endl;
	}while(n <= 0);
	cout << "Ve tam giac Pascal: " << endl;
	for(int i=0; i<=n; i++) {
		for(int j = 0; j <= n-i; j++)
			cout << "  ";
		for(int j = 0; j <= i; j++)
			printf(" %3d", ncr(i, j));
		cout << endl;
	}
	return 0;
}
