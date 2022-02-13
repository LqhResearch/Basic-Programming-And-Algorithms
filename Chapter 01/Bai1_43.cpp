#include<stdio.h>
/*
	Tinh tong tat ca "uoc so chan" cua so nguyen duong n
*/
int main() {
	int n, sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	printf("Uoc so cua %d : ", n);
	for(int i=1; i<=n; i++) {
		if(n%i==0)
			printf("%5d", i);
		if(n%i==0 && i%2==0)
			sum+=i;
	}
	printf("\nKet qua = %d", sum);	
	return 0;
}

