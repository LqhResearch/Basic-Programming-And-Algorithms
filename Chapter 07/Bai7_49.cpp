#include <iostream>
#include <cstring>
using namespace std;
/*
	Viet chuong trinh de quy nhap vao mot dong van ban, sau do hien thi dong van ban dao cua van ban nhap.
	Vd: Input: race fast safe car
        Output: rac efas tsaf ecar
*/
void Reverse(char str[], int n) {
	if(n == -1)
		return;
	else {
		cout << str[n];
		return Reverse(str, n-1);
	}
}

	/*Main function*/
int main() {
	char str[50];
	cout << "Nhap chuoi = ";
	gets(str);
	int n = strlen(str);
	
	cout << "Chuoi dao nguoc: ";
	Reverse(str, n);
	return 0;
}

