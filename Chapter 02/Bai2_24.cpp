#include<stdio.h>
/*
	Viet chuong trinh giai bai toan co:
		Tram trau, tram bo
		Trau dung, an nam
		Trau nam, an ba
		Lu khu trau gia
		Ba con mot bo
		Hoi co bao nhieu trau dung, trau nam, trau gia
*/
int main() {
	/*
		Su dung 3 vong lap so con trau dung, trau na, trau gia
		Trau dung + Trau nam + 3Trau gia
		5.Trau dung + 3.Trau nam + Trau gia/3 (voi trau gia la so chia het cho 3) == 100
	*/
	for(int dung=1; dung<=20; dung++)
		for(int nam=1; nam<=33; nam++)
			for(int gia=1; gia<=100; gia++)
				if(5*dung+3*nam+gia/3 == 100 && gia%3==0 && dung+nam+gia==100)
					printf("%d trau dung, %d trau nam, %d trau gia\n", dung, nam, gia);
	return 0;
}

