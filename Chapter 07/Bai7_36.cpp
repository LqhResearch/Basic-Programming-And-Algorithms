#include<stdio.h>
/*
	De quy: Tim so hang thu n cua day Fibonacci
		f(0) = f(1) = 1
		f(n) = f(n - 1) + f(n - 2)

*/
int Fibonacci(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("Fibonacci thu %d la %d", n, Fibonacci(n));
	return 0;
}

int Fibonacci(int n) {
	if(n==0 || n==1)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}
