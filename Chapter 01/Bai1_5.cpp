#include<stdio.h>
/*
	Tính S(n) = 1/2+1/4+1/6+...+1/2n.
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
	
	for(int i=1; i<=n; i++)
		sum+=(1.0/(2*i));
	printf("Ket qua = %f", sum);
	return 0;
}

