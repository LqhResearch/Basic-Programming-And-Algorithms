#include<stdio.h>
#include<math.h>
/*
	Liet ke tat ca "so chinh phuong" nho hon n
*/
int main() {
	int n;
	bool check;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	printf("So hoan hao nho hon %d : ", n);
	for(int i=1; i<n; i++)
		if(pow((int)sqrt(i), 2) == i)
			printf("%5d", i);
	return 0;
}

