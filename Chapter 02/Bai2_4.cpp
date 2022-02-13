#include<stdio.h>
/*
	Tìm so nguyên duong n nho nhat sao cho 1 + 2 + … + k > 10000.
*/
int main() {
	int k = 0, sum = 0;
	while(sum < 10000) {
		sum+=k;
		k++;
	}
	printf("1 + 2 + 3 + ... + %d = %d", k, sum);
	return 0;
}

