#include<stdio.h>
#include<stdlib.h>
/*
	Viet chuong trinh ve cac hình hoc bang " * " sau day:
	1. Tam giac can dac.
	2. Tam giac can rong.
	3. Tam giac vuong dac.
	4. Tam giac vuong rong.
	5. Hinh vuong dac.
	6. Hinh vuong rong.
	7. Hinh chu nhat dac.
	8. Hinh chu nhat rong.
	9. Hinh thoi dac.
	10. Hinh thoi rong.
	11. Hinh thang dac.
	12. Hinh thang rong.
	13. Hinh thang nguoc dac.
	14. Hinh thang nguoc rong.
	15. Hinh dau cong.
*/

	//Nhap do cao
int inputDoCao(int h)
{
	do{
		printf("Nhap do cao: ");
		scanf("%d", &h);
		if(h <= 0)
			printf("Do cao phai la so > 0\n");
	}while(h <= 0);
	return h;
}
	
	//Nhap chieu dai va chieu rong cua hinh chu nhat
void inputHcn(int &d, int &r)
{
	do{
		printf("Nhap chieu dai: ");
		scanf("%d", &d);
		if(d <= 0)
			printf("Chieu dai phai la so > 0\n");
	}while(d <= 0);
	
	do{
		printf("Nhap chieu rong: ");
		scanf("%d", &r);
		if(r <= 0)
			printf("Chieu rong phai la so > 0\n");
	}while(r <= 0);
}

	//Ve hinh tam giac can dac
void TGCanDac(int h) {
	int mday = h*2-1, head=h, tail=h;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=mday; j++)
			if(j>=head && j<=tail) printf(" * ");
			else printf("   ");
		head--;		tail++;	
		printf("\n");
	}
/*	This code has the same function:
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=mday; j++)
		{
			if((j >= h-i+1) && (j <= h+i-1))
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}*/	
}

	//Ve hinh tam giac rong
void TGCanRong(int h) {
	int mday = h*2-1, head=h, tail=h;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=mday; j++)
			if(j==head || j==tail || i==h) printf(" * ");
			else printf("   ");
		head--;		tail++;
		printf("\n");
	}	
/*	This code has the same function:
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=mday; j++)
		{
			if((j == h-i+1) || (j == h+i-1))
				printf(" * ");
			else if(i == h)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}*/
}

void TGVuongDac1(int h) {
	printf("\nHinh 1: \n");
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j <= i)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
/*	This code has the same fuction:
	int tail=1;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j <= tail)	printf(" * ");
			else	printf("   ");
		tail++;
		printf("\n");
	}*/
}

void TGVuongDac2(int h) {
	printf("\nHinh 2: \n");
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j >= i)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
}

void TGVuongDac3(int h) {
	printf("\nHinh 3: \n");
	int head=h;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j >= head)	printf(" * ");
			else	printf("   ");
		head--;
		printf("\n");
	}
/*	This code has the same fuction:	
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j >= h-i+1)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}*/
}

void TGVuongDac4(int h) {
	printf("\nHinh 4: \n");
	int tail=h;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j <= tail)	printf(" * ");
			else	printf("   ");
		tail--;
		printf("\n");
	}
/*	This code has the same fuction:		
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j <= h-i+1)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}*/
}

	//Ve 4 tam giac vuong dac
void TGVuongDac(int h) {
	TGVuongDac1(h);
	TGVuongDac2(h);
	TGVuongDac3(h);
	TGVuongDac4(h);
}

void TGVuongRong1(int h) {
	printf("\nHinh 1: \n");
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j==1 || i==h || i==j)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
}

void TGVuongRong2(int h) {
	printf("\nHinh 2: \n");
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(i==1 || j==h || i==j)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
}

void TGVuongRong3(int h) {
	printf("\nHinh 3: \n");
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(j==h || i==h || j==h-i+1)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
}

void TGVuongRong4(int h) {
	printf("\nHinh 4: \n");
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(i==1 || j==1 || j==h-i+1)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
}

	//Ve 4 tam giac vuong dac
