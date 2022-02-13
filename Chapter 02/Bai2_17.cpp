#include<stdio.h>
/*
	Viet chuong trinh nhap vao so nguyen co 2 chu so.
	Hay in ra cach doc cua so nguyen vua nhap.
*/
int main() {
	char docSo[10][5]={"chuc", "mot", "hai", "ba", "bon", 
					"nam", "sau", "bay", "tam", "chin"};
	int n, first, last;
	do{
		printf("Nhap so nguyen co 2 chu so: ");
		scanf("%d", &n);
		if(n<10 || n>99)
			printf("Khong phai so nguyen 2 chu so");
	}while(n<10 || n>99);
	first=n/10;
	last=n%10;
	
	if(first==1)
	{
		if(last==0)
			printf("%d doc la: muoi", n);
		else if(last==5)
			printf("%d doc la: muoi lam", n);
		else
			printf("%d doc la: muoi %s", n, docSo[last]);
	}
	else
	{
		if(last==0)
			printf("%d doc la: %s muoi", n, docSo[first]);
		else if(last==5)
			printf("%d doc la: %s muoi lam", n, docSo[first]);
		else
			printf("%d doc la: %s muoi %s", n, docSo[first], docSo[last]);
	}
	return 0;
}

