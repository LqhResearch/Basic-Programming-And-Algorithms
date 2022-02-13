#include<stdio.h>
/*
	Nhap vao so nguyen duong n.
	Tim tìm giá tri nguyên duong k lon nhat sao cho S(k) < n. 
	S(k) duoc dinh nghia : S(k) = 1 + 2 + 3 + … + k.
*/
int main() {
	int n, k, sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; sum+i < n; i++) {
		k = i;
		sum+=k;
	}
	printf("k = %d\t S(k) = %d", k, sum);
	return 0;
}

