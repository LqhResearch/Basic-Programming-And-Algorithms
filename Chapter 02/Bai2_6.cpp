#include<stdio.h>
/*
	Viet chuong trinh tim so nguyen duong m sao cho 1 + 2 + 3 + … + m < N.
*/
int main() {
	int m = 0, n, sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong.\n");
	}while(n < 0);
	
	while(sum+m < n) {
		sum+=m;
		m++;
	}
	printf("1 + 2 + 3 + ... + %d = %d", m, sum);
	return 0;
}

