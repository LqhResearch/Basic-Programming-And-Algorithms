#include<stdio.h>
#include<math.h>
/*
	Tính S(x, n) = -1+x^2/2!-x^4/4!+...+(-1)^(n+1)*x^2n/((2n)!).
*/
int main() {
	int n, giaiThua;
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
	{
		giaiThua = 1;
		for(int j=1; j<=2*i; j++)
			giaiThua*=j;
		sum+=(pow(-1, i+1)*pow(x, 2*i)/giaiThua);
	}
	printf("Ket qua = %f", -sum);
	return 0;
}

