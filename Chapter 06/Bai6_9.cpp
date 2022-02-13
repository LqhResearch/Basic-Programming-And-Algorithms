#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
	Khai bao kieu du lieu va dinh nghia ham nhap, ham xuat:
	-	Tinh khoang cach giua hai diem trong khong gian.
	-	Tinh khoang cach giua hai diem trong khong gian theo phuong x.
	-	Tinh khoang cach giua hai diem trong khong gian theo phuong y.
	-	Tinh khoang cach giua hai diem trong khong gian theo phuong x.
	-	Tim toa do diem doi xung qua goc toa do.
	-	Tim toa do diem doi xung qua mat phang Oxy.
	-	Tim toa do diem doi xung qua mat phang Oxz.
	-	Tim toa do diem doi xung qua mat phang Oyz.
*/
typedef struct Diem {
	float x;
	float y;
	float z;
} Diem;

void InpDiem(Diem &d);
void OutDiem(Diem d);
void KhoangCach2Diem(Diem d1, Diem d2);
void KhoangCach2DiemX(Diem d1, Diem d2);
void KhoangCach2DiemY(Diem d1, Diem d2);
void KhoangCach2DiemZ(Diem d1, Diem d2);
void SerchDoiXungToaDo(Diem d);
void SerchDoiXungOxy(Diem d);
void SerchDoiXungOxz(Diem d);
void SerchDoiXungOyz(Diem d);

	/*Danh sach chuc nang*/
void menu() {
	int choice;
	do{
		printf("\n\t==========Toa Do Diem Khong Gian==========");
		printf("\n1. Nhap, xuat toa do diem.");
		printf("\n2. Tinh khoang cach giua hai diem trong khong gian.");
		printf("\n3. Tinh khoang cach giua hai diem trong khong gian theo phuong x.");
		printf("\n4. Tinh khoang cach giua hai diem trong khong gian theo phuong y.");
		printf("\n5. Tinh khoang cach giua hai diem trong khong gian theo phuong z.");
		printf("\n6. Tim toa do diem doi xung qua goc toa do.");
		printf("\n7. Tim toa do diem doi xung qua mat phang Oxy.");
		printf("\n8. Tim toa do diem doi xung qua mat phang Oxz.");
		printf("\n9. Tim toa do diem doi xung qua mat phang Oyx.");
		printf("\n0. Thoat.");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice < 0 || choice > 9)
			printf("\nChuc nang nay khong ton tai");
	}while(choice < 0 || choice > 9);
	
	Diem d1,d2;
	switch(choice) {
		case 1:{
			InpDiem(d1);
			break;
		}
		case 2:{
			InpDiem(d1);
			InpDiem(d2);
			KhoangCach2Diem(d1, d2);
			break;
		}
		case 3:{
			InpDiem(d1);
			InpDiem(d2);
			KhoangCach2DiemX(d1, d2);
			break;
		}
		case 4:{
			InpDiem(d1);
			InpDiem(d2);
			KhoangCach2DiemY(d1, d2);
			break;
		}case 5:{
			InpDiem(d1);
			InpDiem(d2);
			KhoangCach2DiemZ(d1, d2);
			break;
		}
		case 6:{
			InpDiem(d1);
			SerchDoiXungToaDo(d1);
			break;
		}
		case 7:{
			InpDiem(d1);
			SerchDoiXungOxy(d1);
			break;
		}
		case 8:{
			InpDiem(d1);
			SerchDoiXungOxz(d1);
			break;
		}
		case 9:{
			InpDiem(d1);
			SerchDoiXungOyz(d1);
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

	/*Nhap toa do diem*/
void InpDiem(Diem &d) {
	printf("\n\t-Toa do x: ");
	scanf("%f", &d.x);
	printf("\t-Toa do y: ");
	scanf("%f", &d.y);
	printf("\t-Toa do z: ");
	scanf("%f", &d.z);
	OutDiem(d);
}

	/*Xuat toa do diem*/
void OutDiem(Diem d) {
	printf("Diem (x, y, z) = (%.2f, %.2f, %2.f)", d.x, d.y, d.z);
}

	/*Tinh khoang cach giua hai diem trong khong gian*/
void KhoangCach2Diem(Diem d1, Diem d2) {
	printf("\nKhoang cach 2 diem: %.2f", sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2) + pow(d2.z - d1.z, 2)));
}

	/*Tinh khoang cach giua hai diem trong khong gian theo phuong x*/
void KhoangCach2DiemX(Diem d1, Diem d2) {
	printf("\nKhoang cach 2 diem: %.2f", sqrt(pow(d2.y - d1.y, 2) + pow(d2.z - d1.z, 2)));
}

	/*Tinh khoang cach giua hai diem trong khong gian theo phuong y*/
void KhoangCach2DiemY(Diem d1, Diem d2) {
	printf("\nKhoang cach 2 diem: %.2f", sqrt(pow(d2.x - d1.x, 2) + pow(d2.z - d1.z, 2)));
}

	/*Tinh khoang cach giua hai diem trong khong gian theo phuong z*/
void KhoangCach2DiemZ(Diem d1, Diem d2) {
	printf("\nKhoang cach 2 diem: %.2f", sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2)));
}

	/*Tim toa do diem doi xung qua goc toa do*/
void SerchDoiXungToaDo(Diem d) {
	printf("\nDiem doi xung (x, y, z) = (%.2f, %.2f, %.2f)", -d.x, -d.y, -d.z);
}

	/*Tim toa do diem doi xung qua mat phang Oxy*/
void SerchDoiXungOxy(Diem d) {
	printf("\nDiem doi xung qua Oxy (x, y, z) = (%.2f, %.2f, %.2f)", d.x, d.y, -d.z);
}

	/*Tim toa do diem doi xung qua mat phang Oxz*/
void SerchDoiXungOxz(Diem d) {
	printf("\nDiem doi xung qua Oxz (x, y, z) = (%.2f, %.2f, %.2f)", d.x, -d.y, d.z);
}

	/*Tim toa do diem doi xung qua mat phang Oyz*/
void SerchDoiXungOyz(Diem d) {
	printf("\nDiem doi xung qua Oyz (x, y, z) = (%.2f, %.2f, %.2f)", -d.x, d.y, d.z);
}

