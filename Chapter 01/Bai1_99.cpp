#include <iostream>
using namespace std;
/*
	Trong ky tuyen sinh, mot thi sinh se trung tuyen neu co diem tong ket lon hon hoac bang diem chuan ca khong co mon nao diem 0.
	-	Diem tong ket la tong diem cua 3 mon thi va diem uu tien.
	-	Diem uu tien bao gom diem uu tien theo khu vuc va diem uu tien theo doi tuong.
	Viet chuong trinh nhap: diem chuan cua hoi dong, diem 3 mon thi cua thi sinh.
		Khu vuc		A		2 diem
					B		1 diem
					C		0.5 diem
					X		0 diem (khong thuoc khu vuc nao)
		Doi tuong	1		2.5 diem
					2		1.5 diem
					3		1 diem
					0		0 diem (khong thuoc doi tuong nao)
*/
	/*Tong diem 3 mon thi*/
float Subject(bool &paralysisPoint) {
	float subject1, subject2, subject3;
	cout << "- Diem mon thu 1: "; cin >> subject1;
	cout << "- Diem mon thu 2: "; cin >> subject2;
	cout << "- Diem mon thu 3: "; cin >> subject3;
	if(subject1 == 0 || subject2 == 0 || subject3 == 0)
		paralysisPoint = true;
	return subject1 + subject2 + subject3;
}

	/*Diem uu tien theo khu vuc*/
float Area() {
	char area;
	cout << "- Khu vuc (A, B, C, X): ";
	cin >> area;
	if(area == 'A' || area == 'a') return 2;
	if(area == 'B' || area == 'b') return 1;
	if(area == 'C' || area == 'c') return 0.5;
	if(area == 'X' || area == 'x') return 0;
}

	/*Diem uu tien theo khu vuc*/
float Object() {
	int object;
	cout << "- Doi tuong (1, 2, 3, 0): ";
	cin >> object;
	if(object == 1) return 2.5;
	if(object == 2) return 1.5;
	if(object == 3) return 1;
	if(object == 0) return 0;
}

	/*Diem chuan cua hoi dong*/
float BenchmarkOfCouncil() {
	float point;
	cout << "- Diem chuan cua hoi dong = ";
	cin >> point;
	return point;
}

	/*Main function*/
int main() {
	bool paralysisPoint = false;
	float totalPoint = Subject(paralysisPoint);
	float areaPoint = Area();
	float objectPoint = Object();
	float benchmark = BenchmarkOfCouncil();

	if(paralysisPoint == true)
		cout << "Ban da rot. Vi co mon bi diem 0" << endl;
	else {
		float point = totalPoint + areaPoint + objectPoint;
		cout << "\n==========Tong Ket==========" << endl;
		cout << "Diem 3 mon thi = " << totalPoint << " diem" << endl;
		cout << "Diem khu vuc = " << areaPoint << " diem" << endl;
		cout << "Diem doi tuong = " << objectPoint << " diem" << endl;
		cout << "Tong cong = " << point << " diem" << endl;
		cout << "Diem chuan = " << benchmark << " diem" << endl;
		if(point >= benchmark)
			cout << "Xin chuc mung\nBan dau" << endl;
		else cout << "Ban khong dau" << endl;
	}
	return 0;
}

