#include<stdio.h>
/*
	Viet chuong trình in ra tat ca cac so nho hon 100 tru các so 5, 7, 93.
*/
int main() {
	for(int i=1; i<=100; i++) {
		if(i==5 || i==7 || i==93)
			continue;
		if(i%2!=0)
			printf("%5d", i);
	}
	return 0;
}

