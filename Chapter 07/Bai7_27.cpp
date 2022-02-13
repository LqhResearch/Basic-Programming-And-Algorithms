#include<stdio.h>
/*
	De quy: Tinh tich cac chu so cua so nguyen duong n
*/
int MultiChuSo(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nTich cac chu so cua %d la %d", n, MultiChuSo(n));
	return 0;
}

int MultiChuSo(int n) {
	if(n == 0)
		return 1;
	int multi=MultiChuSo(n/10);
	multi*=(n%10);
	return multi;
}
