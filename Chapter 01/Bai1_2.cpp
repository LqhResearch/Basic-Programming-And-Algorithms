#include<stdio.h>
#include<math.h>
/*
	Tính S(n) = 1^2 +2^2 +3^2 + ... + n^2.
*/
int main() {
	int n, sum=0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++)
		sum+=pow(i, 2);
	printf("Ket qua = %d", sum);
	return 0;
}

