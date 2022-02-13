#include<stdio.h>
/*
	Dem so luong "uoc so" cua so nguyen duong n
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
	for(int i=1; i<=n; i++)
		if(n%i==0){
			printf("%5d", i);
			count++;
		}
	printf("\n%d uoc so", count);
	return 0;
}

