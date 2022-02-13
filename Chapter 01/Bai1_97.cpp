/**************************************************************
 * Author: QHung
 * Create Date: 00/00/0000
 * Modify Date: 31/08/2021
 **************************************************************/

/**************************************************************
 * Viết chương trình nhập vào thông tin tiêu thụ điện (tên, số Kw) và thuế là 10%. Tính và xuất tiền trả theo quy tắc:
 * Bậc 1: Cho kWh từ 0 - 50 giá 1.678
 * Bậc 2: Cho kWh từ 51 - 100 giá 1.734
 * Bậc 3: Cho kWh từ 101 - 200 giá 2.014
 * Bậc 4: Cho kWh từ 201 - 300 giá 2.536
 * Bậc 5: Cho kWh từ 301 - 400 giá 2.834
 * Bậc 6: Cho kWh từ 401 trở lên giá 2.927
 **************************************************************/

#include <iostream>
using namespace std;

struct ElectricityPrice {
    int start;
    int end;
    int price;

    ElectricityPrice(int _start, int _end, int _price) {
        start = _start;
        end = _end;
        price = _price;
    }
};

ElectricityPrice priceList[] = {
    ElectricityPrice(1, 50, 1678),
    ElectricityPrice(51, 100, 1734),
    ElectricityPrice(101, 200, 2014),
    ElectricityPrice(201, 300, 2536),
    ElectricityPrice(301, 400, 2834),
    ElectricityPrice(401, 0, 2927)
};

	/*Main function*/
int main() {
    string customer;
    int kwH = 0, money = 0;
    cout << "Ten khach hang: ";
    getline(cin, customer);
    do {
        cout << "So kw dien: ";
        cin >> kwH;
        if (kwH < 1)
            cout << "So kw dien phai lon hon 0";
    } while (kwH < 1);

    int lenArray = sizeof(priceList) / sizeof(ElectricityPrice);

    cout << "\t==========Hoa Don==========" << endl;
    cout << "Khach hang: " << customer << endl;
    cout << "So kw dien: " << kwH << endl;

    for (int i = lenArray - 1; i >= 0; i--) {
        if (kwH >= priceList[i].start) {
            int number = (kwH - priceList[i].start + 1);
            int price = number * priceList[i].price;
            cout << "Tu " << priceList[i].start << " - " << kwH << " gia " << priceList[i].price << "d : " 
				 << number << " x " << priceList[i].price << " = " << price << "d" << endl;
			
			kwH -= number;
            money += price;
        }
    }

    int tax = money * 0.1; //Thue
    cout << "Tien dien: " << money << "d" << endl;
    cout << "Thue (10%): " << tax << "d" << endl;
    cout << "Tong cong: " << money + tax << "d" << endl;
    return 0;
}
