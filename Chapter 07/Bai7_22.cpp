#include<stdio.h>
/*
	Dem so luong tat ca "uoc so" cua so nguyen duong n
*/
int count(int n, int i);

int main() {
	int n, i=1;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nDem so luong uoc so cua %d: %d", n, count(n, i));
	return 0;
}

int count(int n, int i) {
	if(i==n)
		return 0;
	int dem=count(n, i+1);
	if(n%i==0)
		dem++;
	return dem;
}
