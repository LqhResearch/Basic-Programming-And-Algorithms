#include<stdio.h>
/*
	Viet chuong tinh khi nhap x se tinh gia tri: 
	2x^2 + 5x + 9 khi x >= 5
	-2x^2 + 4x - 9 khi x < 5
*/
int main() {
	int x, kq;
	printf("Nhap x = ");
	scanf("%d", &x);
	
	if(x >= 50)
		kq = 2*x*x + 5*x + 9;
	else
		kq = -2*x*x + 4*x - 9;
		
	printf("Ket qua = %d", kq);
	return 0;
}

