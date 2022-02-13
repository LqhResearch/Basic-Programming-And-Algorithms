#include<stdio.h>
/*
	Dem va in ra bo ba pytago trong khoang tu 1 den 100
*/
int main() {
	int count = 0;
	for(int i=1; i<=100; i++)
		for(int j=i; j<=100; j++)
			for(int k=j; k<=100; k++)
				if(i*i+j*j == k*k)
				{
					printf("%5d%5d%5d\n", i, j, k);
					count++;
				}
	printf("Tat ca %d bo ba pytago", count);
	return 0;
}

