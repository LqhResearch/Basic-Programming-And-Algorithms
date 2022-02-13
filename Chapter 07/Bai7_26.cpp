#include<stdio.h>
/*
	De quy: Tinh tong cac chu so cua so nguyen duong n
*/
int SumChuSo(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nTong cac chu so cua %d la %d", n, SumChuSo(n));
	return 0;
}

int SumChuSo(int n) {
	if(n == 0)
		return 0;
	int sum=SumChuSo(n/10);
	sum+=(n%10);
	return sum;
}
