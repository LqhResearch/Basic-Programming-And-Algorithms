#include<stdio.h>
#include<math.h>
/*
	Nhap vao so nguyen duong n.
	Kiem tra so nguyen duong n co phai la "so chinh phuong" hay khong?
*/
int main() {
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong\n");
	}while(n < 0);

	if(pow((int)sqrt(n), 2) == n)
		printf("%d la so chinh phuong", n);
	else
		printf("%d khong phai la so chinh phuong", n);
	return 0;
}

