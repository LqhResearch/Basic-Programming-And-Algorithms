#include<stdio.h>
#include<stdlib.h>
/*
	Khai bao kieu du lieu NGAY va dinh nghia ham nhap, ham xuat theo dinh dang (ngay/thang/nam).
	-	Kiem tra nam nhuan.
	-	Tinh so thu tu ngay trong nam.
	-	Tinh so thu tu ngay ke tu ngay 1/1/1.
	-	Tim ngay khi biet nam va so thu tu cua ngay trong nam.
	-	Tim ngay khi biet so thu tu ngay ke tu ngày 1/1/1.
	-	Tim ngay ke tiep.
	-	Tim ngay hom qua.
	-	Tim ngay ke do k ngay.
	-	Tim ngay truoc do k ngay.
	-	Khoang cach giua hai ngay.
	-	So sanh hai ngay.
*/

	//Dinh dang kieu du lieu NGAY (dd/mm/yyyy)
typedef struct {
	int day;
	int month;
	int year;
}NGAY;

	//Kiem tra so ngay trong thang
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

	//Xuat ngay thang nam
void OutputDay(NGAY dmy) {
	printf("Ngay: %d / %d / %d", dmy.day, dmy.month, dmy.year);
}

	//Nhap ngay thang nam
void InputDay(NGAY &dmy) {
	printf("\nNhap ngay: ");
	scanf("%d", &dmy.day);
	do{
		printf("Nhap thang: ");
		scanf("%d", &dmy.month);
		if(dmy.month<1 || dmy.month>12)
			printf("Thang nay khong ton tai\n");
	}while(dmy.month<1 || dmy.month>12);
	printf("Nhap nam: ");
	scanf("%d", &dmy.year);
	OutputDay(dmy);
}

	//Kiem tra mot ngay co ton tai hay khong?
void TestInputDay(NGAY &dmy) {
	do{
		InputDay(dmy);
		if(DayOfMonth(dmy.month, dmy.year) < dmy.day)
			printf("\nNgay nay khong ton tai\n");
	}while(DayOfMonth(dmy.month, dmy.year) < dmy.day);
}

	//Dinh dang mot ngay dung theo ngay/thang/nam
void FormatDMY(NGAY dmy, int k) {
	dmy.day+=k;		//Cong ngay them k ngay. Neu giu nguyen ngay thi k=0
		//Dinh dang theo ngay bi vuot so cho phep
	if(dmy.day > DayOfMonth(dmy.month, dmy.year)) {
		while(dmy.day > DayOfMonth(dmy.month, dmy.year)) {
			if(dmy.month == 12) {	//La thang cuoi
				dmy.day-=DayOfMonth(dmy.month, dmy.year);
				dmy.month=1;
				dmy.year++;
			}
			else {
				dmy.day-=DayOfMonth(dmy.month, dmy.year);
				dmy.month++;
			}	
		}
	}
		//Dinh dang theo ngay la so am
	if(dmy.day <= 0) {
		while(dmy.day <= 0) {
			if(dmy.month-1 == 0) {	//La thang 1
				dmy.day+=DayOfMonth(12, dmy.year);
				dmy.month=12;
				dmy.year--;
			}
			else {
				dmy.day+=DayOfMonth(dmy.month-1, dmy.year);
				dmy.month--;
			}	
		}
	}
	OutputDay(dmy);
}

	//Kiem tra nam nhuan
void TestNamNhuan(int year) {
	if((year%4==0 && year%100!=0) || year%400==0)
		printf("%d la nam nhuan", year);
	else
		printf("%d khong phai la nam nhuan", year);
}

	//Tinh so thu tu ngay trong nam
int DayOfYear(NGAY dmy) {
	int doy = dmy.day;	//Day of year
	for(int i=1; i<dmy.month; i++)
		doy+=DayOfMonth(i, dmy.year);
	return doy;
}

	//Tim ngay khi biet nam va so thu tu
NGAY SearchDayOfYear(int year, int number) {
	NGAY dmy;
	dmy.year=year;
	dmy.month=1;
	while(number > DayOfMonth(dmy.month, dmy.year)) {
		number-=DayOfMonth(dmy.month, dmy.year);
		dmy.month++;
	}
	dmy.day=number;
	return dmy;
}

	//Tim ngay khi biet so thu tu ke tu ngay 1/1/1
NGAY SearchDayOfAD(int number) {
	NGAY dmy;
	dmy.year=1;
	if(number>145732)	//Cong them 399 nam de duoc 400 nam
	{
		number-=145732;
		dmy.year+=399;
	}
	while(number>146097) {	//Cong them 400 nam de thoa dieu kien
		number-=146097;
		dmy.year+=400;
	}
	while(number > 365) {
		dmy.year++;
		if((dmy.year%4==0 && dmy.year%100!=0) || dmy.year%400==0)
			number-=366;
		else number-=365;
		
	}
	return SearchDayOfYear(dmy.year, number);
}

	//Tim ngay ke tiep
void NextDay(NGAY dmy) {
	if(dmy.day == DayOfMonth(dmy.month, dmy.year))
	{
		if(dmy.month==12) {
			dmy.day=dmy.month=1;
			dmy.year++;
		}
		else{
			dmy.month++;
			dmy.day=1;
		}
	}
	else{
		dmy.day++;
	}
	printf("\nNgay ke tiep: ");
	OutputDay(dmy);
}

	//Tim ngay truoc do
