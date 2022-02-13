#include<stdio.h>
/*
	Tính S(n) = 1 + 2 + 3 + ... + n.
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
		sum+=i;
	printf("Ket qua = %d", sum);
	return 0;
}

