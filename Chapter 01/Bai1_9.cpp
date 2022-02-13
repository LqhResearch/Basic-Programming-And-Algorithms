#include<stdio.h>
/*
	Tính S(n) = 1/2+3/4+5/6+...+(2n+1)/(2n+2).
*/
int main() {
	int n;
	float sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=0; i<=n; i++)
		sum+=(2.0*i+1)/(2*i+2);
	printf("Ket qua = %f", sum);
	return 0;
}

