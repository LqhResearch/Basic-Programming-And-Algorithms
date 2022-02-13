#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50
/*
	Khai bao kieu du lieu va dinh nghia ham nhap, ham xuat:
	-	Tinh khoang cach giua hai diem.
	-	Tinh khoang cach giua hai diem theo phuong Ox.
	-	Tinh khoang cach giua hai diem theo phuong Oy.
	-	Tim toa do diem doi xung qua goc toa do.
	-	Tim toa do diem doi xung qua goc truc hoanh.
	-	Tim toa do diem doi xung qua goc truc tung.
	-	Kiem tra diem co thuoc phan tu thu I khong?
	-	Kiem tra diem co thuoc phan tu thu II khong?
	-	Kiem tra diem co thuoc phan tu thu III khong?
	-	Kiem tra diem co thuoc phan tu thu IV khong?
	-	Dem so luong diem trong mang co hoanh do duong.
	-	Dem so luong diem khong trung voi diem khac trong mang.
	-	Tim diem trong mang co tung do lon nhat trong mang.
	-	Tim mot diem trong mang gan goc toa do nhat.
	-	Tim mot diem trong mang xa goc toa do nhat.
*/
typedef struct Diem {
	float x;
	float y;
} Diem;

void InpDiem(Diem &d);
void OutDiem(Diem d);
void KhoangCach2Diem(Diem d1, Diem d2);
void KhoangCach2DiemOx(Diem d1, Diem d2);
void KhoangCach2DiemOy(Diem d1, Diem d2);
void DiemDoiXung(Diem d);
void DiemDoiXungTrucHoanh(Diem d);
void DiemDoiXungTrucTung(Diem d);
void TestGocI(Diem d);
void TestGocII(Diem d);
void TestGocIII(Diem d);
void TestGocIV(Diem d);

void InpArrayDiem(Diem arrd[], int &n);
void OutArrayDiem(Diem arrd[], int &n);
void CountXDuong(Diem arrd[], int &n);
void CountDiemDN(Diem arrd[], int &n);
void SearchMaxTung(Diem arrd[], int &n);
void SearchGanToaDo(Diem arrd[], int &n);
void SearchXaToaDo(Diem arrd[], int &n);

	/*Danh sach chuc nang*/
void menu() {
	int choice;
	do{
		printf("\n\t==========Toa Do Diem==========");
		printf("\n1. Nhap, xuat toa do diem.");
		printf("\n2. Tinh khoang cach giua hai diem.");
		printf("\n3. Tinh khoang cach giua hai diem theo phuong Ox.");
		printf("\n4. Tinh khoang cach giua hai diem theo phuong Oy.");
		printf("\n5. Tim toa do diem doi xung qua goc toa do.");
		printf("\n6. Tim toa do diem doi xung qua goc truc hoanh.");
		printf("\n7. Tim toa do diem doi xung qua goc truc tung.");
		printf("\n8. Kiem tra diem co thuoc phan tu thu I khong?");
		printf("\n9. Kiem tra diem co thuoc phan tu thu II khong?");
		printf("\n10. Kiem tra diem co thuoc phan tu thu III khong?");
		printf("\n11. Kiem tra diem co thuoc phan tu thu IV khong?\n");
		printf("\n\t==========Mang Toa Do Diem==========");
		printf("\n12. Nhap, xuat mang toa do diem.");
		printf("\n13. Dem so luong diem trong mang co hoanh do duong.");
		printf("\n14. Dem so luong diem khong trung voi diem khac trong mang.");
		printf("\n15. Tim diem trong mang co tung do lon nhat trong mang.");
		printf("\n16. Tim mot diem trong mang gan goc toa do nhat.");
		printf("\n17. Tim mot diem trong mang xa goc toa do nhat.");
		printf("\n0. Thoat.");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice < 0 || choice > 17)
			printf("\nChuc nang nay khong ton tai");
	}while(choice < 0 || choice > 17);
	
	Diem d1, d2;	//Diem
	Diem arrd[MAX];	//Mang diem
	int n;
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
			KhoangCach2DiemOx(d1, d2);
			break;
		}
		case 4:{
			InpDiem(d1);
			InpDiem(d2);
			KhoangCach2DiemOy(d1, d2);
			break;
		}
		case 5:{
			InpDiem(d1);
			DiemDoiXung(d1);
			break;
		}
		case 6:{
			InpDiem(d1);
			DiemDoiXungTrucHoanh(d1);
			break;
		}
		case 7:{
			InpDiem(d1);
			DiemDoiXungTrucTung(d1);
			break;
		}
		case 8:{
			InpDiem(d1);
			TestGocI(d1);
			break;
		}
		case 9:{
			InpDiem(d1);
			TestGocII(d1);
			break;
		}
		case 10:{
			InpDiem(d1);
			TestGocIII(d1);
			break;
		}
		case 11:{
			InpDiem(d1);
			TestGocIV(d1);
			break;
		}
		case 12:{
			InpArrayDiem(arrd, n);
			break;
		}
		case 13:{
			CountXDuong(arrd, n);
			break;
		}
		case 14:{
			CountDiemDN(arrd, n);
			break;
		}
		case 15:{
			SearchMaxTung(arrd, n);
			break;
		}
		case 16:{
			SearchGanToaDo(arrd, n);
			break;
		}
		case 17:{
			SearchXaToaDo(arrd, n);
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
	OutDiem(d);
}

	/*Xuat toa do diem*/
