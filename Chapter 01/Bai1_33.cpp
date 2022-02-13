#include<stdio.h>
#include<math.h>
/*
	Tính S(n) = sqrt(x^n+sqrt(x^(n-1)+sqrt(x^(n-2)+...sqrt(x^2+sqrtx)))) có n dau can.
*/
int main() {
	int n;
	float x, sum = 0;
	printf("Nhap x = ");
	scanf("%f", &x);
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++) 
		sum = sqrt(pow(x, i)+sum);
	printf("Ket qua = %f", sum);
	return 0;
}

