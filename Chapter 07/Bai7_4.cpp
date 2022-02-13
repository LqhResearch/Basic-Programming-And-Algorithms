#include<stdio.h>
/*
	De quy: S(n) = 1/2 + 1/4 + 1/6 + ... + 1/2n.
*/
float sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = 1/2 + 1/4 + 1/6 + ... + 1/2x%d = %f", n, sum(n));
	return 0;
}

	/*De quy (recursive) */
float sum(int n) {
	if(n==1)
		return 0.5;
	else
		return 1.0/(2*n) + sum(n-1);
}
