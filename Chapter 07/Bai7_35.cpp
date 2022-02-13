#include<stdio.h>
/*
	Kiem tra so nguyen duong co phai la so toan chan hay khong?
*/
bool TestToanChan(int n, bool test);

int main() {
	int n;
	bool t = true;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\n%d", n);
	if(TestToanChan(n, t) == true)
		printf(" la so toan chan");
	else printf(" khong phai la so toan chan");
	return 0;
}

bool TestToanChan(int n, bool test) {
	if(n == 0)
		return test;
	else {
		if(n%10%2==1)
			test = false;
		return TestToanChan(n/10, test);
	}
}
