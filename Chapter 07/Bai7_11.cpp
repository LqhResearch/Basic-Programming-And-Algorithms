#include<stdio.h>
/*
	De quy S(n) = 1 + 1x2 + 1x2x3 + ... + 1x2x3x...xn
*/
int factorial(int n);
int sum(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = 1 + 1x2 + 1x2x3 + ... + 1x2x3x...x%d = %d", n, sum(n));
	return 0;
}

	/*De quy (recursive) */
int factorial(int n) {
	if(n==1)
		return 1;
	else
		return n * factorial(n-1);
}

int sum(int n) {
	if(n==1)
		return 1;
	else
		return factorial(n) + sum(n-1);
}
