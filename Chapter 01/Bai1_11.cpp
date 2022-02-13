#include<stdio.h>
/*
	Tính T(n, x) = x^n.
*/
int main() {
	int n;
	float x, luyThua = 1;
	printf("Nhap x = ");
	scanf("%f", &x);
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++)
		luyThua*=x;
	printf("Ket qua = %f", luyThua);
	return 0;
}

