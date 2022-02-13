#include<stdio.h>
#include<math.h>
/*
	De quy: S(n) = x + x^2/2! + x^3/3! + ... + x^n/n!
*/
int factorial(int n);
float sum(int x, int n);

int main() {
	int n, x;
	printf("Nhap x = ");
	scanf("%d", &x);
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = x + x^2/2! + x^3/3! + ... + x^n/n! = %f", sum(x, n));
	return 0;
}

int factorial(int n) {
	if(n==1)
		return 1;
	else
		return n * factorial(n-1);
}

float sum(int x, int n) {
	if(n==1)
		return 1.0*x;
	else
		return pow(1.0*x, n)/factorial(n) + sum(x, n-1);
}
