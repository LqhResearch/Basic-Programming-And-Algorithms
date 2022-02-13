#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
	Khai bao kieu du lieu DaThuc va dinh nghia ham nhap, ham xuat.
	-	Tinh tong hai da thuc.
	-	Tinh hieu hai da thuc.
	-	Tinh tich hai da thuc.
	-	Tinh thuong hai da thuc.
	-	Tinh da thuc du cho phep chia 2 da thuc.
	-	Tinh dao ham cap 1 cua da thuc.
	-	Tinh dao ham cap k cua da thuc.
	-	Tinh gia tri da thuc toi vi tri x = xo.
*/
typedef struct DonThuc {
	float heSo;
	int soMu;
} DonThuc;

typedef struct DaThuc {
	DonThuc donT[10];
} DaThuc;

void menu();
void InitDT(DaThuc &dt);
void InpDaThuc(DaThuc &dt);
void OutDaThuc(DaThuc dt);

	/*Main function*/
int main() {
	do{
		menu();
	}while(true);
	return 0;
}

	/*Khoi tao gia tri 0 cho da thuc*/
void InitDT(DaThuc &dt) {
	for(int i=0; i<10; i++) {
		dt.donT[i].heSo = 0;
		dt.donT[i].soMu = i;
	}
}

	/*Nhap da thuc*/
void InpDaThuc(DaThuc &dt) {
	int n;
	do{
		printf("\nNhap so mu cao nhat cua da thuc (0 -> 9): ");
		scanf("%d", &n);
	}while(n<0 || n>9);

	InitDT(dt);
	for(int i=n; i>=0; i--) {
		printf("He so bac %d: ", i);
		scanf("%f", &dt.donT[i].heSo);
	}
	OutDaThuc(dt);
}

	/*Xuat da thuc*/
void OutDaThuc(DaThuc dt) {
	int count=0;
	printf("Da thuc: ");
	for(int i=9; i>=0; i--) {
		if(dt.donT[i].heSo == 0)
			continue;
		
		if(count++ == 0)
			printf("%.2fx^%d", dt.donT[i].heSo, i);
		else
			printf(" + %.2fx^%d", dt.donT[i].heSo, i);
	}	
}

	/*Tong hai da thuc*/
void TongDaThuc(DaThuc dt1, DaThuc dt2) {
	DaThuc sum;		InitDT(sum);
	for(int i=9; i>=0; i--)
		sum.donT[i].heSo = dt1.donT[i].heSo + dt2.donT[i].heSo;
	printf("\nTong hai ");
	OutDaThuc(sum);
}

	/*Hieu hai da thuc*/
void HieuDaThuc(DaThuc dt1, DaThuc dt2) {
	DaThuc sub;		InitDT(sub);
	for(int i=9; i>=0; i--)
		sub.donT[i].heSo = dt1.donT[i].heSo - dt2.donT[i].heSo;
	printf("\nHieu hai ");
	OutDaThuc(sub);
}

	/*Tim bac cao nhat cua da thuc*/
int HighestLevel(DaThuc dt) {
	for(int i=9; i>=0; i--)
		if(dt.donT[i].heSo != 0)
			return i;
}

	/*Tich hai da thuc*/
void TichDaThuc(DaThuc dt1, DaThuc dt2) {
	DonThuc daT[20];
	int m = HighestLevel(dt1);
	int n = HighestLevel(dt2);
	
	//Khoi tao daThuc gia tri 0
	for(int i=19; i>=0; i++) {
		daT[i].heSo = 0;
		daT[i].soMu = i;
	}
	
	//Tich hai da thuc
	for(int i=m; i>=0; i--)
		for(int j=n; j>=0; j--) {
			int bac = dt1.donT[i].soMu + dt2.donT[j].soMu;
			daT[bac].heSo += dt1.donT[i].heSo * dt2.donT[j].heSo;
		}
	
	//Xuat tich da thuc
	int count=0;
	printf("Da thuc: ");
	for(int i=19; i>=0; i--) {
		if(daT[i].heSo == 0)
			continue;
		
		if(count++ == 0)
			printf("%.2fx^%d", daT[i].heSo, i);
		else
			printf(" + %.2fx^%d", daT[i].heSo, i);
	}	
}

	/*Thuong hai da thuc*/
