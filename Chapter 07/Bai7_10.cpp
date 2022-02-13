#include<stdio.h>
/*
	De quy: T(x, n) = x^n
*/
int multi(int x, int n);

	/*Main function*/
int main() {
	int n, x;
	printf("Nhap x = ");
	scanf("%d", &x);
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTich T(x, n) = %d^%d = %d", x, n, multi(x, n));
	return 0;
}

	/*De quy (recursive) */
int multi(int x, int n) {
	if(n==0)
		return 1;
	else
		return x*multi(x, n-1);
}
