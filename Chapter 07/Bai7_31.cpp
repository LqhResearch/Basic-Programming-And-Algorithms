#include<stdio.h>
/*
	De quy: Nhap vao so nguyen duong n. Hay tim chu so dau tien cua n
*/
int FirstNum(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nChu so dau tien cua %d la %d", n, FirstNum(n));
	return 0;
}

int FirstNum(int n) {
	if(n < 10)
		return n;
	else return FirstNum(n/10);
}
