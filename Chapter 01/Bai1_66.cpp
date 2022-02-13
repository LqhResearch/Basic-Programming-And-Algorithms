#include<stdio.h>
/*
	Kiem tra so nguyen duong n co "so doi xung" hay khong?
*/
int main() {
	int n, soDao = 0;
	bool check = true;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);
	//Dao nguoc so
	int temp = n;
	while(temp != 0)
	{
		soDao = soDao*10 + temp%10;
		temp/=10;
	}
	//So sanh
	temp = n;
	while((temp != 0) && (soDao != 0))
	{
		if(temp%10 != soDao%10)
		{
			check = false;
			break;
		}
		temp/=10;
		soDao/=10;
	}
	
	if(check == true)
		printf("%d la so doi xung", n);
	else
		printf("%d khong phai la so doi xung", n);
	return 0;
}

