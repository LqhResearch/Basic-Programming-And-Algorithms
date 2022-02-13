#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 50
using namespace std;
/*
	-	Tao mang ngau nhien co n phan tu nguyen co gia tri chan trong doan [-100, 100] va xuat mang.
	-	Viet ham thuc hien tron hoan hao (perfect shuffle) mot mang:
		sao cho cac phan tu cua mot nua mang sau xen ke cac phan tu cua mot nua mang dau. Xuat mang vua tron.
	-	Xac dinh so lan tron tren hoan hao de mang tro ve nhu ban dau.
*/
int arr[MAX], shuf[MAX], temp[MAX], n;

	/*Xuat mang*/
void OutArray(int array[]) {
	cout << endl << "Xuat mang: ";
	for(int i=0; i<n; i++)
		cout << array[i] << "   ";
}

	/*Tao mang ngau nhien*/
void CreateArray() {
	srand(time(NULL));
	for(int i=0; i<n; i++) {
		arr[i] = rand()%201 - 100;	//Sinh so ngau nhien [-100, 100]
		shuf[i] = arr[i];
	}
	OutArray(arr);
}

	/*Ham tron hoan hao*/
void PerfectShuffle() {
	int half = n/2;
	for(int i=0; i<half; i++)
		shuf[2*i] = temp[i];
	for(int i=half; i<n-1; i++)
		shuf[2*(i-half)+1] = temp[i];
	shuf[n-1] = temp[n-1];
	OutArray(shuf);
}

	/*Kiem tra 2 mang co giong nhau khong*/
bool Test2Array(int arr1[], int arr2[]) {
	for(int i=0; i<n; i++)
		if(arr1[i] != arr2[i])
			return false;
	return true;
}

	/*Sao chep mang*/
void CopyArray() {
	for(int i=0; i<n; i++)
		temp[i] = shuf[i];
}

	/*Dem so lan tron hoan hao de tro ve mang ban dau*/
int CountPerShuff() {
	for(int i=1; ; i++) {
		CopyArray();
		PerfectShuffle();
		if(Test2Array(arr, shuf) == true)
			return i;
	}
}

	/*Ham chuong trinh chinh*/
int main() {
	do{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if(n <= 0)
			cout << "So luong phan tu phai > 0" << endl;
	}while(n <= 0);
	
	CreateArray();
	cout << endl << "Can " << CountPerShuff() << " lan de shuffle tro ve ban dau";
	return 0;
}
