#include<stdio.h>
#include<math.h>
/*
	De quy: Hay tim so dao cua so nguyen duong n
*/
int SoDao(int n, int sd);

int main() {
	int n, sd=0;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nSo dao cua %d la %d", n, SoDao(n, sd));
	return 0;
}

int SoDao(int n, int sd) {
	if(n == 0)
		return sd;
	else {
		sd = sd*10 + n%10;
		return SoDao(n/10, sd);
	}
}
