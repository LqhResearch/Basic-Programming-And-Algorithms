#include<stdio.h>
#include<math.h>
/*
	Kiem tra so nguyen 4 byte co dang 2^k hay khong?
*/
int main() {
	int n, k = 0, multi = 1;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong.\n");
	}while(n < 0);
	
	while(multi < n) {
		k++;
		multi*=2;
	}
	
	if(multi == n)
		printf("So nguyen %d co dang 2^%d.\n", n, k);
	else
		printf("So nguyen %d khong co dang 2^k.\n", n);
	return 0;
}