void TGVuongRong(int h) {
	TGVuongRong1(h);
	TGVuongRong2(h);
	TGVuongRong3(h);
	TGVuongRong4(h);
}

	//Ve hinh vuong dac
void HVDac(int h) {
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			printf(" * ");
		printf("\n");
	}
}

	//Ve hinh vuong rong
void HVRong(int h) {
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=h; j++)
			if(i==1 || j==1 || i==h || j==h)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
}

	//Ve hinh chu nhat dac
void HCNDac(int d, int r) {
	for(int i=1; i<=d; i++)
	{
		for(int j=1; j<=r; j++)
			printf(" * ");
		printf("\n");
	}
}

	//Ve hinh chu nhat rong
void HCNRong(int d, int r) {
	for(int i=1; i<=d; i++)
	{
		for(int j=1; j<=r; j++)
			if(i==1 || j==1 || i==d || j==r)
				printf(" * ");
			else
				printf("   ");
		printf("\n");
	}
}

	//Ve hinh thoi voi do cao tu day den ben ngoai la h
void HinhThoiDac(int h) {
	int hmax = h*2-1, head=h, tail=h;
	for(int i=1; i<=hmax; i++)
	{
		for(int j=1; j<=hmax; j++)
		{
			if(j>=head && j<=tail)	printf(" * ");
			else printf("   ");
		}
		if(i<h){	head--;		tail++;	}
		else{	head++;		tail--;	}
		printf("\n");
	}
/*	This code has the same fuction: 	
	for(int i=1; i<=hmax; i++)
	{
		for(int j=1; j<=hmax; j++)
		{
			if(i<=h && j>=h-i+1 && j<=h+i-1)
				printf(" * ");
			else if(i>h && j>=i-h+1 && j<= hmax-i+h)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}*/
}

	//Ve hinh thoi rong voi do cao tu day den ben ngoai la h
void HinhThoiRong(int h) {
	int hmax = h*2-1, head=h, tail=h;
	for(int i=1; i<=hmax; i++)
	{
		for(int j=1; j<=hmax; j++)
		{
			if(j==head || j==tail)	printf(" * ");
			else printf("   ");
		}
		if(i<h){	head--;		tail++;	}
		else{	head++;		tail--;	}
		printf("\n");
	}
	
/*	This code has the same fuction:
	for(int i=1; i<=hmax; i++)
	{
		for(int j=1; j<=hmax; j++)
		{
			if(i<=h && j<=h && j==h-i+1)
				printf(" * ");
			else if(i<=h && j>h && j==h+i-1)
				printf(" * ");
			else if(i>h && j<=h && i-j==h-1)
				printf(" * ");
			else if(i>h && j>h && hmax+h==i+j)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}*/
}

	//Ve hinh thang dac
void HinhThangDac(int h) {
	int day=h*3-2;		//Day lon cua hinh thang
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=day; j++)
		{
			if(i+j>=h+1 && j<=2*h+i-2)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}
/*	Doan code thu 2: Cong dung giong het doan tren
	int head=h, tail=2*h-1;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=day; j++)
		{
			if(j>=head && j<=tail)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
		head--;		tail++;
	}
*/
}

	//Ve hinh thang dac
void HinhThangRong(int h) {
	int day=h*3-2, head=h, tail=2*h-1;		//Day lon cua hinh thang
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=day; j++)
		{
			if((i==1 && j>=head && j<=tail) || i==h)
				printf(" * ");
			else if(j==head || j==tail)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
		head--;		tail++;
	}
}

	//Ve hinh thang nguoc dac
void HinhThangNguocDac(int h) {
	int day=h*3-2, head=1, tail=day;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=day; j++)
		{
			if(j>=head && j<=tail)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
		head++;		tail--;
	}
}

	//Ve hinh thang nguoc rong
void HinhThangNguocRong(int h) {
	int day=h*3-2, head=1, tail=day;		//Day lon cua hinh thang
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=day; j++)
		{
			if((i==h && j>=head && j<=tail) || i==1)
				printf(" * ");
			else if(j==head || j==tail)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
		head++;		tail--;
	}
}

	//Ve hinh dau cong
