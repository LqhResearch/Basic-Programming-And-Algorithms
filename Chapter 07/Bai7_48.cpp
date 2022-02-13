#include <iostream>
using namespace std;
/*
	Gia su dan so the gioi nam 2020 la 8 ti nguoi voi muc tang truong hang nam khong doi la 2.5%.
	Viet ham de quy tinh dan so the gioi nam 2030.
*/
long long DanSo(int n) {
	if(n == 0)
		return 8000000000;
	else
		return 1.025*DanSo(n-1);
}

	/*Main function*/
int main() {
	int nowYear=2020, nextYear=2030;
	int n = nextYear - nowYear;
	
	cout << DanSo(n) << " nguoi";
	return 0;
}

