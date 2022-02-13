#include<stdio.h>
/*
	Viet chuong trinh nhap vao 2 so thuc.
	Kiem tra xem 2 so vua nhap co cung dau hay khong?
*/
int main() {
	float a, b;
	printf("Nhap a = ");
	scanf("%f", &a);
	printf("Nhap b = ");
	scanf("%f", &b);
	
	if((a>0 && b>0) || (a<0 && b<0))
		printf("%.2f va %.2f cung dau", a, b);
	else
		printf("%.2f va %.2f khong cung dau", a, b);
	return 0;
}

