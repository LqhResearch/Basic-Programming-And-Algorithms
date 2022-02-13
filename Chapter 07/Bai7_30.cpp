#include<stdio.h>
/*
	De quy: Tinh tich cac chu so le cua so nguyen duong n
*/
int MultiChuSoLe(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nTich cac chu so le cua %d la %d", n, MultiChuSoLe(n));
	return 0;
}

int MultiChuSoLe(int n) {
	if(n == 0)
		return 1;
	int multi=MultiChuSoLe(n/10);
	if(n%10%2 == 1)
		multi*=(n%10);
	return multi;
}
