#include<stdio.h>
#include<math.h>
/*
	T�nh S(n) = sqrt(1+sqrt(2+sqrt(3+...sqrt((n-1)+sqrtn)))) c� n dau can.
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
		sum = sqrt(n-i+1+sum);
	
	printf("Ket qua = %f", sum);
	return 0;
}

