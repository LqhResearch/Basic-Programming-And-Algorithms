#include<stdio.h>
/*
	Viet chuong trinh nhap vao mot ngay(ngay, thang, nam).
	Tinh xem ngay do la ngay thu may trong nam.
*/
int DayOfMonth(int month, int year)
{
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:	{
			if((year%4==0 && year%100!=0) || year%400==0)
				return 29;
			else
				return 28;
		}
	}
}

int main() {
	int day, month, year;
	printf("Nhap ngay = ");
	scanf("%d", &day);
	do{
		printf("Nhap thang = ");
		scanf("%d", &month);
		if(month<1 || month>12)
			printf("Khong phai thang trong nam\n");
	}while(month<1 || month>12);
	do{
		printf("Nhap nam = ");
		scanf("%d", &year);
		if(year<0)
			printf("Hay nhap nam sau cong nguyen\n");
	}while(year<0);
	
	int doy = 0;	//Day of year
	for(int i=1; i<month; i++)
		doy+=DayOfMonth(i, year);
	doy+=day;
	printf("Ngay %d thang %d nam %d la ngay thu %d trong nam", day, month, year, doy);
	return 0;
}

