#include<stdio.h>
/*
	De quy: Tinh tong cac chu so chan cua so nguyen duong n
*/
int SumChuSoChan(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nTong cac chu so chan cua %d la %d", n, SumChuSoChan(n));
	return 0;
}

int SumChuSoChan(int n) {
	if(n == 0)
		return 0;
	int sum=SumChuSoChan(n/10);
	if(n%10%2 == 0)	//So chan
		sum+=(n%10);
	return sum;
}
