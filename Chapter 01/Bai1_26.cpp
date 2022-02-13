#include<stdio.h>
#include<math.h>
/*
	Tính S(x, n) = -x+x^2/2!-x^3/3!+...+(-1)^n*x^n/n!.
*/
int main() {
	int n, giaiThua = 1;
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
	{
		giaiThua*=i;
		sum+=(pow(-1, i)*pow(x, i)/giaiThua);
	}
	printf("Ket qua = %f", sum);
	return 0;
}

