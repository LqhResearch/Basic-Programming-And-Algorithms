#include<stdio.h>
/*
	Liet ke tat ca "so hoan hao" nho hon n
*/
int main() {
	int n, sum;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	printf("So hoan hao nho hon %d : ", n);
	for(int i=1; i<n; i++)
	{
		sum = 0;
		for(int j=1; j<i; j++)
			if(i%j == 0) sum+=j;
		if(sum == i)
			printf("%5d", i);
	}
	return 0;
}

