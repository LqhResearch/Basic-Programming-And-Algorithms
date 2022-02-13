#include<stdio.h>
/*
	Tính S(n) = 1/(1 × 2)+1/(2 × 3)+...+1/(n ×(n+1)).
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
		sum+=1.0/(i*(i+1));
	printf("Ket qua = %f", sum);
	return 0;
}

