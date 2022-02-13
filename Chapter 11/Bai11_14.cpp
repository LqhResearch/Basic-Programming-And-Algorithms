/**************************************************************
 * Author: QHung
 * Create Date: 07/09/2021
 * Modify Date: 00/00/0000
 **************************************************************/

/**************************************************************
 * Viết chương trình nhập một chữ số, ký tự hoặc biểu tượng từ người dùng, sau đó kiểm tra xem đó là loại nào và in kết quả.
 **************************************************************/

#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Nhap mot ky tu bat ky: ";
    cin >> c;

    if (c >= 'A' && c <= 'Z') {
        cout << c << " la chu cai in hoa";
    } else if (c >= 'a' && c <= 'z') {
        cout << c << " la chu cai in thuong";
    } else if (c >= '0' && c <= '9') {
        cout << c << " la so";
    } else {
        cout << c << " la ky tu dac biet";
    }
    return 0;
}
