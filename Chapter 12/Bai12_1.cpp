#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
/*
	Ghi 5 so nguyen ngau nhien vao tap tin Bai01_Interger.txt, 5 so ngau nhien vao tap tin Bai01_Real.txt. 
	Sau do doc cac so nay tu tap tin va xuat ra man hinh.
*/

	/*Main function*/
int main() {
	int a; double b;
		//Ghi 5 so nguyen ngau nhien
	ofstream ofs("Bai01_Interger.txt");
	srand(time(NULL));
	for(int i=0; i<5; i++)
		ofs << rand() << endl;
	ofs.close();
	
		//Xuat 5 so nguyen ngau nhien
	cout << "\nSo nguyen: ";
	ifstream ifs("Bai01_Interger.txt");
	for(int i=0; i<5; i++) {
		ifs >> a;
		cout << a << "   ";
	}
	ifs.close();
	
		//Ghi 5 so thuc ngau nhien
	ofstream ofs1("Bai01_Real.txt");
	srand(time(NULL));
	for(int i=0; i<5; i++)
		ofs1 << rand()/(float)RAND_MAX << endl;
	ofs1.close();
	
		//Xuat 5 so thuc ngau nhien
	cout << "\nSo thuc: ";
	ifstream ifs1("Bai01_Real.txt");
	for(int i=0; i<5; i++) {
		ifs1 >> b;
		cout << b << "   ";
	}
	ifs1.close();
	return 0;
}

