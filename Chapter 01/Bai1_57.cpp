#include<stdio.h>
/*
	Nhap vao so nguyen duong n. Tim chu so dau tien.
*/
int main() {
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	int temp = n;
	while(temp >= 10)
	{
		temp/=10;
	}
	printf("So %d co chu so dau tien la %d", n, temp);
	return 0;
}

