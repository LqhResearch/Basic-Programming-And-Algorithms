#include<stdio.h>
/*
	De quy: S(n) = 1 + 1/(1+2) + 1/(1+2+3) + ... + 1/(1+2+3+...+n)
*/
int sum1n(int n);
float sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = 1 + 1/(1+2) + 1/(1+2+3) + ... + 1/(1+2+3+...+n) = %f", sum(n));
	return 0;
}

	/*De quy (recursion) */
int sum1n(int n) {
	if(n==1)
		return 1;
	else
		return n + sum1n(n-1);
}

float sum(int n) {
	if(n==1)
		return 1.0;
	else
		return 1.0/sum1n(n) + sum(n-1);
}
