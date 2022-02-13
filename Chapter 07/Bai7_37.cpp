#include<stdio.h>
/*
	De quy: Viet ham tinh so hang thu n cua 2 day sau:
		x(0) = 1
		y(0) = 0;
		x(n) = x(n-1) + y(n-1)
		y(n) = 3 * x(n-1) + y(n-1)
*/
int TinhXn(int n);
int TinhYn(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nx(n) = %d", TinhXn(n));
	printf("\ny(n) = %d", TinhYn(n));
	return 0;
}

int TinhXn(int n) {
	if(n==0)
		return 1;
	else
		return TinhXn(n-1) + TinhYn(n-1);
}

int TinhYn(int n) {
	if(n==0)
		return 0;
	else
		return 3*TinhXn(n-1) + TinhYn(n-1);
}

