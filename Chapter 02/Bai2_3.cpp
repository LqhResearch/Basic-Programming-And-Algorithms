#include<stdio.h>
#include<string.h>
/*
	Viet chuong trinh nhap vao ho ten, diem toan, diem van cua mot hoc sinh.
	Tinh trung binh va xuat ket qua.
*/
int main() {
	char hoTen[50];
	float toan, van, dtb;
	fflush(stdin);
	printf("Nhap ho ten: ");
	gets(hoTen);
	do{
		printf("Nhap diem toan = ");
		scanf("%f", &toan);
		if(toan < 0 || toan > 10)
			printf("Hay nhap diem trong khoang 0 <= x <= 10\nHay nhap lai = \n");
	}while(toan < 0 || toan > 10);
	do{
		printf("Nhap diem van = ");
		scanf("%f", &van);
		if(van < 0 || van > 10)
			printf("Hay nhap diem trong khoang 0 <= x <= 10\nHay nhap lai = ");
	}while(van < 0 || van > 10);
	
	dtb = (toan + van)/2;
	
	printf("\nHo ten: %s\n", hoTen);
	printf("Diem Toan = %.2f\n", toan);
	printf("Diem Van = %.2f\n", van);
	printf("Diem Trung Binh = %.2f\n", dtb);
	return 0;
}

