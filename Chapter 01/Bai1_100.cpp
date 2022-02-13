#include <iostream>
using namespace std;
/*
	Viet chuong trinh tinh hoa don khach hang cho mot cong ty cap.
	Co 2 loai khach hang: Nhan dan va Doanh ngiep. Co 2 muc gia tri tinh toan tren cap:
	-	Doi voi khach hang nha dan
		+	Phi xu li hoa don: 4.5 $
		+	Phi dich vu co ban: 20.5 $
		+	Thue kenh cao cao: 7.5 $ / kenh
	-	Doi voi khach hang doanh nghiep
		+	Phi xu li hoa don: 15 $
		+	Phi dich vu co ban: 75 $ cho 10 ket noi dau, 5 $ cho moi ket noi them
		+	Thue kenh cao cao: 50 $ / kenh
*/

	/*Khach hang doanh nghiep*/
float Enterprise() {
	int service;
	cout << "- So dau noi: ";
	cin >> service;
	float total = 140;
	if(service > 10)
		total+=(service-10)*5;
	return total;
}

	/*Main function*/
int main() {
	int choice;
	do{
		cout << "\n\t==========Khach hang==========" << endl;
		cout << "1. Nha dan" << endl;
		cout << "2. Doanh nghiep" << endl;
		cout << " >> Hay chon: ";
		cin >> choice;
		if(choice != 1 && choice != 2)
			cout << "Khong co loai khach hang nay" << endl;
	}while(choice != 1 && choice != 2);
	
	switch(choice) {
		case 1:{
			cout << "Gia: 32.5 $" << endl;
			break;
		}
		case 2:{
			cout << "Gia: " << Enterprise() << " $" << endl;
			break;
		}
	}
	return 0;
}

