/*
	Viet chuong trình tìm hai so nguyên khi biet tong và hieu cua hai so nguyên do.
	VD: Tong = 10, Hieu = 2 ==> Hai so nguyên là 6 và 4
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

