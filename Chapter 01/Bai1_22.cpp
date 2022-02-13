#include<stdio.h>
#include<math.h>
/*
	Tính S(x, n) = x-x^3+x^5+...+(-1)^n*x^(2n+1).
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
	
	for(int i=0; i<=n; i++)
		sum+=(pow(-1, i)*pow(x, 2*i+1));
	printf("Ket qua = %f", sum);
	return 0;
}

