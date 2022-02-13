#include<stdio.h>
/*
	De quy: S(n) = 1/2 + 2/3 + 3/4 + ... + n/(n+1)
*/
float sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = 1/2 + 2/3 + 3/4 + ... + %d/(%d+1) = %f", n, n, sum(n));
	return 0;
}

	/*De quy (recursive) */
float sum(int n) {
	if(n==1)
		return 0.5;
	else
		return 1.0*n/(n+1) + sum(n-1);
}