void BeforeDay(NGAY dmy) {
	if(dmy.day==1)
	{
		if(dmy.month==1) {
			dmy.day=31;
			dmy.month=12;
			dmy.year--;
		}
		else {
			dmy.month--;
			dmy.day=DayOfMonth(dmy.month, dmy.year);
		}
	}
	else {
		dmy.day--;
	}
	printf("\nNgay truoc do: ");
	OutputDay(dmy);
}

	//So sanh hai ngay
void CompareDate(NGAY dmy1, NGAY dmy2) {
	int date1 = dmy1.year*10000+dmy1.month*100+dmy1.day;
	int date2 = dmy2.year*10000+dmy2.month*100+dmy2.day;
	if(date1 < date2)
		printf("\n%d / %d / %d truoc %d / %d / %d", dmy1.day, dmy1.month, dmy1.year, dmy2.day, dmy2.month, dmy2.year);
	else if(date1 == date2)
		printf("\nCung mot ngay");
	else printf("\n%d / %d / %d sau %d / %d / %d", dmy1.day, dmy1.month, dmy1.year, dmy2.day, dmy2.month, dmy2.year);
}

	//Tinh so thu tu tu ngay 1/1/1
int DayOfAD(NGAY dmy) {
	if(dmy.month < 3) {
		dmy.year--;
		dmy.month+=12;
	}
	return 365*dmy.year+dmy.year/4-dmy.year/100+dmy.year/400+(153*dmy.month - 457)/5+dmy.day-306;
}

	//Tinh khoang cach 2 ngay
void DistanceDays(NGAY dmy1, NGAY dmy2) {
	int date1 = DayOfAD(dmy1);
	int date2 = DayOfAD(dmy2);
	if(date1 > date2)
		printf("\nKhoang cach hai ngay la %d ngay", date1-date2);
	else
		printf("\nKhoang cach hai ngay la %d ngay", date2-date1);
}

	//Quan li chuong trinh ve thoi gian
void TimeManage() {
	int type, year, number, k;
	NGAY dmy1, dmy2;
	do{
		printf("\n\t====Phep Toan Thoi Gian=====\n");
		printf("\n1. Kiem tra nam nhuan");
		printf("\n2. Tinh so thu tu ngay trong nam");
		printf("\n3. Tinh so thu tu ke tu ngay 1/1/1");
		printf("\n4. Tim ngay khi biet nam va so thu tu");
		printf("\n5. Tim ngay khi biet so thu tu ke tu ngay 1/1/1");
		printf("\n6. Tim ngay ke tiep");
		printf("\n7. Tim ngay hom qua");
		printf("\n8. Tim ngay ke do k ngay");
		printf("\n9. Tim ngay truoc do k ngay");
		printf("\n10. Khoang cach giua hai ngay");
		printf("\n11. So sanh hai ngay");
		
		printf("\n\n0. Thoat");
		printf("\n   >> Hay lua chon: ");
		scanf("%d", &type);
		if(type<0 || type>11)
			printf("Chuc nang nay khong ton tai\n");
	}while(type<0 || type>11);
	
	switch(type) {
		case 1:{
			printf("\n=====Kiem tra nam nhuan=====\n");
			printf("Nhap nam: ");
			scanf("%d", &year);
			TestNamNhuan(year);
			break;
		}
		case 2:{
			printf("\n=====Tinh so thu tu ngay trong nam=====\n");
			TestInputDay(dmy1);
			printf(" la ngay thu %d", DayOfYear(dmy1));
			break;
		}
		case 3:{
			printf("\n=====Tinh so thu tu ke tu ngay 1/1/1=====\n");
			TestInputDay(dmy1);
			printf(" la ngay thu %d", DayOfAD(dmy1));
			break;
		}
		case 4:{
			printf("\n=====Tim ngay khi biet nam va so thu tu=====\n");
			printf("Nhap nam: ");
			scanf("%d", &year);
			printf("Nhap so thu tu cua nam: ");
			scanf("%d", &number);
			OutputDay(SearchDayOfYear(year, number));
			break;
		}
		case 5:{
			printf("\n=====Tim ngay khi biet so thu tu ke tu ngay 1/1/1=====\n");
			printf("Nhap so thu tu cua nam: ");
			scanf("%d", &number);
			OutputDay(SearchDayOfAD(number));
			break;
		}
		case 6:{
			printf("\n=====Tim ngay ke tiep=====\n");
			InputDay(dmy1);
			FormatDMY(dmy1, 1);
			break;
		}
		case 7:{
			printf("\n=====Tim ngay truoc do=====\n");
			InputDay(dmy1);
			FormatDMY(dmy1, -1);
			break;
		}		
		case 8:{
			printf("\n=====Tim ngay ke tiep k ngay=====\n");
			InputDay(dmy1);
			printf("\nSo ngay ke tiep: ");
			scanf("%d", &k);
			FormatDMY(dmy1, k);
			break;
		}
		case 9:{
			printf("\n=====Tim ngay truoc do k ngay=====\n");
			InputDay(dmy1);
			printf("\nSo ngay truoc do: ");
			scanf("%d", &k);
			FormatDMY(dmy1, -k);
			break;
		}
		case 10:{
			printf("\n=====Khoang cach giua hai ngay=====\n");
			TestInputDay(dmy1);
			TestInputDay(dmy2);
			DistanceDays(dmy1, dmy2);
			break;
		}
		case 11:{
			printf("\n=====So sanh hai ngay=====\n");
			TestInputDay(dmy1);
			TestInputDay(dmy2);
			CompareDate(dmy1, dmy2);
			break;
		}
		case 0: exit(1);
	}
}

	//Chuong trinh chinh
int main() {
	do{
		TimeManage();
	}while(true);
	return 0;
}
