#include<stdio.h>
#include<math.h>
/*
	De quy: S(n) = x + x^2 + x^3 + ... + x^n.
*/
int sum(int x, int n);

	/*Main function*/
int main() {
	int n, x;
	printf("Nhap x = ");
	scanf("%d", &x);
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = x + x^2 + x^3 + ... + x^n = %d", sum(x, n));
	return 0;
}

	/*De quy (recursion) */
int sum(int x, int n) {
	if(n==1)
		return x;
	else
		return pow(x, n) + sum(x, n-1);
}
