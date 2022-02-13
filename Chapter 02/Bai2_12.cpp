#include<stdio.h>
/*
	Viet chuong trinh nhap 3 so thuc. Hay in so thuc ay ra man hinh theo thu tu tang dan.
	Luu y: Chi dung toi da 2 bien phu
*/
int main() {
	float a, b, c, temp;
	printf("Nhap 3 so thuc: \n");
	scanf("%f%f%f", &a, &b, &c);
	if(a > b) {
		temp = a;
		a = b;
		b = temp;
	}
	if(b > c) {
		temp = b;
		b = c;
		c = temp;
	}
	if(a > c) {
		temp = a;
		a = c;
		c = temp;
	}
	printf("Tang dan: %5.2f%5.2f%5.2f", a, b, c);
	return 0;
}

