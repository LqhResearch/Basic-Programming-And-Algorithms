#include <iostream>
using namespace std;
/*
	Nhap vao mot so nguyen co 3 chu so, hay in ra cach doc cua no.
*/
string read[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "muoi"};

	/*Main function*/
int main() {
	int n;
	do{
		cout << "- Nhap so = ";
		cin >> n;
		if(n < 100 || n > 999)
			cout << "Hay nhap so co 3 chu so" << endl;
	}while(n < 100 || n > 999);
	
	int t=n/100, c=(n-t*100)/10, dv=n%10;
	cout << "\nDoc la: ";
	if(c == 0) {
		if(dv == 0) cout << read[t] << " tram";
		if(dv != 0) cout << read[t] << " tram linh " << read[dv];
	}
	else if(c == 1) {
		if(dv == 0) cout << read[t] << " tram muoi";
		else if(dv == 5) cout << read[t] << " tram muoi lam";
		else cout << read[t] << " tram muoi " << read[dv];
	}
	else if(dv == 0) cout << read[t] << " tram " << read[c] << " muoi";
	else if(c != 1 && dv == 5) cout << read[t] << " tram " << read[c] << " muoi lam";
	else cout << read[t] << " tram " << read[c] << " muoi " << read[dv];
	return 0;
}

