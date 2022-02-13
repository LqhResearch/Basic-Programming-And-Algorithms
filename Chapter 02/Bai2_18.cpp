#include<stdio.h>
#include<math.h>
/*
	Viet chuong trinh tinh S = can bac n cua x (n la so nguyen duong).
*/
int main() {
	int n;
	float S, x;
	printf("Nhap so = ");
	scanf("%f", &x);
	do{
		printf("Nhap can bac n: ");
		scanf("%d", &n);
		if(n<0)
			printf("Hay nhap so lon hon 0\n");
	}while(n<0);
	S = pow(x, 1.0/n);
	printf("Can bac %d cua %.3f = %f", n, x, S);
	return 0;
}

