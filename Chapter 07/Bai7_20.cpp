#include<stdio.h>
/*
	Tinh tong tat ca "uoc so" cua so nguyen duong n
*/
int sum(int n, int i);

int main() {
	int n, i=1;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong uoc so cua %d: %d", n, sum(n, i));
	return 0;
}

int sum(int n, int i) {
	if(i==n)
		return 0;
	int tong=sum(n, i+1);
	if(n%i==0)
		tong+=i;
	return tong;
}
