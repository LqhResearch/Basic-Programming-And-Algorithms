#include<stdio.h>
/*
	Dem so luong "chu so dau tien" cua so nguyen duong n
*/
int main() {
	int n, count = 0;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	//Tim gia tri dau tien
	int first = n;
	while(first >= 10)
	{
		first/=10;
	}
	//Dem so lan xuat hien cua gia tri dau tien
	int temp = n;
	while(temp != 0)
	{
		if(temp%10 ==first)
			count++;
		temp/=10;
	}
	printf("Chu so lon nhat cua %d la %d xuat hien %d lan", n, first, count);
	return 0;
}

