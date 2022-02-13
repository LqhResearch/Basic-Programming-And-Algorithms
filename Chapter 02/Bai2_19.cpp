#include<stdio.h>
#include<math.h>
/*
	Viet chuong trinh tinh x^y (y la so nguyen duong)
*/
int main() {
	float x;
	int y;
	printf("Nhap so = ");
	scanf("%f", &x);
	do{
		printf("Nhap luy thua y: ");
		scanf("%d", &y);
		if(y<0)
			printf("Hay nhap so lon hon 0\n");
	}while(y<0);
	
	printf("%.3f ^ %d = %f", x, y, pow(x, y));
	return 0;
}

