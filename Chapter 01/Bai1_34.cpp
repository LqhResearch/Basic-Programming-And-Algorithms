#include<stdio.h>
/*
	Tính S(n) = 1/(1+(1/(1+(1/(1+(1/(1+(1/(1+1))))))))) có n dau phân so.
*/
int main() {
	int n;
	float sum = 1;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++) 
		sum=1.0/(1+sum);
	printf("Ket qua = %f", sum);	
	return 0;
}

