#include <iostream>
using namespace std;
/*
	Viet chuong trinh tinh luong cua nhan vien dua theo tham nien cong tac (TNCT) nhu sau:
	Luong = he so * luong can ban, trong do luong can ban la 1,6 trieu dong.
	-	Neu TNCT < 12 thang: he so = 1.92
	-	Neu 12 <= TNCT < 36 thang: he so = 2.34
	-	Neu 36 <= TNCT < 60 thang: he so = 3
	-	Neu TNCT >= 60 thang: he so 4.5
*/

	/*Main function*/
int main() {
	int TNCT;
	float luong, heSo;
	do{
		cout << "So thang cong tac = ";
		cin >> TNCT;
		if(TNCT <= 0)
			cout << "So thang phai lon hon hoac bang 0" << endl;
	}while(TNCT <= 0);
	
	if(TNCT < 12) heSo = 1.92;
	else if(TNCT >= 12 && TNCT < 36) heSo = 2.34;
	else if(TNCT >= 36 && TNCT < 60) heSo = 3;
	else heSo = 4.5;
	
	cout << "Luong = " << heSo*1.6 << " trieu dong";
	return 0;
}

