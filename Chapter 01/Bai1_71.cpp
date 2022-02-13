#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
	Giai phuong trình và bien luan:
	-	Phuong trình bac nhat dang ax + b = 0.
	-	Phuong trình bac hai dang ax2 + bx + c = 0.
	-	Phuong trình trùng phuong dang ax4 + bx2 + c = 0.
*/
void menu();
void PTB1(int a, int b);
void PTB2(int a, int b, int c);
void PTTP(int a, int b, int c);

int main() {
	do{
		menu();
	}while(true);
	return 0;
}

void menu()
{
	int type, a, b, c;
	printf("\n\t===MENU===\n");
	printf("1. Phuong trinh bac nhat ax + b = 0.\n");
	printf("2. Phuong trinh bac hai ax2 + bx + c = 0.\n");
	printf("3. Phuong trinh trung phuong ax4 + bx2 + c = 0.\n");
	printf("4. Thoat.\n");
	printf(">> Hay lua chon: ");
	do{
		scanf("%d", &type);
		if(type < 1 || type > 4)
			printf("Khong co su lua chon nay.\n>> Hay lua chon lai: ");
	}while(type < 1 || type > 4);
	
	switch(type)
	{
		case 1:{
			printf("Nhap a, b = ");
			scanf("%d%d", &a, &b);
			PTB1(a, b);
			break;
		}
		case 2:{
			printf("Nhap a, b, c = ");
			scanf("%d%d%d", &a, &b, &c);
			PTB2(a, b, c);
			break;
		}
		case 3:{
			printf("Nhap a, b, c = ");
			scanf("%d%d%d", &a, &b, &c);
			PTTP(a, b, c);
			break;
		}
		case 4: exit(1);
	}
}

void PTB1(int a, int b) {
	if(a==0 && b==0)
		printf("Phuong trinh vo so nghiem.\n");
	else if(a==0 && b!=0)
		printf("Phuong trinh vo nghiem.\n");
	else
		printf("Nghiem = %f", -1.0*b/a);
}

void PTB2(int a, int b, int c) {
	if(a==0) {
		if(b==0 && c==0)
			printf("Phuong trinh vo so nghiem.\n");
		else if(b==0 && c!=0)
			printf("Phuong trinh vo nghiem.\n");
		else PTB1(b, c);
	}
	else {
		int D = b*b-4*a*c;
		if(D > 0) {
			float x1 = (-b+sqrt(D))/(2*a);
			float x2 = (-b-sqrt(D))/(2*a);
			printf("Nghiem = %f\nNghiem = %f\n", x1, x2);
		}
		else if(D == 0)
			printf("Nghiem = %f\n", -1.0*b/(2*a));
		else printf("Phuong trinh vo nghiem.\n");
	}
}

void PTTP(int a, int b, int c) {
	if(a==0) {
		if(b==0 && c==0)
			printf("Phuong trinh vo so nghiem.\n");
		else if(b==0 && c!=0)
			printf("Phuong trinh vo nghiem.\n");
		else PTB1(b, c);
	}
	else {
		int D = b*b-4*a*c;
		if(D > 0) {
			float x1 = (-b+sqrt(D))/(2*a);
			float x2 = (-b-sqrt(D))/(2*a);
			printf("Nghiem = %f\nNghiem = %f\n", sqrt(x1), -sqrt(x1));
			printf("Nghiem = %f\nNghiem = %f\n", sqrt(x2), -sqrt(x2));
		}
		else if(D == 0) {
			float x = -b/(2*a);
			printf("Nghiem = %f\nNghiem = %f\n", sqrt(x), -sqrt(x));
		}
		else printf("Phuong trinh vo nghiem.\n");
	}
}
