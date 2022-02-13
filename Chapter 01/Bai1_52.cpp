#include<stdio.h>
/*
	Tinh tong chu so cua so nguyen duong n
*/
int main() {
	int n, sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	int temp = n;
	while(temp != 0)
	{
		sum+=(temp%10);
		temp/=10;
	}
	printf("Tong cac chu so cua %d la %d", n, sum);
	return 0;
}

