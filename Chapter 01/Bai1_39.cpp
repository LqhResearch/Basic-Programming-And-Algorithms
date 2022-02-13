#include<stdio.h>
#include<math.h>
/*
	Liet ke tat ca "so nguyen to" nho hon n
*/
bool TestSNT(int n) {
	for(int i=2; i<=sqrt(n); i++)
		if(n%i==0)
			return false;
	return true;	
}

int main() {
	int n, count;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	printf("So nguyen to nho hon %d : ", n);
	for(int i=2; i<n; i++)
		if(TestSNT(i))
			printf("%5d", i);
	return 0;
}

