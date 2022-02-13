#include<stdio.h>
#include<string.h>
/*
	In ra ma Hexa cua so nguyen duong n
*/
int main() {
	char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
		if(n < 0)
			printf("Vui long nhap so nguyen duong.\n");
	}while(n < 0);
	
	char maHex[20];
	int temp = n, i = 0, kiTu;
	while(temp != 0) {
		maHex[i] = hex[temp%16];
		temp/=16;
		i++;
	}
	printf("Ma hex cua %d la ", n);
	strrev(maHex);
	for(int i=0; i<strlen(maHex); i++)
		printf("%c", maHex[i]);
	return 0;
}

