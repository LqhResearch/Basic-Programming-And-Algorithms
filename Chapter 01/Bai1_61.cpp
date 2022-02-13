#include<stdio.h>
/*
	Dem so luong "chu so lon nhat" cua so nguyen duong n
*/
int main() {
	int n, count = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	//Tim gia tri lon nhat
	int temp = n, max = n%10;
	while(temp != 0)
	{
		if(temp%10 > max)
			max = temp%10;
		temp/=10;
	}
	//Dem so lan xuat hien cua gia tri lon nhat
	temp = n;
	while(temp != 0)
	{
		if(temp%10 == max)
			count++;
		temp/=10;
	}
	printf("Chu so lon nhat cua %d la %d xuat hien %d lan", n, max, count);
	return 0;
}

