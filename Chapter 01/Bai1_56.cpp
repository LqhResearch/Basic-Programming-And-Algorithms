#include<stdio.h>
/*
	Tinh tich "chu so le" cua so nguyen duong n
*/
int main() {
	int n, multi = 1;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	int temp = n;
	while(temp != 0)
	{
		if(temp%10%2 != 0)
			multi*=(temp%10);
		temp/=10;
	}
	printf("Tich cac chu so le cua %d la %d", n, multi);
	return 0;
}