void HinhDauCong(int h) {
	int dai=3*h-2;
	for(int i=1; i<=dai; i++)
	{
		for(int j=1; j<=dai; j++)
		{
			if((i<h || i>2*h-1) && j>=h && j<2*h)
				printf(" * ");
			else if(i>=h && i<=2*h-1)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}
}

	//Quan li cac hinh hoc
void GeometricManagement() {
	int type, h, d, r;
	do{
		printf("\n=====Danh Sach Hinh Hoc=====\n");
		printf("\t1. Tam giac can dac.\n");
		printf("\t2. Tam giac can rong.\n");
		printf("\t3. Tam giac vuong dac.\n");
		printf("\t4. Tam giac vuong rong.\n");
		printf("\t5. Hinh vuong dac.\n");
		printf("\t6. Hinh vuong rong.\n");
		printf("\t7. Hinh chu nhat dac.\n");
		printf("\t8. Hinh chu nhat rong.\n");
		printf("\t9. Hinh thoi dac.\n");
		printf("\t10. Hinh thoi rong.\n");
		printf("\t11. Hinh thang dac.\n");
		printf("\t12. Hinh thang rong.\n");
		printf("\t13. Hinh thang nguoc dac.\n");
		printf("\t14. Hinh thang nguoc rong.\n");
		printf("\t15. Hinh dau cong.\n");
		printf("\t0. Thoat.\n");
		printf(">> Hay lua chon chuc nang: ");
		scanf("%d", &type);
		if(type<0 || type>15)
			printf("Chuc nang nay chua co\n");
	}while(type<0 || type>15);
	
	switch(type)
	{
		case 1:{
			printf("\t====Tam giac can dac====\n");
			TGCanDac(inputDoCao(h));
			break;
		}
		case 2:{
			printf("\t====Tam giac can rong====\n");
			TGCanRong(inputDoCao(h));
			break;
		}
		case 3:{
			printf("\t====Tam giac vuong dac====\n");
			TGVuongDac(inputDoCao(h));
			break;
		}
		case 4:{
			printf("\t====Tam giac vuong rong====\n");
			TGVuongRong(inputDoCao(h));
			break;
		}
		case 5:{
			printf("\t====Hinh vuong dac====\n");
			HVDac(inputDoCao(h));
			break;
		}
		case 6:{
			printf("\t====Hinh vuong rong====\n");
			HVRong(inputDoCao(h));
			break;
		}
		case 7:{
			printf("\t====Hinh chu nhat dac====\n");
			inputHcn(d, r);
			HCNDac(d, r);
			break;
		}
		case 8:{
			printf("\t====Hinh chu nhat rong====\n");
			inputHcn(d, r);
			HCNRong(d, r);
			break;
		}
		case 9:{
			printf("\t====Hinh thoi dac====\n");
			HinhThoiDac(inputDoCao(h));
			break;
		}
		case 10:{
			printf("\t====Hinh thoi rong====\n");
			HinhThoiRong(inputDoCao(h));
			break;
		}
		case 11:{
			printf("\t====Hinh thang dac====\n");
			HinhThangDac(inputDoCao(h));
			break;
		}
		case 12:{
			printf("\t====Hinh thang rong====\n");
			HinhThangRong(inputDoCao(h));
			break;
		}
		case 13:{
			printf("\t====Hinh thang nguoc dac====\n");
			HinhThangNguocDac(inputDoCao(h));
			break;
		}
		case 14:{
			printf("\t====Hinh thang nguoc rong====\n");
			HinhThangNguocRong(inputDoCao(h));
			break;
		}
		case 15:{
			printf("\t====Hinh dau cong====\n");
			HinhDauCong(inputDoCao(h));
			break;
		}
		case 0:{
			printf("\t====Thoat khoi chuong trinh====\n");
			exit(1);
		}
	}
}

	//Chuong trinh chinh
int main() {
	do{
		GeometricManagement();
	}while(true);
	return 0;
}

