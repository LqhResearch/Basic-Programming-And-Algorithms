#include <iostream>
using namespace std;
/*
	Cho ni la mot so nguyen duong, voi dinh nghia: Chuoi tren so ngung khi ni co gia tri 1. 
	Cac so duoc sinh ra goi la hailstones(mua da) va qua trinh tren duoc chung minh la luon luon dung.
	Viet chuong trinh sinh ra chuoi hailstones voi ni nhap tu ban phim.
*/

	/*Main function*/
int main() {
	int n, num = 0, i = 0;
	do{
		cout << "Nhap so nguyen duong: ";
		cin >> n;
		if(n <= 0)
			cout << "Hay nhap so nguyen duong" << endl;
	}while(n <= 0);
	
	while(true) {
		cout << "  " << n;
		if(n == 1 && num > 1 && ++num) break;
		if(n % 2) n = 3*n+1;
		else n /= 2;
		num++;	i++;
		if(num % 6)
			cout << endl;
	}
	cout << endl << "Hailstones sinh duoc = " << num;
	return 0;
}

