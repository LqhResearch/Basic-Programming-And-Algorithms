#include<stdio.h>
#include<math.h>
/*
	Viet chuong trinh nhap vao 3 so thuc.
	Neu la so am thi thay bang tri tuyet doi.
*/
int main() {
	float a, b, c;
	printf("Nhap a = ");
	scanf("%f", &a);
	printf("Nhap b = ");
	scanf("%f", &b);
	printf("Nhap c = ");
	scanf("%f", &c);
	
	a = (a > 0) ? a : abs(a);
	b = (b > 0) ? b : abs(b);
	c = (c > 0) ? c : abs(c);
	
	printf("a = %.2f\nb = %.2f\nc = %.2f\n", a, b, c);
	return 0;
}

