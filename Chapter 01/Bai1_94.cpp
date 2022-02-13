#include <iostream>
using namespace std;
/*
	Nhap vao mot so tien n (nghin dong, n > 5) nguyen duong.
	Doi so tien nay ra ba loai tien giay 1000VNÐ, 2000VNÐ, 5000VNÐ.
	Tim phuong an doi tien sao cho loai tien 2000VNÐ chiem hon phan nua so to bac phai doi it nhat.
*/

	/*Main function*/
int main() {
	int n;
	cout << "Nhap so tien: ";
	cin >> n;
	
	for(int i=0; i<=n; i++)		//To 1000VND
		for(int j=0; j<=(n/2); j++)		//To 2000VND
			for(int k=0; k<=(n/5); k++)		//To 5000VND
				if((i+j*2+k*5 == n) && (j > i+k))
					cout << endl << "(1000VND, 2000VND, 5000VND) = " << i << ", " << j << ", " << k << " = " << i+j+k;
	return 0;
}

