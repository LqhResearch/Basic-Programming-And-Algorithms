#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
/*
	Hay khai bao kieu du lieu de bieu dien thong tin cua mot tinh. Biet rang mot tinh gom nhung thanh pha nhu sau:
	-	Ma tinh (kieu nguyen)
	-	Ten tinh (30 ky tu)
	-	Dan so (kieu nguyen)
	-	Dien tich (kieu thuc)
	a. Xuat cac tinh co dan so lon hon 1.000.000
	b. Tim mot tinh co dien tich lon nhat.
	c. Sap xep cac tinh giam dan theo dien tich.
*/
typedef struct Tinh {
	int maSo;
	char ten[30];
	int danSo;
	float dTich;
} Tinh;

void AddTinh();
void OutTinhMillion();
void SearchMaxArea();
void SortList();

Tinh listTinh[MAX];
int local = -1;

	/*Danh sach chuc nang*/
void menu() {
	int choice;
	do{
		printf("\n\t==========Danh sach Tinh==========");
		printf("\n1. Them tinh");
		printf("\n2. Xuat cac tinh co dan so lon hon 1.000.000");
		printf("\n3. Tim mot tinh co dien tich lon nhat");
		printf("\n4. Sap xep cac tinh giam dan theo dien tich");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice < 0 || choice > 4)
			printf("\nChuc nang nay khong ton tai");
	}while(choice < 0 || choice > 4);
	
	switch(choice) {
		case 1:{
			AddTinh();
			break;
		}
		case 2:{
			OutTinhMillion();
			break;
		}
		case 3:{
			SearchMaxArea();
			break;
		}
		case 4:{
			SortList();
			break;
		}
		case 0: exit(0);
	}
}

	/*Main function*/
int main() {
	do{
		menu();
	}while(true);
	return 0;
}

	/*Them 1 tinh*/
void AddTinh() {
	local++;
	printf("\nMa tinh: ");
	scanf("%d", &listTinh[local].maSo);
	printf("Ten tinh: ");
	fflush(stdin);	gets(listTinh[local].ten);
	printf("Dan so: ");
	scanf("%d", &listTinh[local].danSo);
	printf("Dien tich: ");
	scanf("%f", &listTinh[local].dTich);
}

	/*Xuat cac tinh co dan so lon hon 1.000.000*/
void OutTinhMillion() {
	for(int i=0; i<=local; i++)
		if(listTinh[i].danSo > 1000000) {
			printf("\nMa tinh: %d", listTinh[i].maSo);
			printf("\nTen tinh: %s", listTinh[i].ten);
			printf("\nDan so: %d", listTinh[i].danSo);
			printf("\nDien tich: %.2f", listTinh[i].dTich);
		}
}

	/*Tim mot tinh co dien tich lon nhat*/
void SearchMaxArea() {
	Tinh max = listTinh[0];
	for(int i=0; i<=local; i++)
		if(listTinh[i].dTich > max.dTich)
			max = listTinh[i];
	
	printf("\nMa tinh: %d", max.maSo);
	printf("\nTen tinh: %s", max.ten);
	printf("\nDan so: %d", max.danSo);
	printf("\nDien tich: %.2f", max.dTich);
}

	/*Hoan vi 2 tinh*/
void Swap(Tinh &t1, Tinh &t2) {
	Tinh temp = t1;
	t1 = t2;
	t2 = temp;
}

	/*Sap xep cac tinh giam dan theo dien tich*/
void SortList() {
	for(int i=0; i<local; i++)
		for(int j=i+1; j<=local; j++)
			if(listTinh[i].dTich < listTinh[j].dTich)
				Swap(listTinh[i], listTinh[j]);
	
	for(int i=0; i<=local; i++) {
		printf("\nMa tinh: %d", listTinh[i].maSo);
		printf("\nTen tinh: %s", listTinh[i].ten);
		printf("\nDan so: %d", listTinh[i].danSo);
		printf("\nDien tich: %.2f", listTinh[i].dTich);
	}
}

