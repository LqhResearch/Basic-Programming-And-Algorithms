#include<stdio.h>
/*
	Tim "uoc so le lon nhat" cua so nguyen duong n
*/
int main() {
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	printf("Uoc so le lon nhat : ");
	for(int i=n; i>=1; i--)
		if(n%i==0 && i%2!=0) {
			printf("%5d", i);
			break;
		}
	return 0;
}