void ThuongDaThuc(DaThuc dt1, DaThuc dt2) {
	DaThuc div;		InitDT(div);
	
	int high1 = HighestLevel(dt1);
	int high2 = HighestLevel(dt2);
	
	/*Chia hai da thuc*/
	while (high1 >= high2) {
		int lt = dt1.donT[high1].soMu - dt2.donT[high2].soMu;
		float ans = dt1.donT[high1].heSo / dt2.donT[high2].heSo;
		div.donT[lt].heSo = ans;
		
		for(int i=high2; i >= 0; i--) {
			int lt1 = lt+i;
			dt1.donT[lt1].heSo = dt1.donT[lt1].heSo - ans*dt2.donT[i].heSo;
		}
		high1--;
	}
	printf("\n\nThuong hai ");
	OutDaThuc(div);
}

	/*Phan du cua thuong hai da thuc*/
void PhanDuThuongDaThuc(DaThuc dt1, DaThuc dt2) {
	DaThuc div;		InitDT(div);
	
	int high1 = HighestLevel(dt1);
	int high2 = HighestLevel(dt2);
	
	/*Chia hai da thuc*/
	while (high1 >= high2) {
		int lt = dt1.donT[high1].soMu - dt2.donT[high2].soMu;
		float ans = dt1.donT[high1].heSo / dt2.donT[high2].heSo;
		div.donT[lt].heSo = ans;
		
		for(int i=high2; i >= 0; i--) {
			int lt1 = lt+i;
			dt1.donT[lt1].heSo = dt1.donT[lt1].heSo - ans*dt2.donT[i].heSo;
		}
		high1--;
	}
	printf("\n\nPhan du cua thuong hai ");
	OutDaThuc(dt1);
}

	/*Tinh dao ham cap k*/
void DaoHam(DaThuc dt, int n) {
	DaThuc tmp;		InitDT(tmp);
	
	int high = HighestLevel(dt);
	for(int k=1; k<=n; k++) {
		for(int i=high; i >= 0; i--)
			tmp.donT[i-1].heSo = i*dt.donT[i].heSo;
		
		dt.donT[high].heSo = 0;
		for(int i=high-1; i >= 0; i--)
			dt.donT[i].heSo = tmp.donT[i].heSo;
		high--;
	}
	printf("\n\nDao ham cap %d: ", n);
	OutDaThuc(dt);
}

	/*Gia tri da thuc toi vi tri X = Xo*/
float GiaTriXo(DaThuc dt, float x) {
	int sum = 0;
	for(int i=HighestLevel(dt); i>=0; i--)
		sum += (dt.donT[i].heSo*pow(x, dt.donT[i].soMu));
	return sum;
}

	/*Chuc nang cua Don thuc*/
void menu() {
	DaThuc dt1, dt2;
	int choice;
	do{
		printf("\n=====Chuc nang Da thuc=====");
		printf("\n1. Tong hai da thuc");
		printf("\n2. Hieu hai da thuc");
		printf("\n3. Tich hai da thuc");
		printf("\n4. Thuong hai da thuc");
		printf("\n5. Tinh da thuc du cho phep chia 2 da thuc");
		printf("\n6. Dao ham cap 1 cua da thuc");
		printf("\n7. Dao ham cap k cua da thuc");
		printf("\n8. Gia tri da thuc toi vi tri X = Xo");
		printf("\n0. Thoat");
		printf("\n >> Hay lua chon: ");
		scanf("%d", &choice);
		if(choice<0 || choice>9)
			printf("\nChuc nang nay khong ton tai");
	}while(choice<0 || choice>9);
	
	switch(choice) {
		case 1:{
			InpDaThuc(dt1);
			InpDaThuc(dt2);
			TongDaThuc(dt1, dt2);
			break;
		}
		case 2:{
			InpDaThuc(dt1);
			InpDaThuc(dt2);
			HieuDaThuc(dt1, dt2);
			break;
		}
		case 3:{
			InpDaThuc(dt1);
			InpDaThuc(dt2);
			TichDaThuc(dt1, dt2);
			break;
		}
		case 4:{
			InpDaThuc(dt1);
			InpDaThuc(dt2);
			ThuongDaThuc(dt1, dt2);
			break;
		}
		case 5:{
			InpDaThuc(dt1);
			InpDaThuc(dt2);
			PhanDuThuongDaThuc(dt1, dt2);
			break;
		}
		case 6:{
			InpDaThuc(dt1);
			DaoHam(dt1, 1);
			break;
		}
		case 7:{
			int k;
			printf("Dao ham cap k: ");
			scanf("%d", &k);
			InpDaThuc(dt1);
			DaoHam(dt1, k);
			break;
		}
		case 8:{
			InpDaThuc(dt1);
			float x;
			printf("\n\nNhap Xo = ");
			scanf("%f", &x);
			printf("Ket qua = %.2f", GiaTriXo(dt1, x));
			break;
		}
		case 0: exit(0);
	}
}

