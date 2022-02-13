#include<stdio.h>
/*
	De quy: Dem so luong chu so le trong so nguyen duong n
*/
int CountChuSoLe(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nSo %d co %d chu so le", n, CountChuSoLe(n));
	return 0;
}

int CountChuSoLe(int n) {
	if(n == 0)
		return 0;
	int count=CountChuSoLe(n/10);
	if(n%10%2==1)
		count++;
	return count;
}
