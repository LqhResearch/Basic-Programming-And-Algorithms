#include<stdio.h>
/*
	De quy: S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1).
*/
float sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = 1 + 1/3 + 1/5 + ... + 1/(2x%d+1) = %f", n, sum(n));
	return 0;
}

	/*De quy (recursive) */
float sum(int n) {
	if(n==0)
		return 1;
	else
		return 1.0/(2*n+1) + sum(n-1);
}
