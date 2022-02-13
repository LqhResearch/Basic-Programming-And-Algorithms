#include<stdio.h>
/*
	Nhap vao 2 so nguyen duong. 
	-	Tim uoc so chung lon nhat.
	-	Tim boi so chung nho nhat.
*/
int main() {
	int a, b, us;
	printf("So thu nhat = ");
	scanf("%d", &a);
	printf("So thu hai = ");
	scanf("%d", &b);
	
	int sum = a*b;
	while(a-b) (a>b) ? a-=b : b-=a;
	
	printf("Uoc so chung lon nhat = %d\n", a);
	printf("Boi so chung nho nhat = %d\n", sum/a);
	return 0;
}

