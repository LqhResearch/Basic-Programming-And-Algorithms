/**************************************************************
 * Author: QHung
 * Create Date: 31/08/2021
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * Bài 1.107 :	Nhập vào số tiền n đồng (n là số nguyên dương lớn hơn 1). Đổi số tiền thành các tờ có mệnh giá: 500đ, 200đ, 100đ, 50đ, 20đ, 10đ, 5đ, 2đ, 1đ. In ra số lượng tờ của từng mệnh giá.
 * Ưu tiên các tờ có mệnh giá lớn.
 **************************************************************/

#include <iostream>
using namespace std;

int moneyFaceValue[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };

int main() {
    int money;
    do {
        cout << "Nhap so tien: ";
        cin >> money;
        if (money < 1)
            cout << "\tVui long nhap so tien lon hon 0d" << endl;
    } while (money < 1);

    cout << "So tien " << money << "d bao gom: " << endl;

    int lenArray = sizeof(moneyFaceValue) / sizeof(int);
    for (int i = 0; i < lenArray; i++) {
        if (money >= moneyFaceValue[i]) {
            int piece = money / moneyFaceValue[i];
            money = money - (piece * moneyFaceValue[i]);
            cout << "\t" << piece << " to co menh gia la " << moneyFaceValue[i] << "d" << endl;
        }
    }
    return 0;
}
