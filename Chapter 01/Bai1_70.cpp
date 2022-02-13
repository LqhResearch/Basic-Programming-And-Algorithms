#include<stdio.h>
/*
	Nhap vao 1 so nguyen duong. Phan tich thua so nguyen to.
*/
int main() {
	int n, i = 2;
	printf("So nguyen duong = ");
	scanf("%d", &n);
	
	printf("%5d = ", n);
	while(n > 1) {
		while(n%i) i++;
		n/=i;
		printf(n > 1 ? " %d *" : " %d", i);
	}
	return 0;
}

