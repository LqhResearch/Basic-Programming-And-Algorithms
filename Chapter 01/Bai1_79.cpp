#include<stdio.h>
#include<math.h>
#include<string.h>
/*
	Doi tu he nhi phan sang thap phan
*/
int main() {
	char str[50];
	printf("Nhap ma nhi phan = ");
	gets(str);
	int sum = 0, len = strlen(str);
	for(int i=0; i<len; i++)
		sum+=((int)str[i]-48)*pow(2, len-i-1);
	printf("So thap phan = %d", sum);
	return 0;
}

