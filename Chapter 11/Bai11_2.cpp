#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;
/*
	Bài 11.2 : 	Viết các hàm mô phỏng các hàm của string.h sau: 
	-	Hàm strcat(s1, s2) : Nối chuỗi s2 vào chuỗi s1.
	-	Hàm strchr(s, c) : Hàm trả về vị trí đầu tiên ki tự c trong chuỗi s.
	-	Hàm strcmp (s1, s2) : So sánh 2 chuỗi.
	-	Hàm strcpy(s1, s2) : Sao chép chuỗi s2 vào chuỗi s1.
	-	Hàm strcspn(s1, s2) : Trả về vị trí kí tự đầu tiên của s2 trong s1.
	-	Hàm strlen (s) : Trả về độ dài của chuỗi.
	-	Hàm strncat(s1, s2, n) : Nối n kí tự chuỗi s2 vào chuỗi s1.
	-	Hàm strncmp(s1, s2, n) : So sánh n kí tự kí tự của chuỗi s2.
	-	Hàm strncpy(s1, s2, n) : So sánh n kí tự kí tự của chuỗi s2 thành chuỗi s1.
	-	Hàm strpbrk(s1, s2) : Trả về chuỗi kí tự của chuỗi s2 xuất hiện đầu tiên trong chuỗi s1.
	-	Hàm strrchr(s, c) : Hàm trả về vị trí cuối cùng kí tự c trong chuỗi s.
	-	Hàm strspn(s1, s2) : Hàm trả về số kí tự của chuỗi s2 giống chuỗi s1 tính từ đầu chuỗi.
	-	Hàm strstr(s1, s2) : Hàm trả về vị trí bắt đầu kí tự của chuỗi s2.
	-	Hàm strupr(s) : Hàm trả về chuỗi chứa kí tự In hoa.
	-	Hàm strlwr(s) : Hàm trả về chuỗi chứa kí tự In thường.
	-	Hàm strrev(s): Hàm trả vễ chuỗi đảo ngược.
*/
void menu();
void inp(char * );
void out(char * );
void strcatNew(char * , char * );
void strchrNew(char * , char);
int strcmpNew(char * , char * );
void strcpyNew(char * , char * );
int strcspnNew(char * , char * );
int strlenNew(char * );
void strncatNew(char * , char * , int);
int strncmpNew(char * , char * , int);
void strncpyNew(char * , char * , int);
char strpbrkNew(char * , char * );
void strrchrNew(char * , char);
int strspnNew(char * , char * );
char * strstrNew(char * , char * );
void struprNew(char * );
void strlwrNew(char * );
char * strrevNew(char * );

/*Main function */
int main() {
    do {
        menu();
    } while (true);
    return 0;
}

