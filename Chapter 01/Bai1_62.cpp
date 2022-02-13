#include<stdio.h>
/*
	Dem so luong "chu so nho nhat" cua so nguyen duong n
*/
int main() {
	int n, count = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	//Tim gia tri nho nhat
	int temp = n, min = n%10;
	while(temp != 0)
	{
		if(temp%10 < min)
			min = temp%10;
		temp/=10;
	}
	//Dem so lan xuat hien cua gia tri nho nhat
	temp = n;
	while(temp != 0)
	{
		if(temp%10 == min)
			count++;
		temp/=10;
	}
	printf("Chu so nho nhat cua %d la %d xuat hien %d lan", n, min, count);
	return 0;
}

