#include<stdio.h>
/*
	De quy: Dem so luong chu so cua so nguyen duong n
*/
int CountChuSo(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nSo %d co %d chu so", n, CountChuSo(n));
	return 0;
}

int CountChuSo(int n) {
	if(n == 0)
		return 0;
	int count=CountChuSo(n/10);
	count++;
	return count;
}
