#include<stdio.h>
/*
	Chuyen doi nhiet do Fahreneit sang Celsius
	Chuyen doi nhiet do Celsius sang Fahreneit
*/
int main() {
	int type;
	float doF, doC;
	do{
		printf("1. Chuyen doi nhiet do Fahreneit sang Celsius.\n");
		printf("2. Chuyen doi nhiet do Celsius sang Fahreneit.\n");
		printf(">> Hay lua chon: ");
		scanf("%d", &type);
	}while(type<1 && type>2);
	
	switch(type) {
		case 1:{
			printf("Nhap do F = ");
			scanf("%f", &doF);
			doC = (doF-32)/1.8;
			printf("%.2f do F = %.2f do C\n", doF, doC);
			break;
		}
		case 2:{
			printf("Nhap do C = ");
			scanf("%f", &doC);
			doF = doC*1.8+32;
			printf("%.2f do C = %.2f do F\n", doC, doF);
			break;
		}
	}
	return 0;
}

