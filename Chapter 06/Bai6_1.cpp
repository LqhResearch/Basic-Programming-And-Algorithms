#include<stdio.h>
#include<stdlib.h>
/*
	Khai bao kieu du lieu PHANSO và dinh nghia ham nhap, ham xuat.
	-	Tính tong hai phân so.
	-	Tính hieu hai phân so.
	-	Tính tích hai phân so.
	-	Tính thuong hai phân so.
	-	Kiem tra phan so toi gian.
	-	Rut gon phân so.
	-	Qui dong hai phân so.
	-	So sánh hai phân so.
	-	Tìm phân so lon nhat.
	-	Tìm phân so nho nhat. 
	-	Kiem tra có phai phan so duong hay không?.
	-	Kiem tra có phai phan so am hay không?.
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

	//Kiem tra phan so toi gian chua?
void CheckToiGianPS(PHANSO ps) {
	int us;
	for(int i=1; i<=ps.tuSo; i++)
		if(ps.tuSo%i==0 && ps.mauSo%i==0)
			us=i;
	if(us == 1) printf("Phan so da toi gian");
	else printf("Phan so chua da toi gian");
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

	//Qui dong hai phan so
void QuiDongPS(PHANSO ps1, PHANSO ps2) {
	int bs;
	for(int i=ps1.mauSo*ps2.mauSo; i>=ps1.mauSo; i--)
		if(i%ps1.mauSo==0 && i%ps2.mauSo==0)
			bs=i;
	ps1.tuSo=ps1.tuSo*(bs/ps1.mauSo);
	ps1.mauSo=bs;
	XuatPhanSo(ps1);
	
	ps2.tuSo=ps2.tuSo*(bs/ps2.mauSo);
	ps2.mauSo=bs;
	XuatPhanSo(ps2);
}

	//So sanh hai phan so
void SoSanhPS(PHANSO ps1, PHANSO ps2) {
	float p1=1.0*ps1.tuSo/ps1.mauSo;
	float p2=1.0*ps2.tuSo/ps2.mauSo;
	if(p1 > p2)
		printf("%d / %d lon hon %d / %d", ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo);
	else if(p1 == p2)
		printf("%d / %d bang %d / %d", ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo);
	else
		printf("%d / %d nho hon %d / %d", ps1.tuSo, ps1.mauSo, ps2.tuSo, ps2.mauSo);
}

	//Tim phan so lon nhat
void MaxPS(PHANSO ps1, PHANSO ps2) {
	float p1=1.0*ps1.tuSo/ps1.mauSo;
	float p2=1.0*ps2.tuSo/ps2.mauSo;
	if(p1 > p2)	XuatPhanSo(ps1);
	else	XuatPhanSo(ps2);
}

	//Tim phan so nho nhat
void MinPS(PHANSO ps1, PHANSO ps2) {
	float p1=1.0*ps1.tuSo/ps1.mauSo;
	float p2=1.0*ps2.tuSo/ps2.mauSo;
	if(p1 < p2)	XuatPhanSo(ps1);
	else	XuatPhanSo(ps2);
}

	//Kiem tra phan so co phai la phan so duong hay khong?
void CheckPSDuong(PHANSO ps) {
	if((ps.tuSo>0 && ps.mauSo>0) || (ps.tuSo<0 && ps.mauSo<0))
		printf("%d / %d la phan so duong", ps.tuSo, ps.mauSo);
	else
		printf("%d / %d khong phai la phan so duong", ps.tuSo, ps.mauSo);
}

	//Kiem tra phan so co phai la phan so am hay khong?
void CheckPSAm(PHANSO ps) {
	if((ps.tuSo>0 && ps.mauSo<0) || (ps.tuSo<0 && ps.mauSo>0))
		printf("%d / %d la phan so am", ps.tuSo, ps.mauSo);
	else
		printf("%d / %d khong phai la phan so am", ps.tuSo, ps.mauSo);
}

	//Quan li tat cac tinh nang cua phan so
void PhanSoManage() {
	int type;
	PHANSO ps1, ps2;
	do{
		printf("\n\t====Phep Toan Phan So=====\n");
		printf("\n1. Tong hai phan so");
		printf("\n2. Hieu hai phan so");
		printf("\n3. Tich hai phan so");
		printf("\n4. Thuong hai phan so");
		printf("\n5. Kiem tra phan so toi gian");
		printf("\n6. Rut gon phan so");
		printf("\n7. Qui dong hai phan so");
		printf("\n8. So sanh hai phan so");
		printf("\n9. Tim phan so lon nhat");
		printf("\n10. Tim phan so nho nhat");
		printf("\n11. Kiem tra phan so co phai la phan so duong hay khong?");
		printf("\n12. Kiem tra phan so co phai la phan so am hay khong?");
		printf("\n\n0. Thoat");
		printf("\n>> Hay lua chon: ");
		scanf("%d", &type);
		if(type<0 || type>12)
			printf("Chuc nang nay khong ton tai\n");
	}while(type<0 || type>12);
	
	switch(type) {
		case 1:{
			printf("\n=====Tong hai phan so=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			printf("Tong = ");
			XuatPhanSo(Tong(ps1, ps2));
			break;
		}
		case 2:{
			printf("\n=====Hieu hai phan so=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			printf("Hieu = ");
			XuatPhanSo(Hieu(ps1, ps2));
			break;
		}
		case 3:{
			printf("\n=====Tich hai phan so=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			printf("Tich = ");
			XuatPhanSo(Tich(ps1, ps2));
			break;
		}
		case 4:{
			printf("\n=====Thuong hai phan so=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			printf("Thuong = ");
			XuatPhanSo(Thuong(ps1, ps2));
			break;
		}
		case 5:{
			printf("\n=====Kiem tra phan so toi gian=====\n");
			NhapPhanSo(ps1);
			CheckToiGianPS(ps1);
			break;
		}
		case 6:{
			printf("\n=====Rut gon phan so=====\n");
			NhapPhanSo(ps1);
			printf("Rut gon = ");
			RutGonPS(ps1);
			XuatPhanSo(ps1);
			break;
		}
		case 7:{
			printf("\n=====Quy dong hai phan so=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			printf("Qui dong: \n");
			QuiDongPS(ps1, ps2);
			break;
		}
		case 8:{
			printf("\n=====So sanh hai phan so=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			SoSanhPS(ps1, ps2);
			break;
		}
		case 9:{
			printf("\n=====Tim phan so lon nhat=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			printf("Max ");
			MaxPS(ps1, ps2);
			break;
		}
		case 10:{
			printf("\n=====Tim phan so nho nhat=====\n");
			NhapPhanSo(ps1);
			NhapPhanSo(ps2);
			printf("Min ");
			MinPS(ps1, ps2);
			break;
		}
		case 11:{
			printf("\n=====Kiem tra phan so co phai la phan so duong hay khong?=====\n");
			NhapPhanSo(ps1);
			CheckPSDuong(ps1);
			break;
		}
		case 12:{
			printf("\n=====Kiem tra phan so co phai la phan so am hay khong?=====\n");
			NhapPhanSo(ps1);
			CheckPSAm(ps1);
			break;
		}
		case 0: exit(1);
	}
}

	//Chuong trinh chinh
int main() {
	do{
		PhanSoManage();
	}while(true);
	return 0;
}

