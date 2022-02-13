#include <iostream>
#include <string>
using namespace std;
/*
	Nhap mot chuoi ky tu chua it nhat 4 ky tu so.
	Loai bo mot so ky tu ra khoi chuoi sao cho 4 ky tu so cung cung con lai (theo dung thu tu do) tao nen so lon nhat.
*/

	/*Main function*/
int main() {
	string str;
	cout << "Nhap chuoi: ";
	getline(cin, str);
	
	int count = 0, end;
	for(end=str.length()-1; end>=0; end--) {
		if(str[end] >= '0' && str[end] <= '9')	count++;
		if(count == 4)	break;
	}
	
	int max = str[end] - 48, vt = end;
	for(int i=0; i<end; i++)
		if(str[i] >= '0' && str[i] <= '9') {
			int temp = str[i] - 48;
			if(temp > max) {
				max = temp;
				vt = i;
			}
		}
	
	cout << "So lon nhat: ";
	count = 0;
	for(int i=vt; i<str.length(); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			cout << str[i] - 48;
			count++;
		}
		if(count == 4) break;
	}
	return 0;
}

