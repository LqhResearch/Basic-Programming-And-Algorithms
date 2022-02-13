#include<stdio.h>
#include<string.h>
/*
	Chuyen doi so la ma sang so thap phan
*/
char laMa[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int soLaMa[7] = {1, 5, 10, 50, 100, 500, 1000};

int laMatoNum(char c) {
	for(int i=0; i<7; i++)
		if(c == laMa[i])
			return i;
}

int main() {
	char str[20];
	printf("Nhap so La ma (Chi su dung I, V, X, L, C, D, M) = ");
	gets(str);
	int sum = 0;
	int after, before, len = strlen(str);
	for(int i=0; i<len; i++) {
		before = laMatoNum(str[i]);
		after = laMatoNum(str[i+1]);
		if(i == len-1)
			after = 0;
		if(before >= after)
			sum+=soLaMa[before];
		else
			sum-=soLaMa[before];
	}
	printf("Ket qua = %d", sum);
	return 0;
}

