#include <iostream>
using namespace std;
/*
	Viet chuong trinh kiem tra 2 ve.
*/

	/*Main function*/
int main() {
	int n;
	cout << "Nhap so nguyen >= 3 : ";
	cin >> n;
	
	int left = 0;	//Ve trai
	for(int i=1; i<=n; i++)
		left += (i*i*i);
	
	int right = n*n*(n+1)*(n+1)/4;
	cout << "Ve trai = " << left << endl;
	cout << "Ve phai = " << right << endl;
	return 0;
}

