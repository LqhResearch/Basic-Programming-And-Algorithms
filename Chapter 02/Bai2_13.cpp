#include<stdio.h>
/*
	Viet chuong trinh nhap mot thang va nam. Hay cho biet thang do co bao nhieu ngay?
*/
int main() {
	int thang, nam;
	do{
		printf("Nhap thang = ");
		scanf("%d", &thang);
		if(thang<1 || thang>12)
			printf("Khong phai thang trong nam\n");
	}while(thang<1 || thang>12);
	do{
		printf("Nhap nam = ");
		scanf("%d", &nam);
		if(nam<0)
			printf("Hay nhap nam sau cong nguyen\n");
	}while(nam<0);
	
	switch(thang)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("Thang %d nam %d co 31 ngay", thang, nam);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("Thang %d nam %d co 30 ngay", thang, nam);
			break;
		case 2:{
			if((nam%4==0 && nam%100!=0) || nam%400==0)
				printf("Thang %d nam %d co 29 ngay", thang, nam);
			else
				printf("Thang %d nam %d co 28 ngay", thang, nam);
			break;
		}
	}
	return 0;
}

