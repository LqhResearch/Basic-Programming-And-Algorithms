/**************************************************************
 * Author: QHung
 * Create Date: 00/00/0000
 * Modify Date: 29/08/2021
 **************************************************************/

/**************************************************************
 * Bài 11.3 : Viết chương trình nhập vào một chuỗi, xử lý chuỗi như sau:
 * a. Viết hoa các ký tự đầu mỗi từ, viết thường các ký tự còn lại của từ.
 **************************************************************/

#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

void CapitilazeEachWord(char str[]) {
    strlwr(str); //Chuyen thanh chuyen thuong
    // Cach 1
    //	char *token = strtok(str, " ");
    //	while(token != NULL) {
    //		if(token[0] >= 'a' && token[0] <= 'z')	//Chuyen ki tu dau thanh in hoa
    //			token[0] -= 32;
    //		cout << token << " ";
    //		token = strtok(NULL, " ");
    //	}

    // Cach 2
    str[0] = toupper(str[0]);
    for (int i = 1; i < strlen(str); i++) {
        if (str[i - 1] == ' ')
            str[i] = toupper(str[i]);
    }
    cout << str;
}

/* Main function */
int main() {
    char str[MAX];
    cout << "Nhap chuoi: ";
    gets(str);
    CapitilazeEachWord(str);
    return 0;
}
