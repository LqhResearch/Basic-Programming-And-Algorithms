#include<stdio.h>
/*
	T�nh S(n) = 1+ 1�2 + 1�2�3 +...+ 1�2�3ׅ�n.
*/
int main() {
	int n, sum = 0, luyThua = 1;
	
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++)
	{
		luyThua*=i;
		sum+=luyThua;
	}
	printf("Ket qua = %d", sum);
	return 0;
}

