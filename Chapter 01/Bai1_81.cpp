#include<stdio.h>
#include<stdlib.h>
/*
	Tìm x:
		x + a = b
		x - a = b
		x * a = b
		x / a = b
		a + x = b
		a - x = b
		a * x = b
		a / x = b
*/
void menu();

int main() {
	do{
		menu();
	}while(true);
	return 0;
}

void menu() {
	int type, a, b;
	printf("Nhap a = ");
	scanf("%d", &a);
	printf("Nhap b = ");
	scanf("%d", &b);
	printf("\n\t===MENU===\n");
	printf("1. x + a = b\n");
	printf("2. x - a = b\n");
	printf("3. x * a = b\n");
	printf("4. x / a = b\n");
	printf("5. a + x = b\n");
	printf("6. a - x = b\n");
	printf("7. a * x = b\n");
	printf("8. a / x = b\n");
	printf("9. Thoat.\n");
	printf(">> Hay lua chon: ");
	do{
		scanf("%d", & type);
		if(type < 1 || type > 9)
			printf("Vui long nhap vao 1 <= x <= 9\n>> Hay nhap lai: ");
	}while(type < 1 || type > 9);
	
	switch(type) {
		case 1:{
			printf("x  +  %d  =  %d\n", a, b);
			printf("x        =  %d  -  %d\n", b, a);
			printf("x        =  %d\n", b-a);
			printf("-----------------------------\n");
			break;
		}
		case 2:{
			printf("x  -  %d  =  %d\n", a, b);
			printf("x        =  %d  +  %d\n", b, a);
			printf("x        =  %d\n", b+a);
			printf("-----------------------------\n");
			break;
		}
		case 3:{
			printf("x  *  %d  =  %d\n", a, b);
			printf("x        =  %d  /  %d\n", b, a);
			printf("x        =  %.2f\n", 1.0*b/a);
			printf("-----------------------------\n");
			break;
		}
		case 4:{
			printf("x  /  %d  =  %d\n", a, b);
			printf("x        =  %d  *  %d\n", b, a);
			printf("x        =  %d\n", b*a);
			printf("-----------------------------\n");
			break;
		}
		case 5:{
			printf("%d  +  x  =  %d\n", a, b);
			printf("      x  =  %d  -  %d\n", b, a);
			printf("      x  =  %d\n", b-a);
			printf("-----------------------------\n");
			break;
		}
		case 6:{
			printf("%d  -  x  =  %d\n", a, b);
			printf("      x  =  %d  -  %d\n", a, b);
			printf("      x  =  %d\n", a-b);
			printf("-----------------------------\n");
			break;
		}
		case 7:{
			printf("%d  *  x  =  %d\n", a, b);
			printf("      x  =  %d  /  %d\n", b, a);
			printf("      x  =  %f.2\n", 1.0*b/a);
			printf("-----------------------------\n");
			break;
		}
		case 8:{
			printf("%d  /  x  =  %d\n", a, b);
			printf("      x  =  %d  /  %d\n", a, b);
			printf("      x  =  %.2f\n", 1.0*a/b);
			printf("-----------------------------\n");
			break;
		}
		case 9: exit(1);
	}
}
