#include<stdio.h>
/*
	Kiem tra so nguyen duong co phai la so toan le hay khong?
*/
bool TestToanLe(int n, bool test);

int main() {
	int n;
	bool t = true;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\n%d", n);
	if(TestToanLe(n, t) == true)
		printf(" la so toan le");
	else printf(" khong phai la so toan le");
	return 0;
}

bool TestToanLe(int n, bool test) {
	if(n == 0)
		return test;
	else {
		if(n%10%2==0)
			test = false;
		return TestToanLe(n/10, test);
	}
}
