#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
	Khai bao kieu du lieu PHANSO và dinh nghia ham nhap, ham xuat.
	-	Dinh nghia toan tu cong (operator +) cho hai phan so.
	-	Dinh nghia toan tu tru (operator -) cho hai phan so.
	-	Dinh nghia toan tu nhan (operator *) cho hai phan so.
	-	Dinh nghia toan tu chia (operator /) cho hai phan so.
	-	Dinh nghia toan tu tang mot (operator ++) cho hai phan so.
	-	Dinh nghia toan tu giam mot (operator --) cho hai phan so.
*/
	//Khai bao kieu du lieu PHANSO
typedef struct {
	int tuSo;
	int mauSo;
}PHANSO;

	//Xuat phan so
void XuatPhanSo(PHANSO ps) {
	printf("Phan so : %d / %d\n", ps.tuSo, ps.mauSo);
}

	//Nhap phan so
void NhapPhanSo(PHANSO &ps) {
	printf("Nhap tu so: ");
	scanf("%d", &ps.tuSo);
	printf("Nhap mau so: ");
	scanf("%d", &ps.mauSo);
	XuatPhanSo(ps);
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
PHANSO Tong(PHANSO ps1, PHANSO ps2) {
	PHANSO tong;
	tong.tuSo=ps1.tuSo*ps2.mauSo+ps2.tuSo*ps1.mauSo;
	tong.mauSo=ps1.mauSo*ps2.mauSo;
	RutGonPS(tong);
	return tong;
}

	//Hieu hai phan so
PHANSO Hieu(PHANSO ps1, PHANSO ps2) {
	PHANSO hieu;
	hieu.tuSo=ps1.tuSo*ps2.mauSo-ps2.tuSo*ps1.mauSo;
	hieu.mauSo=ps1.mauSo*ps2.mauSo;
	RutGonPS(hieu);
	return hieu;
}

	//Tich hai phan so
PHANSO Tich(PHANSO ps1, PHANSO ps2) {
	PHANSO tich;
	tich.tuSo=ps1.tuSo*ps2.tuSo;
	tich.mauSo=ps1.mauSo*ps2.mauSo;
	RutGonPS(tich);
	return tich;
}

	//Thuong hai phan so
PHANSO Thuong(PHANSO ps1, PHANSO ps2) {
	PHANSO thuong;
	thuong.tuSo=ps1.tuSo*ps2.mauSo;
	thuong.mauSo=ps1.mauSo*ps2.tuSo;
	RutGonPS(thuong);
	return thuong;
}

	//Quan li tat cac tinh nang cua phan so
void PhanSoManage() {
	char pheptinh[2];
	PHANSO ps1, ps2;
	printf("\n\t====Phep Toan Phan So=====\n");
	printf("\n+. Tong hai phan so");
	printf("\n-. Hieu hai phan so");
	printf("\n*. Tich hai phan so");
	printf("\n/. Thuong hai phan so");
	printf("\n++. Tang phan so them 1");
	printf("\n--. Giam phan so di 1");
	printf("\ne. Thoat");
	printf("\nNhap phep toan = ");
	fflush(stdin);		gets(pheptinh);
	
	if(strcmp(pheptinh, "+") == 0) {
		printf("\n=====Tong hai phan so=====\n");
		NhapPhanSo(ps1);
		NhapPhanSo(ps2);
		printf("Tong = ");
		XuatPhanSo(Tong(ps1, ps2));
	}
	else if(strcmp(pheptinh, "-") == 0) {
		printf("\n=====Hieu hai phan so=====\n");
		NhapPhanSo(ps1);
		NhapPhanSo(ps2);
		printf("Hieu = ");
		XuatPhanSo(Hieu(ps1, ps2));
	}
	else if(strcmp(pheptinh, "*") == 0) {
		printf("\n=====Tich hai phan so=====\n");
		NhapPhanSo(ps1);
		NhapPhanSo(ps2);
		printf("Tich = ");
		XuatPhanSo(Tich(ps1, ps2));		
	}
	else if(strcmp(pheptinh, "/") == 0) {
		printf("\n=====Thuong hai phan so=====\n");
		NhapPhanSo(ps1);
		NhapPhanSo(ps2);
		printf("Thuong = ");
		XuatPhanSo(Thuong(ps1, ps2));		
	}
	else if(strcmp(pheptinh, "++") == 0) {
		printf("\n=====Tang phan so them 1=====\n");
		NhapPhanSo(ps1);
		ps2.tuSo=ps2.mauSo=1;
		XuatPhanSo(Tong(ps1, ps2));		
	}
	else if(strcmp(pheptinh, "--") == 0) {
		printf("\n=====Giam phan so di 1=====\n");
		NhapPhanSo(ps1);
		ps2.tuSo=ps2.mauSo=1;
		XuatPhanSo(Hieu(ps1, ps2));		
	}
	else exit(1);
}

int main() {
	do{
		PhanSoManage();
	}while(true);
	return 0;
}

