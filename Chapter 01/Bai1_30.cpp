#include<stdio.h>
#include<math.h>
/*
	Tính S(n) = sqrt(n+sqrt((n-1)+sqrt((n-2)+...sqrt(2+sqrt1))))  có n dau can.
*/
int main() {
	int n;
	float sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++)
		sum = sqrt(i+sum);
	
	printf("Ket qua = %f", sum);
	return 0;
}

