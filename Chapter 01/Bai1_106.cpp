/*
	Viet chuong tr�nh t�m hai so nguy�n khi biet tong v� hieu cua hai so nguy�n do.
	VD: Tong = 10, Hieu = 2 ==> Hai so nguy�n l� 6 v� 4
*/
#include <iostream>
using namespace std;

int main() {
	int a, b, sum, sub;
	printf("- Tong = ");
	scanf("%d", &sum);
	printf("- Hieu = ");
	scanf("%d", &sub);
	
	a = (sum + sub) / 2;
	b = (sum - sub) / 2;
	
	printf("Hai so nguyen la %d va %d", a, b);
	return 0;
}

