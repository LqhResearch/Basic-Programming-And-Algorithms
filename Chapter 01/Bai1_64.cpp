#include<stdio.h>
/*
	Kiem tra so nguyen duong n co "toan chu so le" hay khong?
*/
int main() {
	int n;
	bool check = true;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	
	int temp = n;
	while(temp != 0)
	{
		if(temp%10%2 == 0)
		{
			check = false;
			break;
		}
		temp/=10;
	}
	
	if(check == true)
		printf("%d la so toan chu so le", n);
	else
		printf("%d khong phai la so toan chu so le", n);
	return 0;
}