void OutDiem(Diem d) {
	printf("Diem (x, y) = (%.2f, %.2f)", d.x, d.y);
}

	/*Tinh khoang cach giua hai diem.*/
void KhoangCach2Diem(Diem d1, Diem d2) {
	Diem temp;
	temp.x = d2.x - d1.x;
	temp.y = d2.y - d1.y;
	printf("\nKhoang cach 2 diem: %.2f", sqrt(temp.x*temp.x + temp.y*temp.y));
}

	/*Tinh khoang cach giua hai diem theo phuong Ox*/
void KhoangCach2DiemOx(Diem d1, Diem d2) {
	printf("\nKhoang cach giua hai diem theo phuong Ox: %.2f", d2.x - d1.x);
}

	/*Tinh khoang cach giua hai diem theo phuong Oy*/
void KhoangCach2DiemOy(Diem d1, Diem d2) {
	printf("\nKhoang cach giua hai diem theo phuong Oy: %.2f", d2.y - d1.y);
}

	/*Tim toa do diem doi xung qua goc toa do*/
void DiemDoiXung(Diem d) {
	printf("\nDiem doi xung (x, y) = (%.2f, %.2f)", -d.x, -d.y);
}

	/*Tim toa do diem doi xung qua goc truc hoanh*/
void DiemDoiXungTrucHoanh(Diem d) {
	printf("\nDiem doi xung truc hoanh (x, y) = (%.2f, %.2f)", d.x, -d.y);
}

	/*Tim toa do diem doi xung qua goc truc tung*/
void DiemDoiXungTrucTung(Diem d) {
	printf("\nDiem doi xung truc tung (x, y) = (%.2f, %.2f)", -d.x, d.y);
}

	/*
		-	Goc phan tu thu I (x, y) = (+, +)
		-	Goc phan tu thu II (x, y) = (-, +)
		-	Goc phan tu thu III (x, y) = (-, -)
		-	Goc phan tu thu IV (x, y) = (+, -)
	*/
	
	/*Kiem tra diem co thuoc phan tu thu I khong?*/
void TestGocI(Diem d) {
	if(d.x > 0 && d.y > 0)
		printf("\nDiem thuoc goc phan tu thu I");
	else
		printf("\nKhong thuoc goc phan tu thu I");
}

	/*Kiem tra diem co thuoc phan tu thu II khong?*/
