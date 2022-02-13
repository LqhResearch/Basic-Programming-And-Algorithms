#include<stdio.h>
#include<math.h>
/*
	De quy: S(n) = x + x^3 + x^5 + ... + x^(2n+1)
*/
int sum(int x, int n);

	/*Main function*/
int main() {
	int n, x;
	printf("Nhap x = ");
	scanf("%d", &x);
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = x + x^3 + x^5 + ... + x^(2n+1) = %d", sum(x, n));
	return 0;
}

	/*De quy (recursion) */
int sum(int x, int n) {
	if(n==0)
		return x;
	else
		return pow(x, 2*n+1) + sum(x, n-1);
}
