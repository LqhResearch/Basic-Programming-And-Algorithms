#include<stdio.h>
/*
	De quy: S(n) = 1 + 2 + 3 + ... + n.
*/
int sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong tu 1 den %d la %d", n, sum(n));
	return 0;
}

	/*De quy (recursive) */
int sum(int n) {
	if(n==1)
		return 1;
	else
		return n + sum(n-1);
}
