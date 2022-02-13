#include<stdio.h>
#include<math.h>
/*
	Tính S(n) = x^2+x^4+x^6+...+x^2n.
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
		sum+=pow(x, 2*i);
	printf("Ket qua = %f", sum);
	return 0;
}

