#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
	Viet tro choi bao - da - keo voi luat choi: bao thang da, da thang keo, keo thang bao.
	Nguoi choi nhap vao mot trong ba ky tu b (bao), d (da), k (keo)
	May tinh sinh ngau nhien mot trong ba ky tu tren, thong qua ket qua choi.
*/
string game = "bdk";
int computer = 0, player = 0;

	/*Kiem tra tro choi bao - da - keo*/
void BaoDaKeo(char com, char play) {
	if((com=='b' && play=='d') || (com=='d' && play=='k') || (com=='k' && play=='b')) {
		cout << "\nMay thang";
		computer++;
	}
	else if(com == play)
		cout << "\nHai ben hoa";
	else {
		cout << "\nBan thang";
		player++;
	}
}

	/*Main function*/
int main() {
	char play, ans;
	do{
		srand(time(NULL));
		ans = game[rand()%3];	//May tinh chon ngau nhien bao - da - keo

		cout << "\nChon 1 trong 3: ky tu b (bao), d (da), k (keo): ";
		cin >> play;
		if(play - '0' == 0) {
			cout << "\nTi so (computer:player) = " << computer << " : " << player;
			if(computer > player) cout << "\nKet qua cuoi cung may tinh thang";
			else if(computer < player) cout << "\nKet qua cuoi cung ban thang";
			else cout << "\nKet qua cuoi cung ban va may tinh hoa";
			return 0;	//Thoat chuong trinh
		}
		
		BaoDaKeo(ans, play);
		cout << "\nTi so (computer:player) = " << computer << " : " << player;
	}while(true);
	return 0;
}

