#include<stdio.h>
/*
	Tim "chu so nho nhat" cua so nguyen duong n.
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
	int min = temp%10;
	while(temp != 0) {
		if(temp%10 < min)
			min = temp%10;
		temp/=10;
	}
	printf("Chu so nho nhat cua %d la %d", n, min);
	return 0;
}

