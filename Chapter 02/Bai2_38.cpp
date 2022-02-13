/**************************************************************
 * Author: QHung
 * Create Date: 15/12/2020
 * Modify Date: 15/12/2020
 **************************************************************/

/**************************************************************
 * Ve tam giac Floyd
 **************************************************************/
#include <iostream>
using namespace std;

	/*Main function*/
int main() {
	int n;
	do {
		cout << "- Nhap so: ";
		cin >> n;
		if(n <= 0)
			cout << "Vui long nhap so nguyen duong." << endl;
	}while(n <= 0);
	cout << "Ve tam giac Floyd: " << endl;
	
	int count = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++)
			cout << ++count << "  ";
		cout << endl;
	}
	return 0;
}

