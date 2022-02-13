/*****************************************************
 * Author: QHung
 * Create Date: 15/12/2020
 * Modify Date: 15/12/2020
 *****************************************************/

/*****************************************************
 * Viet chuong trinh tinh tien cuoc TAXI.
 * Biet rang:
 * 		- Km dau tien la 5000d
 *		- Den 30 km la 4000d
 *		- Neu lon hon 30 km thi moi km them 3000d
 * Hay nhap so km sau do in ra so tien phai tra.
 *****************************************************/
#include <iostream>
using namespace std;

	/*Main function*/
int main() {
	int km, money = 0;
	do {
		cout << "- So km: ";
		cin >> km;
		if(km <= 0)
			cout << "So km phai lon hon 0" << endl;
	}while(km <= 0);
	if(km > 30) {
		money+=(km-30)*3000;
		km=30;
	}
	if(km > 1) {
		money+=(km-1)*4000;
		km=1;
	}
	money+=km*5000;
	cout << km << " km la " << money << " dong";
	return 0;
}

