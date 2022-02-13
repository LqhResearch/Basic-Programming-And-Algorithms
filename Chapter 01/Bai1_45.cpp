#include<stdio.h>
/*
	Dem so luong "uoc so chan" cua so nguyen duong n
*/
int main() {
	int n, count = 0;
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
			count++;
	}
	printf("\n%d uoc chan", count);	
	return 0;
}

