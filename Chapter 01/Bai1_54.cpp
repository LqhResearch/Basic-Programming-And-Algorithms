#include<stdio.h>
/*
	Dem so luong "chu so le" cua so nguyen duong n
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
		if(temp%10%2 != 0) 
			chuSo++;
		temp/=10;
	}
	printf("So %d co %d chu so le", n, chuSo);
	return 0;
}

