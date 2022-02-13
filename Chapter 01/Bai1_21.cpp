#include<stdio.h>
#include<math.h>
/*
	Tính S(x, n) = x-x^2+x^3+...+(-1)^(n+1)*x^n.
*/
int main() {
	int n;
	float x, sum = 1;
	printf("Nhap x = ");
	scanf("%f", &x);
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=0; i<=n; i++)
		sum+=(pow(-1, i+1)*pow(x, i));
	printf("Ket qua = %f", sum);
	return 0;
}