/* Cac chuc nang thuoc thu vien string.h */
void menu() {
    int choice, n;
    char c;
    char * str1 = (char * ) malloc(20 * sizeof(char));
    char * str2 = (char * ) malloc(20 * sizeof(char));
    char * ans = (char * ) malloc(20 * sizeof(char));
    do {
        cout << "\n\t==========Mo phong Thu vien string.h==========" << endl;
        cout << "1. strcat - Noi chuoi 2 vao chuoi 1." << endl;
        cout << "2. strchr - Ham tra ve vi tri dau tien ki tu c trong chuoi s." << endl;
        cout << "3. strcmp - So sanh 2 chuoi." << endl;
        cout << "4. strcpy - Sao chep chuoi s1 thanh s2." << endl;
        cout << "5. strcspn - Tra ve vi tri ki tu dau tien cua s2 trong s1." << endl;
        cout << "6. strlen - Tra ve do dai cua chuoi." << endl;
        cout << "7. strncat - Noi n ki tu chuoi 2 vao chuoi 1." << endl;
        cout << "8. strncmp - So sanh n ki tu cua 2 chuoi." << endl;
        cout << "9. strncpy - Sao chep n ki tu chuoi s2 thanh chuoi s1." << endl;
        cout << "10. strpbrk - Tra ve ki tu cua chuoi 2 xuat hien dau tien trong chuoi 1." << endl;
        cout << "11. strrchr - Ham tra ve vi tri cuoi cung ki tu c trong chuoi s." << endl;
        cout << "12. strspn - Ham tra ve so ki tu cua chuoi s2 giong chuoi s1 tinh tu dau chuoi." << endl;
        cout << "13. strstr - Ham tra ve vi tri bat dau ki tu cua chuoi s2." << endl;
        cout << "14. strupr - Ham tra ve chuoi chua ki tu In hoa." << endl;
        cout << "15. strlwr - Ham tra ve chuoi chua ki tu In thuong." << endl;
        cout << "16. strrev - Ham tra ve chuoi dao nguoc." << endl;
        cout << "0. Thoat" << endl;
        cout << " >> Hay lua chon: ";
        cin >> choice;
        if (choice < 0 || choice > 16)
            cout << "Chuc nang nay khong ton tai" << endl;
    } while (choice < 0 || choice > 16);

    switch (choice) {
	    case 1: {
	        inp(str1);
	        inp(str2);
	        strcatNew(str1, str2);
	        cout << endl;
	        out(str1);
	        break;
	    }
	    case 2: {
	        inp(str1);
	        cout << "Nhap 1 ki tu: ";
	        cin >> c;
	        strchrNew(str1, c);
	        out(str1);
	        break;
	    }
	    case 3: {
	        inp(str1);
	        inp(str2);
	        int ans = strcmpNew(str1, str2);
	        if (ans == -1)
	            cout << "\nChuoi 1 ngan hon chuoi 2";
	        else if (ans == 1)
	            cout << "\nChuoi 1 dai hon chuoi 2";
	        else cout << "\nHai chuoi bang nhau";
	        break;
	    }
	    case 4: {
	        inp(str1);
	        inp(str2);
	        strcpyNew(str1, str2);
	        out(str1);
	        break;
	    }
	    case 5: {
	        inp(str1);
	        inp(str2);
	        int ans = strcspnNew(str1, str2);
	        if (ans == -1)
	            cout << "\nKhong tim thay";
	        else cout << "\nBat dau tai vi tri: " << ans + 1;
	        break;
	    }
	    case 6: {
	        inp(str1);
	        cout << "\nDo dai chuoi la " << strlenNew(str1);
	        break;
	    }
	    case 7: {
	        inp(str1);
	        inp(str2);
	        cout << "Nhap so ki tu: ";
	        cin >> n;
	        strncatNew(str1, str2, n);
	        cout << endl;
	        out(str1);
	        break;
	    }
	    case 8: {
	        inp(str1);
	        inp(str2);
	        cout << "Nhap so ki tu: ";
	        cin >> n;
	        int ans = strncmpNew(str1, str2, n);
	        if (ans == -1)
	            cout << "\nChuoi 1 ngan hon chuoi 2";
	        else if (ans == 1)
	            cout << "\nChuoi 1 dai hon chuoi 2";
	        else cout << "\nHai chuoi bang nhau";
	        break;
	    }
	    case 9: {
	        inp(str1);
	        inp(str2);
	        cout << "Nhap so ki tu: ";
	        cin >> n;
	        strncpyNew(str1, str2, n);
	        out(str1);
	        break;
	    }
	    case 10: {
	        inp(str1);
	        inp(str2);
	        c = strpbrkNew(str1, str2);
	        cout << "\nKi tu xuat hien: " << c;
	        break;
	    }
	    case 11: {
	        inp(str1);
	        cout << "Nhap 1 ki tu: ";
	        cin >> c;
	        strrchrNew(str1, c);
	        out(str1);
	        break;
	    }
	    case 12: {
	        inp(str1);
	        inp(str2);
	        cout << "\nSo ki tu giong nhau: " << strspnNew(str1, str2);
	        break;
	    }
	    case 13: {
	        inp(str1);
	        inp(str2);
	        ans = strstrNew(str1, str2);
	        if (ans[0] == '\0')
	            cout << "Ket qua: (null)";
	        else out(ans);
	        break;
	    }
	    case 14: {
	        inp(str1);
	        cout << "\nChuyen thanh in hoa: " << endl;
	        struprNew(str1);
	        out(str1);
	        break;
	    }
	    case 15: {
	        inp(str1);
	        cout << "\nChuyen thanh in thuong: " << endl;
	        strlwrNew(str1);
	        out(str1);
	        break;
	    }
	    case 16: {
	        inp(str1);
	        cout << "\nChuoi dao nguoc: " << endl;
	        out(strrevNew(str1));
	        break;
	    }
	    case 0: {
	        cout << "\n==========Thank you for using==========" << endl;
	        free(str1);
	        free(str2);
	        free(ans);
	        exit(0);
	    }
    }
}

/* Tra ve 1 chuoi */
void inp(char * str) {
    fflush(stdin); //Xoa vung dem
    cout << "Nhap chuoi: ";
    gets(str);
}

/* Xuat 1 chuoi */
void out(char * str) {
    cout << "Chuoi ki tu: ";
    for (int i = 0; i < strlen(str); i++)
        cout << str[i];
}

/* Ham noi chuoi 2 vao chuoi 1 */
void strcatNew(char * str1, char * str2) {
    int len1 = strlenNew(str1);
    int len2 = strlenNew(str2);
    
    for (int i = 0; i < len2; i++)
        str1[len1 + i] = str2[i];
    str1[len1 + len2] = '\0';
}

/* Ham tra ve vi tri dau tien ki tu c trong chuoi s */
void strchrNew(char * str, char c) {
    int index = -1, len = strlenNew(str);
    for (int i = 0; i < len; i++)
        if (str[i] == c) {
            index = i;
            break;
        }

    if (index != -1) {
        for (int i = index; i < len; i++)
            str[i - index] = str[i];
        str[len - index] = '\0';
    }
}

