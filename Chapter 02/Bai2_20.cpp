#include<stdio.h>
/*
	In ra bang cuu chuong (tu 2 den 9) ra man hinh.
*/
int main() {
	for(int i=2; i<=9; i++)
	{
		printf("\nBang cuu chuong %d: \n", i);
		for(int j=1; j<=10; j++)
			printf("%d x %d = %d\n", i, j, i*j);
	}
	return 0;
}

