#include <iostream>
#include <fstream>
using namespace std;
/*
	Cho mot file gom t bo test, moi bo test ghi tren 2 dong.
	Dong thu nhat la so phan cua mang ta ki hieu la n.
	Dong thu hai gom n phan tu cac so nguyen duoc ghi cach nhau mot vai dau cach.
	Hay ap dung de chi ra trong t mang do mang nao doi xung, mang nao khong doi xung.
	Ket qua the hien tren dong nhu sau: Neu mang doi xung ghi ra YES, nguoc lai ghi No.
*/
bool TestDoiXung(int arr[], int n) {
	for(int i=0; i<(n-1)/2; i++)
		if(arr[i] != arr[n-i-1])
			return false;
	return true;
}

	/*Main function*/
int main() {
	int n, n1, arr[50];
	ifstream ifs("Bai05_Input.txt");
	ofstream ofs("Bai05_Output.txt");
	ifs >> n;
	for(int i=0; i<n; i++) {	//So bo du lieu
		ifs >> n1;
		for(int j=0; j<n1; j++)
			ifs >> arr[j];
		if(TestDoiXung(arr, n1) == true)
			ofs << "YES" << endl;
		else ofs << "NO" << endl;
	}
	ofs.close();
	ifs.close();
	return 0;
}

