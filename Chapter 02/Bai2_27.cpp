#include<stdio.h>
/*
	Nhap vao mot nam tinh can chi cua nam vua nhap.
		10 can: Canh, Tan, Nham, Quy, Giap, At, Binh, Ðinh, Mau, Ky.
		12 chi (12 con giáp): Ty, Suu, Dan, Mao, Thin, Ty, Ngo, Mui, Than, Dau, Tuat, Hoi.
*/
int main() {
	
	/*
		10 can: Canh, Tan, Nham, Quy, Giap, At, Binh, Ðinh, Mau, Ky
		12 chi (12 con giáp): Ty, Suu, Dan, Mao, Thin, Ty, Ngo, Mui, Than, Dau, Tuat, Hoi
	
	*/
	char can[10][5]={"Canh", "Tan", "Nham", "Quy", "Giap", "At", "Binh", "Dinh", "Mau", "Ky"};
	char chi[12][5]={"Than", "Dau", "Tuat", "Hoi", "Ti", "Suu", "Dan", "Mao", "Thin", "Ty.", "Ngo", "Mui"};
	int year;
	do{
		printf("Nhap nam: ");
		scanf("%d", &year);
		if(year < 0)
			printf("Vui long nam la so lon hon hoac bang 0\n");
	}while(year < 0);
	
	printf("Nam %d la nam %s %s", year, can[year%10], chi[year%12]);
	return 0;
}

