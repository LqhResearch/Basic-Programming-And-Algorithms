#include<stdio.h>
/*
	Tinh tich tat ca "uoc so" cua so nguyen duong n
*/
int multi(int n, int i);

int main() {
	int n, i=1;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTich uoc so cua %d: %d", n, multi(n, i));
	return 0;
}

int multi(int n, int i) {
	if(i==n)
		return 1;
	int tich=multi(n, i+1);
	if(n%i==0)
		tich*=i;
	return tich;
}