void TestGocII(Diem d) {
	if(d.x < 0 && d.y > 0)
		printf("\nDiem thuoc goc phan tu thu II");
	else
		printf("\nKhong thuoc goc phan tu thu II");
}

	/*Kiem tra diem co thuoc phan tu thu III khong?*/
void TestGocIII(Diem d) {
	if(d.x < 0 && d.y < 0)
		printf("\nDiem thuoc goc phan tu thu III");
	else
		printf("\nKhong thuoc goc phan tu thu III");
}

	/*Kiem tra diem co thuoc phan tu thu IV khong?*/
void TestGocIV(Diem d) {
	if(d.x > 0 && d.y < 0)
		printf("\nDiem thuoc goc phan tu thu IV");
	else
		printf("\nKhong thuoc goc phan tu thu IV");
}

	/*Nhap mang toa do diem*/
void InpArrayDiem(Diem arrd[], int &n) {
	printf("\nSo luong toa do diem: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("\nPhan tu %d: ", i);
		InpDiem(arrd[i]);
	}
	OutArrayDiem(arrd, n);
}

	/*Xuat mang toa do diem*/
void OutArrayDiem(Diem arrd[], int &n) {
	for(int i=0; i<n; i++) {
		printf("\nPhan tu %d: ", i);
		OutDiem(arrd[i]);
	}
}

	/*Dem so luong diem trong mang co hoanh do duong*/
void CountXDuong(Diem arrd[], int &n) {
	InpArrayDiem(arrd, n);
	
	int count = 0;
	for(int i=0; i<n; i++)
		if(arrd[i].x > 0)
			count++;
	printf("\n%d diem co hoanh do duong", count);
}

	/*Kiem tra mot phan tu co ton tai chua*/
bool TestExist(Diem arrd[], int n, Diem test) {
	int count = -1;
	for(int i=0; i<n; i++)
		if((arrd[i].x == test.x) && (arrd[i].y == test.y))
			count++;
	if(count == 0) return true;
	else return false;
}

	/*Dem so luong diem khong trung voi diem khac trong mang*/
void CountDiemDN(Diem arrd[], int &n) {
	InpArrayDiem(arrd, n);
	
	int count = 0;
	for(int i=0; i<n; i++)
		if(TestExist(arrd, n, arrd[i]) == true)
			count++;
	printf("\n%d diem khong trung nhau", count);
}

	/*Tim diem trong mang co tung do lon nhat trong mang*/
void SearchMaxTung(Diem arrd[], int &n) {
	InpArrayDiem(arrd, n);
	
	Diem max = arrd[0];
	for(int i=1; i<n; i++)
		if(arrd[i].y > max.y)
			max = arrd[i];
	printf("\nDiem co tung do cao nhat (x, y) = (%.2f, %.2f)", max.x, max.y);
}

	/*Tim mot diem trong mang gan goc toa do nhat*/
void SearchGanToaDo(Diem arrd[], int &n) {
	InpArrayDiem(arrd, n);
	
	Diem max = arrd[0];
	for(int i=1; i<n; i++) {
		float diem1 = sqrt(max.x*max.x + max.y*max.y);
		float diem2 = sqrt(arrd[i].x*arrd[i].x + arrd[i].y*arrd[i].y);
		if(diem2 < diem1)
			max = arrd[i];
	}
	printf("\nDiem gan goc toa do nhat (x, y) = (%.2f, %.2f)", max.x, max.y);
}

	/*Tim mot diem trong mang xa goc toa do nhat*/
void SearchXaToaDo(Diem arrd[], int &n) {
	InpArrayDiem(arrd, n);
	
	Diem max = arrd[0];
	for(int i=1; i<n; i++) {
		float diem1 = sqrt(max.x*max.x + max.y*max.y);
		float diem2 = sqrt(arrd[i].x*arrd[i].x + arrd[i].y*arrd[i].y);
		if(diem2 > diem1)
			max = arrd[i];
	}
	printf("\nDiem xa gan goc toa do nhat (x, y) = (%.2f, %.2f)", max.x, max.y);
}

