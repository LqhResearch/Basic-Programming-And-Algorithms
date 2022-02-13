#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
	Khai bao kieu du lieu DONTHUC va dinh nghia ham nhap, ham xuat.
	-	Tich tich hai don thuc.
	-	Tich thuong hai don thuc.
	-	Tinh dao ham cap 1 don thuc.
	-	Tinh dao ham cap k don thuc.
	-	Tinh gia tri don thuc toi vi tri x = xo.
*/
typedef struct DonThuc {
	float heSo;
	int soMu;
} DonThuc;

void InpDonThuc(DonThuc &dt);
void OutDonThuc(DonThuc dt);
void TichDonThuc(DonThuc dt1, DonThuc dt2);
void ThuongDonThuc(DonThuc dt1, DonThuc dt2);
void menu();

	/*Main function*/
int main() {
	do{
		menu();
	}while(true);
	return 0;
}

	/*Nhap don thuc*/
void InpDonThuc(DonThuc &dt) {
	printf("\nNhap he so: ");
	scanf("%f", &dt.heSo);
	printf("Nhap so mu: ");
	scanf("%d", &dt.soMu);
	OutDonThuc(dt);
}

	/*Xuat don thuc*/
void OutDonThuc(DonThuc dt) {
	if(dt.soMu == 0)
		printf("Don thuc: %.2f", dt.heSo);
	else if(dt.soMu == 1)
		printf("Don thuc: %.2fx", dt.heSo);
	else printf("Don thuc: %.2fx^%d", dt.heSo, dt.soMu);
}

	/*Tich hai don thuc*/
void TichDonThuc(DonThuc dt1, DonThuc dt2) {
	DonThuc multi;
	multi.heSo = dt1.heSo*dt2.heSo;
	multi.soMu = dt1.soMu+dt2.soMu;
	
	printf("\nTich hai ");
	OutDonThuc(multi);
}

	/*Thuong hai don thuc*/
void ThuongDonThuc(DonThuc dt1, DonThuc dt2) {
	DonThuc div;
	div.heSo = dt1.heSo/dt2.heSo;
	div.soMu = dt1.soMu-dt2.soMu;
	
	printf("\nThuong hai ");
	OutDonThuc(div);
}

	/*Tinh dao ham*/
DonThuc daoHam(DonThuc dt) {
	if(dt.soMu == 0)
		dt.heSo = 0;
	else {
		dt.heSo*=dt.soMu;
		dt.soMu--;
	}
	return dt;
}

	/*Dao ham cap k*/
void daoHamK(DonThuc dt) {
	int k;
	do{
		printf("\nNhap cap(> 1): ");
		scanf("%d", &k);
	}while(k < 2);
	
	for(int i=1; i<=k; i++)
		dt = daoHam(dt);
	printf("\nDao ham cap %d cua ", k);
	OutDonThuc(dt);
}

	/*Gia tri don thuc toi vi tri x = xo*/
void ValueAtDonThuc(DonThuc dt) {
	int x;
	printf("\nNhap gia tri x: ");
	scanf("%d", &x);
	
	float ans = dt.heSo*pow(x, dt.soMu);
	printf("\nGia tri la %.2f", ans);
}

	/*Chuc nang cua Don thuc*/
void menu() {
	DonThuc dt1, dt2;
	int choice;
	do{
		printf("\n=====Chuc nang Don thuc=====");
		printf("\n1. Tich hai don thuc");
		printf("\n2. Thuong hai don thuc");
		printf("\n3. Dao ham cap 1 cua don thuc");
		printf("\n4. Dao ham cap k cua don thuc");
		printf("\n5. Gia tri don thuc toi vi tri x = xo");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>5)
			printf("\nChuc nang nay khong ton tai");
	}while(choice<0 || choice>5);
	
	switch(choice) {
		case 1:{
			InpDonThuc(dt1);
			InpDonThuc(dt2);
			TichDonThuc(dt1, dt2);
			break;
		}
		case 2:{
			InpDonThuc(dt1);
			InpDonThuc(dt2);
			ThuongDonThuc(dt1, dt2);
			break;
		}
		case 3:{
			InpDonThuc(dt1);
			OutDonThuc(daoHam(dt1));
			break;
		}
		case 4:{
			InpDonThuc(dt1);
			daoHamK(dt1);
			break;
		}
		case 5:{
			InpDonThuc(dt1);
			ValueAtDonThuc(dt1);
			break;
		}
		case 0: exit(0);
	}
}
