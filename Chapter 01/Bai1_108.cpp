/**************************************************************
 * Author: QHung
 * Create Date: 04/11/2021
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * Nhập chương trình:
 * Chuyển đổi độ C sang độ F.
 * Chuyển đổi độ F sang độ C.
 * 		độ F=độ C * 1.8 + 32
 **************************************************************/

#include <iostream>
using namespace std;

int main() {
    float degC, degF;
    int choice;
    cout << "+---------------------------------+" << endl;
    cout << "| 1. Chuyen doi do C sang do F    |" << endl;
    cout << "| 2. Chuyen doi do F sang do C    |" << endl;
    cout << "+---------------------------------+" << endl;
    cout << " >> Hay lua chon: ";
    cin >> choice;
    
    switch(choice) {
    	case 1: {
    		cout << "Nhap do C: ";
    		cin >> degC;
    		degF = degC * 1.8 + 32;
    		cout << degC << " do C = " << degF << " do F";
			break;
		}
		case 2: {
    		cout << "Nhap do F: ";
    		cin >> degF;
    		degC = (degF - 32) / 1.8;
    		cout << degF << " do F = " << degC << " do C";
			break;
		}
		default: {
			cout << "Khong ton tai tinh nang nay" << endl;
			break;
		}
	}
    return 0;
}