/* So sanh 2 chuoi */
int strcmpNew(char * str1, char * str2) {
    int len1 = strlenNew(str1);
    int len2 = strlenNew(str2);
    int max = len1 > len2 ? len1 : len2;
    
    for (int i = 0; i < max; i++)
        if (str1[i] != str2[i]) {
            if (str1[i] > str2[i])
                return 1;
            if (str1[i] < str2[i])
                return -1;
        }
    return 0;
}

/* Sao chep chuoi s1 thanh s2 */
void strcpyNew(char * str1, char * str2) {
    int len = strlenNew(str2);
    for (int i = 0; i < len; i++)
        str1[i] = str2[i];
    str1[len] = '\0';
}

/* Tra ve vi tri ki tu dau tien cua s2 trong s1 */
int strcspnNew(char * str1, char * str2) {
    int len = strlenNew(str1);
    for (int i = 0; i < len; i++)
        if (str1[i] == str2[0])
            return i;
    return -1;
}

/* Tra ve do dai chuoi ki tu */
int strlenNew(char * str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

/* Noi n ki tu chuoi 2 vao chuoi 1 */
void strncatNew(char * str1, char * str2, int n) {
    int len1 = strlenNew(str1);
    for (int i = 0; i < n; i++)
        str1[len1 + i] = str2[i];
    str1[len1 + n] = '\0';
}

/* So sanh n ki tu cua 2 chuoi */
int strncmpNew(char * str1, char * str2, int n) {
    for (int i = 0; i < n; i++)
        if (str1[i] != str2[i]) {
            if (str1[i] > str2[i])
                return 1;
            if (str1[i] < str2[i])
                return -1;
        }
    return 0;
}

/* Sao chep n ki tu chuoi s2 thanh chuoi s1 */
void strncpyNew(char * str1, char * str2, int n) {
    for (int i = 0; i < n; i++)
        str1[i] = str2[i];
    str1[n] = '\0';
}

/* Tra ve ki tu cua chuoi 2 xuat hien dau tien trong chuoi 1 */
char strpbrkNew(char * str1, char * str2) {
    for (int i = 0; i < strlenNew(str1); i++)
        for (int j = 0; j < strlenNew(str2); j++)
            if (str1[i] == str2[j])
                return str2[j];
}

/* Ham tra ve vi tri cuoi cung ki tu c trong chuoi s */
void strrchrNew(char * str, char c) {
    char * s = (char * )"\0";
    int index = -1;
    for (int i = strlenNew(str) - 1; i >= 0; i--)
        if (str[i] == c) {
            index = i;
            break;
        }
    if (index != -1) {
        int len = strlenNew(str);
        for (int i = index; i < len; i++)
            str[i - index] = str[i];
        str[len - index] = '\0';
    }
}

/* Ham tra ve so ki tu cua chuoi s2 giong chuoi s1 tinh tu dau */
int strspnNew(char * str1, char * str2) {
    int count = 0;
    for (int i = 0; i < strlenNew(str1); i++)
        if (str1[i] == str2[i])
            count++;
        else break;
    return count;
}

/* Ham tra ve vi tri bat dau ki tu cua chuoi s2 */
char * strstrNew(char * str1, char * str2) {
    char * str = (char * ) malloc(20 * sizeof(char));
    int index = -1;
    int len1 = strlenNew(str1), len2 = strlenNew(str2);
    
    for (int i = len1 - 1; i >= 0; i--)
        if (str1[i] == str2[0])
            index = i;
    for (int i = index; i < len2; i++)
        if (str1[i] != str2[i - index]) {
            str[0] = '\0';
            return str;
        }
    for (int i = index; i < len1; i++)
        str[i - index] = str1[i];
        
    str[len1 - index] = '\0';
    return str;
}

/* Ham tra ve chuoi chua ki tu In hoa. */
void struprNew(char * str) {
    for (int i = 0; i < strlenNew(str); i++)
        if (str[i] >= 97 && str[i] <= 122) //97=A --> 122=Z
            str[i] -= 32;
}

/* Ham tra ve chuoi chua ki tu In thuong. */
void strlwrNew(char * str) {
    for (int i = 0; i < strlenNew(str); i++)
        if (str[i] >= 65 && str[i] <= 90) //65=a --> 90=z
            str[i] += 32;
}

/*  Hàm trả vễ chuỗi đảo ngược.  */
char * strrevNew(char * str) {
    int len = strlenNew(str);
    char * res = (char * ) malloc(len * sizeof(char));
    int indexRes = 0, indexStr = len - 1;

    while (indexStr >= 0) {
        res[indexRes] = str[indexStr];
        indexRes++;
        indexStr--;
    }
    return res;
}
