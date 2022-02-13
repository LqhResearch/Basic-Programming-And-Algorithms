#include<stdio.h>
/*
	Kiem tra so nguyen duong n co "giam dan tu trai sang phai" hay khong?
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
	
	int temp = n, before, after;
	while(temp >= 10)
	{
		after = temp%10;
		before = (temp/10)%10;
		if(before < after) {
			check = false;
			break;
		}
		temp/=10;
	}
	
	if(check == true)
		printf("%d la so giam dan tu trai sang phai", n);
	else
		printf("%d khong phai la so giam dan tu trai sang phai", n);
	return 0;
}

