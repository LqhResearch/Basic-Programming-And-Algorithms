#include <iostream>
#include <cstring>
using namespace std;
/*
	Nhap mot chuoi ky tu, xuat ra cac tu dai nhat trong chuoi.
*/

	/*Main function*/
int main() {
	char str[100], str1[100];
	cout << "Nhap chuoi: ";
	gets(str);
	strcpy(str1, str);

	char *token = strtok(str, " ");
	int max = strlen(token);
	while(token != NULL) {
		int len = strlen(token);
		if(max < len)	max = len;
		token = strtok(NULL, " ");
	}

	token = strtok(str1, " ");
	while(token != NULL) {
		int len = strlen(token);
		if(len == max)
			cout << token << ", ";
		token = strtok(NULL, " ");
	}

	return 0;
}

