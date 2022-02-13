#include<stdio.h>
/*
		Tính S(n) = 1+1/(1+2)+1/(1+2+3)+...+1/(1+2+3+...+n).
*/
int main() {
	int n, mauSo = 0;
	float sum = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	for(int i=1; i<=n; i++) {
		mauSo+=i;
		sum+=1.0/mauSo;
	}
	printf("Ket qua = %f", sum);
	return 0;
}

