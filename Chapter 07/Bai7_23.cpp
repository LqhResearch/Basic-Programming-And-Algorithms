#include<stdio.h>
#include<math.h>
/*
	De quy: Liet ke cac so nguyen to nho hon n
*/
int testSNT(int n, int i);
void Listed(int n);

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	printf("\nUoc so cua %d: ", n);
	Listed(n);
	return 0;
}

int testSNT(int n, int i) {
	if(i > sqrt(n))
		return 0;
	int count=testSNT(n, i+1);
	if(n%i==0)
		count++;
	return count;
}

void Listed(int n) {
	if(n==1)
		return;
	else {
		if(testSNT(n, 2) == 0)
			printf("%5d", n);
		return Listed(n-1);
	}
}
