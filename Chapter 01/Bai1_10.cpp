#include<stdio.h>
/*
	Tính T(n) = 1 × 2 × 3 × … × n.
*/
int main() {
	int n, multi = 1;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++)
		multi*=i;
	printf("Ket qua = %d", multi);
	return 0;
}

