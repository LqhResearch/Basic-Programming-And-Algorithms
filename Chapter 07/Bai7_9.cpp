#include<stdio.h>
/*
	De quy: T(n) = 1 x 2 x 3 x ... x n
*/
int multi(int n);

	/*Main function*/
int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTich T(n) = 1 x 2 x 3 x ... x %d = %d", n, multi(n));
	return 0;
}

	/*De quy (recursive) */
int multi(int n) {
	if(n==0)
		return 1;
	else
		return n*multi(n-1);
}
