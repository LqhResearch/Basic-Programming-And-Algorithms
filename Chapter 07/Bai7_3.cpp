#include<stdio.h>
/*
	De quy: S(n) = 1 + 1/2 + 1/3 + ... + 1/n.
*/
float sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = 1 + 1/2 + 1/3 + ... + 1/%d = %f", n, sum(n));
	return 0;
}

	/*De quy (recursive) */
float sum(int n) {
	if(n==1)
		return 1.0;
	else
		return 1.0/n + sum(n-1);
}
