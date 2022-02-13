#include<stdio.h>
#include<stdlib.h>
/*
	Khai bao kieu du lieu SOPHUC va dinh nghia ham nhap, ham xuat:
	-	Tinh tong hai so phuc
	-	Tinh hieu hai so phuc
	-	Tinh tich hai so phuc
	-	Tinh thuong hai so phuc
	-	Luy thua bac n cua so phuc
*/
typedef struct {
	int thuc;
	int ao;
}SOPHUC;

typedef struct {
	SOPHUC tu;
	SOPHUC mau;	
}THUONGSOPHUC;

void inpSoPhuc(SOPHUC &sp);
void outSoPhuc(SOPHUC sp);
void menu();
void tongSoPhuc(SOPHUC sp1, SOPHUC sp2);
void hieuSoPhuc(SOPHUC sp1, SOPHUC sp2);
void tichSoPhuc(SOPHUC sp1, SOPHUC sp2);
void thuongSoPhuc(SOPHUC sp1, SOPHUC sp2);
void luyThuaBacN(SOPHUC sp);

int main() {
	do{
		menu();
	}while(true);
	return 0;
}

	/*Nhap so phuc*/
void inpSoPhuc(SOPHUC &sp) {
	printf("\nNhap phan thuc: ");
	scanf("%d", &sp.thuc);
	printf("Nhap phan ao: ");
	scanf("%d", &sp.ao);
	outSoPhuc(sp);
}

	/*Xuat so phuc*/
void outSoPhuc(SOPHUC sp) {
	printf("%d + %di", sp.thuc, sp.ao);
}

	/*Chuc nang cua so phuc*/
void menu() {
	int choice;
	SOPHUC sp1, sp2;
	do{
		printf("\n===============Chuc nang So phuc===============");
		printf("\n1. Tong hai so phuc");
		printf("\n2. Hieu hai so phuc");
		printf("\n3. Tich hai so phuc");
		printf("\n4. Thuong hai so phuc");
		printf("\n5.Luy thua bac n so phuc");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>5)
			printf("\nChuc nang nay khong ton tai");
	}while(choice<0 || choice>5);
	
	switch(choice) {
		case 1:{
			printf("\n-----Tong hai so phuc-----");
			inpSoPhuc(sp1);
			inpSoPhuc(sp2);
			tongSoPhuc(sp1, sp2);
			break;
		}
		case 2:{
			printf("\n-----Hieu hai so phuc-----");
			inpSoPhuc(sp1);
			inpSoPhuc(sp2);
			hieuSoPhuc(sp1, sp2);
			break;
		}
		case 3:{
			printf("\n-----Tich hai so phuc-----");
			inpSoPhuc(sp1);
			inpSoPhuc(sp2);
			tichSoPhuc(sp1, sp2);
			break;
		}
		case 4:{
			printf("\n-----Thuong hai so phuc-----");
			inpSoPhuc(sp1);
			inpSoPhuc(sp2);
			thuongSoPhuc(sp1, sp2);
			break;
		}
		case 5:{
			printf("\n-----Luy thua bac n so phuc-----");
			inpSoPhuc(sp1);
			luyThuaBacN(sp1);
			break;
		}
		case 0: exit(0);
	}
}

	/*Tong hai so phuc*/
void tongSoPhuc(SOPHUC sp1, SOPHUC sp2) {
	SOPHUC tong;
	tong.thuc = sp1.thuc + sp2.thuc;
	tong.ao = sp1.ao + sp2.ao;
	printf("\nTong hai so phuc: ");
	outSoPhuc(tong);
}

	/*Hieu hai so phuc*/
void hieuSoPhuc(SOPHUC sp1, SOPHUC sp2) {
	SOPHUC hieu;
	hieu.thuc = sp1.thuc - sp2.thuc;
	hieu.ao = sp1.ao - sp2.ao;
	printf("\nHieu hai so phuc: ");
	outSoPhuc(hieu);
}

	/*Tich hai so phuc*/
void tichSoPhuc(SOPHUC sp1, SOPHUC sp2) {
	SOPHUC tich;
	tich.thuc = sp1.thuc*sp2.thuc - sp1.ao*sp2.ao;
	tich.ao = sp1.thuc*sp2.ao + sp2.thuc*sp1.ao;
	printf("\nTich hai so phuc: ");
	outSoPhuc(tich);
}

	/*Thuong hai so phuc*/
void thuongSoPhuc(SOPHUC sp1, SOPHUC sp2) {
	THUONGSOPHUC thuong;
	thuong.tu.thuc = sp1.thuc*sp2.thuc + sp1.ao*sp2.ao;
	thuong.tu.ao = sp2.thuc*sp1.ao - sp1.thuc*sp2.ao;
	thuong.mau.thuc = sp2.thuc*sp2.thuc + sp2.ao*sp2.ao;
	thuong.mau.ao = sp2.thuc*sp2.thuc + sp2.ao*sp2.ao;
	printf("\nThuong hai so phuc: ");
	printf("%d/%d + %d/%di", thuong.tu.thuc, thuong.mau.thuc, thuong.tu.ao, thuong.mau.ao);
}

	/*Luy thua bac n cua so phuc*/
void luyThuaBacN(SOPHUC sp) {
	SOPHUC luyThua = sp;
	int n;
	printf("\nNhap bac cua so phuc: ");
	scanf("%d", &n);
	if(n==0) {	//Truong hop bac 0
		printf("\nLuy thua bac 0 cua so phuc: 1");
		return;
	}
	for(int i=2; i<=n; i++)
	{
		SOPHUC tmp = luyThua;
		luyThua.thuc = tmp.thuc*sp.thuc - tmp.ao*sp.ao;
		luyThua.ao = tmp.thuc*sp.ao + sp.thuc*tmp.ao;
	}
	printf("\nLuy thua bac %d cua so phuc: ", n);
	outSoPhuc(luyThua);
}
