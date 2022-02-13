#include<stdio.h>
/*
	Liet ke tat cac "uoc so" cua so nguyen duong n 
*/
void Listed(int n, int i);

int main() {
	int n, i=1;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	printf("\nTat ca uoc so cua %d: ", n);
	Listed(n, i);
	return 0;
}

void Listed(int n, int i) {
	if(i==n)
		return;
	else {
		if(n%i==0)	printf("%5d", i);
		return Listed(n, i+1);
	}
}
