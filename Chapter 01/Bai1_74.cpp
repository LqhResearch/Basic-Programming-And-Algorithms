#include<stdio.h>
/*
	Tim gia tri lon nhat cua 4 sô a, b, c, d.
*/
int main() {
	int a, b, c, d, max;
	printf("Nhap a = ");	scanf("%d", &a);
	printf("Nhap b = ");	scanf("%d", &b);
	printf("Nhap c = ");	scanf("%d", &c);
	printf("Nhap d = ");	scanf("%d", &d);
	max = a;
	if(b > max) max = b;
	if(c > max) max = c;
	if(d > max) max = d;
	printf("Max = %d", max);
	return 0;
}

