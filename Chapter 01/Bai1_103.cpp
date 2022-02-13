/**************************************************************
 * Author: QHung
 * Create Date: 
 * Modify Date: 
 **************************************************************/

/**************************************************************
 * Viet chuong trinh nhap vao so thuc va tra ve phan tram cua no.
 **************************************************************/
#include <iostream>
using namespace std;

	/*Main function*/
int main() {
	float num;
	do{
		cout << "- Nhap so: ";
		cin >> num;
		if(num < 0)
			cout << "Vui long nhap so lon hon hoac bang 0" << endl;
	}while(num < 0);
	
	cout << num << " = " << (num*100) << "%";
	return 0;
}

