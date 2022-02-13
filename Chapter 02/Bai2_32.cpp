#include <iostream>
using namespace std;
/*
	Nhap vao mot so nguyen co 2 chu so, hay in ra cach doc cua no.
*/
string read[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi"};

	/*Main function*/
int main() {
	int n;
	do{
		cout << "- Nhap so = ";
		cin >> n;
		if(n < 10 || n > 99)
			cout << "Hay nhap so co 2 chu so" << endl;
	}while(n < 10 || n > 99);
	
	cout << "\nDoc la: ";
	if(n == 10) cout << read[10];
	else if(n == 15) cout << "muoi lam";
	else if(n%10==0) cout << read[n/10] << " muoi";
	else if(n%10==5) cout << read[n/10] << " muoi lam";
	else if(n > 10 && n < 19) cout << read[10] << " " << read[n%10];
	else cout << read[n/10] << " muoi " << read[n%10];
	return 0;
}

