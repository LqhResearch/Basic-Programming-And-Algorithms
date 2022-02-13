#include<stdio.h>
/*
	Nhap vao so nguyen duong n.
	Kiem tra so nguyen duong n co phai la "so hoan hao" hay khong?
*/
int main() {
	int n, sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<n; i++)
		if(n%i==0) sum+=i;
	if(sum == n)
		printf("%d la so hoan hao", n);
	else
		printf("%d khong phai la so hoan hao", n);
	return 0;
}

