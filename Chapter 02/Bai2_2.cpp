#include<stdio.h>
/*
	Nhap vao mot thang trong nam. Cho biet thang do thuoc quy nào.
*/
int main() {
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 1 || n > 12)
			printf("%d khong phai thang trong nam\nHay nhap lai: ", n);
	}while(n < 1 || n > 12);
	
	switch(n)
	{
		case 1:
		case 2:
		case 3:
			printf("Thang %d thuoc qui I", n);
			break;
		case 4:
		case 5:
		case 6:
			printf("Thang %d thuoc qui II", n);
			break;
		case 7:
		case 8:
		case 9:
			printf("Thang %d thuoc qui III", n);
			break;
		case 10:
		case 11:
		case 12:
			printf("Thang %d thuoc qui IV", n);
			break;
	}
	return 0;
}

