#include <iostream>
#include <cstring>
using namespace std;
/*
	Khong su dung cac su dung cac ham cua string.h, viet chuong trinh dao cac tu trong mot chuoi.
*/

	/*Main function*/
int main() {
	char str[50], temp[50];
	cout << "Nhap chuoi: ";
	gets(str);

	int vt=0, end = strlen(str)-1, start, j;
	while(vt <= strlen(str)) {
		for(j=end; j>=0; j--) {
			if(str[j] == ' ') {
				start = j+1; break;
			}
			if(j==0) start=0;
		}	
		for(int k=start; k<=end; k++) {
			temp[vt] = str[k];	vt++;
		}
		temp[vt] = ' '; vt++;
		end = start-2; j=end;
	}
	cout << "Chuoi dao nguoc tu: " << temp;
	return 0;
}

