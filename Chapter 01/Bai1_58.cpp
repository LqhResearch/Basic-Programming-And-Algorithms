#include<stdio.h>
/*
	Tim "chu so dao nguoc" cua so nguyen duong n.
*/
int main() {
	int n, soDao = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	int temp = n;
	while(temp != 0)
	{
		soDao= soDao*10 + temp%10;
		temp/=10;
	}
	printf("So dao cua %d la %d", n, soDao);
	return 0;
}

