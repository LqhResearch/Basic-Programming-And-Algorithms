#include<stdio.h>
/*
	Liet ke tat ca "uoc so" cua so nguyen duong n
*/
int main() {
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	printf("Uoc so cua %d : ", n);
	for(int i=1; i<=n; i++)
		if(n%i==0)
			printf("%5d", i);
	return 0;
}

