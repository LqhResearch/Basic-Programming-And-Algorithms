#include<stdio.h>
/*
	De quy: S(n) = 1/2 + 3/4 + 5/6 + ... + (2n+1)/(2n+2)
*/
float sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = 1/2 + 3/4 + 5/6 + ... + (2x%d+1)/(2x%d+2) = %f", n, n, sum(n));
	return 0;
}

	/*De quy (recursive) */
float sum(int n) {
	if(n==0)
		return 0.5;
	else
		return (1.0*2*n+1)/(2*n+2) + sum(n-1);
}
