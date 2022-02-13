#include <iostream>
#include <cstring>
using namespace std;
/*
	Viet ham tim kiem trong mot so chuoi cho truoc, mot chuoi so trung voi chuoi mau.
	Cho phep chuoi mau dung ky tu dai dien (wildcard): *. Ky tu *: so trung voi khong hoac nhieu ky tu bat ki tai vi tri tuong ung trong chuoi cho truoc.
	Vd: Input: Danh sach cac tu: television menu editions education
       	Output: Tim [*e*u*]: menu education
				Tim [e*i*n]: education
				Tim [*e*o*]: television editions education
*/
bool find(char* s, char inp[]) {
	int j=-1;
	if(inp[0] != '*' && inp[0] != s[0]) return false;
	if(inp[4] != '*' && inp[4] != s[strlen(s)-1]) return false;
	for(int i=0; i<5; i++) {
		if(inp[i] == '*')	continue;
		bool flag = false;
		for(++j; j<strlen(s); j++)
			if(s[j] == inp[i]) {
				flag = true;
				break;
			}	
		if(flag == false) return false;
	}
	return true;
}

	/*Main function*/
int main() {
	char str[100], key[10];
	cout << "- Nhap cum tu: ";
	gets(str);
	cout << "- Nhap tu khoa: ";
	do{
		gets(key);
		if(strlen(key) != 5)
			cout << "\nVui long nhap dung 5 ki tu\n- Nhap lai tu khoa: ";
	}while(strlen(key) != 5);
	
	cout << "\nCac tu tuong thich: ";
	char *token = strtok(str, " ");
	while(token != NULL) {
		if(find(token, key) == true)
			cout << token << ", ";
		token = strtok(NULL, " ");
	}
	return 0;
}

