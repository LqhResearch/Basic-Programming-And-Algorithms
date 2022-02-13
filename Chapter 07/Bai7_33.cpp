#include<stdio.h>
/*
	De quy: Tim chu so lon nhat, nho nhat cua so nguyen n
*/
int MaxChuSo(int n, int max);
int MinChuSo(int n, int min);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int max = n%10;
	int min = n%10;
	printf("\nChu so lon nhat cua %d la %d", n, MaxChuSo(n, max));
	printf("\nChu so nho nhat cua %d la %d", n, MinChuSo(n, min));
	return 0;
}

int MaxChuSo(int n, int max) {
	if(n == 0)
		return max;
	else {
		if(n%10 > max)
			max = n%10;
		return MaxChuSo(n/10, max);
	}
}

int MinChuSo(int n, int min) {
	if(n == 0)
		return min;
	else {
		if(n%10 < min)
			min = n%10;
		return MinChuSo(n/10, min);
	}
}
