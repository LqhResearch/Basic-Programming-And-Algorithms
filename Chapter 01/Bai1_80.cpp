#include<stdio.h>
#include<math.h>
#include<string.h>
/*
	Doi tu he thap phan sang nhi phan
*/
int main() {
	char bin[50];
	fflush(stdin);
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong.\n");
	}while(n < 0);
	
	int temp = n, i = 0;
	while(temp != 0) {
		bin[i] = temp%2+48;
		temp/=2;
		i++;
	}
	strrev(bin);
	printf("So nguyen duong %d co ma nhi phan la: ", n);
	for(int i=0; i<strlen(bin); i++)
		printf("%c", bin[i]);
	return 0;
}

