#include<stdio.h>
#include<math.h>
/*
	Tính S(n) = 1+x+x^3/3!+x^5/5!+...+x^(2n+1)/((2n+1)!).
*/
int main() {
	int n, giaiThua;
	float x, sum = 1;
	printf("Nhap x = ");
	scanf("%f", &x);
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=0; i<=n; i++){
		giaiThua = 1;
		for(int j=1; j<=2*i+1; j++)
			giaiThua*=j;
		sum+=(pow(x, 2*i+1)/giaiThua);
	}
	printf("Ket qua = %f", sum);
	return 0;
}

