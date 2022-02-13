#include<stdio.h>
#include<math.h>
/*
	De quy: S(n) = sqrt(2+ sqrt(2+ sqrt(2+ ...sqrt(2+ sqrt2)))) có n dau can.
*/
float sum(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTong S(n) = sqrt(2+ sqrt(2+ sqrt(2+ ...sqrt(2+ sqrt2)))) = %f", sum(n));
	return 0;
}

float sum(int n) {
	if(n==1)
		return sqrt(2);
	else
		return sqrt(2 + sum(n-1));
}
