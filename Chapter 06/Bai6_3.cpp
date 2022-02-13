#include<stdio.h>
#include<stdlib.h>
/*
	Khai bao kieu du lieu HONSO và dinh nghia ham nhap, ham xuat.
	-	Tinh tong hai hon so.
	-	Tinh hieu hai hon so.
	-	Tinh tich hai hon so.
	-	Tinh thuong hai hon so.	
	-	Kiem tra hon so toi gian.
	-	Rut gon hon so.
	-	Qui dong hai hon so.
	-	So sanh hai hon so.
	-	Tim hon so lon nhat trong hai hon so.
	-	Tim hon so nho nhat trong hai hon so.
	-	Chuyen doi: Hon so thanh Phan so.
	-	Chuyen doi: Phan so thanh Hon so.
*/
typedef struct {
	int tuSo;
	int mauSo;
}PHANSO;

typedef struct {
	int nguyen;
	PHANSO ps;
}HONSO;

	//Xuat phan so
void XuatHonSo(HONSO hs) {
	printf("Hon so : %d and %d / %d\n", hs.nguyen, hs.ps.tuSo, hs.ps.mauSo);
}

	//Nhap phan so
void NhapHonSo(HONSO &hs) {
	printf("Nhap phan nguyen: ");
	scanf("%d", &hs.nguyen);
	printf("Nhap tu so: ");
	scanf("%d", &hs.ps.tuSo);
	do{
		printf("Nhap mau so: ");
		scanf("%d", &hs.ps.mauSo);
		if(hs.ps.mauSo == 0)
			printf("\nMau so la so khac 0");
	}while(hs.ps.mauSo == 0);
	XuatHonSo(hs);
}

	//Rut gon phan so
void RutGonPS(PHANSO &ps) {
	int us;
	for(int i=1; i<=ps.tuSo; i++)
		if(ps.tuSo%i==0 && ps.mauSo%i==0)
			us=i;
	ps.tuSo/=us;
	ps.mauSo/=us;
}

	//Tong hai phan so
PHANSO TongPS(PHANSO ps1, PHANSO ps2) {
	PHANSO tong;
	tong.tuSo=ps1.tuSo*ps2.mauSo+ps2.tuSo*ps1.mauSo;
	tong.mauSo=ps1.mauSo*ps2.mauSo;
	RutGonPS(tong);
	return tong;
}

	//Tong hai hon so
HONSO TongHS(HONSO hs1, HONSO hs2) {
	HONSO tongHS;
	tongHS.nguyen = hs1.nguyen + hs2.nguyen;
	PHANSO tongPS = TongPS(hs1.ps, hs2.ps);
	tongHS.ps.tuSo = tongPS.tuSo;
	tongHS.ps.mauSo = tongPS.mauSo;
	return tongHS;
}

	//Quan li tat cac tinh nang cua hon so
void HonSoManage() {
	int type;
	HONSO hs1, hs2;
	do{
		printf("\n\t====Phep Toan Hon So=====\n");
		printf("\n1. Tong hai hon so");
		printf("\n2. Hieu hai hon so");
		printf("\n3. Tich hai hon so");
		printf("\n4. Thuong hai hon so");
		printf("\n5. Kiem tra hon so toi gian");
		printf("\n6. Rut gon hon so");
		printf("\n7. Qui dong hai hon so");
		printf("\n8. So sanh hai hon so");
		printf("\n9. Tim hon so lon nhat");
		printf("\n10. Tim hon so nho nhat");
		printf("\n11. Chuyen doi: Hon so -> Phan so");
		printf("\n12. Chuyen doi: Phan so -> Hon so");
		printf("\n\n0. Thoat");
		printf("\n>>  Hay lua chon: ");
		scanf("%d", &type);
		if(type<0 || type>12)
			printf("Chuc nang nay khong ton tai\n");
	}while(type<0 || type>12);
	
	switch(type) {
		case 1:{
			printf("\n=====Tong hai hon so=====\n");
			NhapHonSo(hs1);
			NhapHonSo(hs2);
			printf("Tong = ");
			XuatHonSo(TongHS(hs1, hs2));
			break;
		}
		case 2:{
			printf("\n=====Hieu hai hon so=====\n");
			
			break;
		}
		case 3:{
			printf("\n=====Tich hai hon so=====\n");
			
			break;
		}
		case 4:{
			printf("\n=====Thuong hai hon so=====\n");
			
			break;
		}
		case 5:{
			printf("\n=====Kiem tra hon so toi gian=====\n");
			
			break;
		}
		case 6:{
			printf("\n=====Rut gon hon so=====\n");
			
			break;
		}
		case 7:{
			printf("\n=====Quy dong hai hon so=====\n");
			
			break;
		}
		case 8:{
			printf("\n=====So sanh hai hon so=====\n");
			
			break;
		}
		case 9:{
			printf("\n=====Tim hon so lon nhat=====\n");
			
			break;
		}
		case 10:{
			printf("\n=====Tim hon so nho nhat=====\n");
			
			break;
		}
		case 11:{
			printf("\n=====Chuyen doi: Hon so -> Phan so=====\n");
			
			break;
		}
		case 12:{
			printf("\n=====Chuyen doi: Phan so -> Hon so=====\n");
			
			break;
		}
		case 0: exit(1);
	}
}

int main() {
	do{
		HonSoManage();
	}while(true);
	return 0;
}

