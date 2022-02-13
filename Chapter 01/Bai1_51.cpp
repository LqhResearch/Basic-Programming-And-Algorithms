#include<stdio.h>
/*
	Dem so luong chu so cua so nguyen duong n
*/
int main() {
	int n, chuSo = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	int temp = n;
	while(temp != 0)
	{
		temp/=10;
		chuSo++;
	}
	printf("So %d co %d chu so", n, chuSo);
	return 0;
}

