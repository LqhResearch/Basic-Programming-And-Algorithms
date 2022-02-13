#include<stdio.h>
/*
	De quy: Liet ke cac so chinh phuong nho hon n
*/
int testSCP(float n);
void Listed(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nSo chinh phuong: ", n);
	Listed(n);
	return 0;
}

int testSCP(float n) {
	if(n == 1.0) return 1;
	if(n < 1.0) return 0;
	else return testSCP(n/2);
}

void Listed(int n) {
	if(n==0)
		return;
	else {
		if(testSCP(n) == 1)
			printf("%5d", n);
		return Listed(n-1);
	}
}
