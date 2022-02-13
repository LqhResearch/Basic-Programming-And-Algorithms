#include<stdio.h>
/*
	De quy: S(n) = 1^2 + 2^2 + 3^2 + ... + n^2.
*/
int sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong tu 1^2 den %d^2 la %d", n, sum(n));
	return 0;
}

	/*De quy (recursive) */
int sum(int n) {
	if(n==1)
		return 1;
	else
		return n * n + sum(n-1);
}
