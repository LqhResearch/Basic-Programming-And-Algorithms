#include<stdio.h>
/*
	Tinh tich tat ca "uoc so" cua so nguyen duong n
*/
int main() {
	int n, multi = 1;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	printf("Uoc so cua %d : ", n);
	for(int i=1; i<=n; i++)
		if(n%i==0){
			printf("%5d", i);
			multi*=i;
		}
	printf("\nKet qua = %d", multi);
	return 0;
}

