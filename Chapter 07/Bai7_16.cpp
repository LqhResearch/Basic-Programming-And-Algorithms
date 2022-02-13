#include<stdio.h>
#include<math.h>
/*
	De quy: S(n) = x + x^2/(1+2) + x^3/(1+2+3) + ... + x^n/(1+2+3+...+n)
*/
int sum1n(int n);
float sum(int x, int n);

	/*Main function*/
int main() {
	int n, x;
	printf("Nhap x = ");
	scanf("%d", &x);
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = x + x^2/(1+2) + x^3/(1+2+3) + ... + x^n/(1+2+3+...+n) = %f", sum(x, n));
	return 0;
}

	/*De quy (recursion) */
int sum1n(int n) {
	if(n==1)
		return 1;
	else
		return n + sum1n(n-1);
}

float sum(int x, int n) {
	if(n==1)
		return 1.0*x;
	else
		return pow(1.0*x, n)/sum1n(n) + sum(x, n-1);
}
