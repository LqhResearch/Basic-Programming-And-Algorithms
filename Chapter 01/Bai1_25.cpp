#include<stdio.h>
#include<math.h>
/*
	Tính S(x, n) = -x+x^2/(1+2)-x^3/(1+2+3)+...+(-1)^n*x^n/(1+2+3+...+n).
*/
int main() {
	int n, mauSo = 0;
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
		mauSo+=i;
		sum+=(pow(-1, i)*pow(x, i)/mauSo);
	}
	printf("Ket qua = %f", sum);
	return 0;
}

