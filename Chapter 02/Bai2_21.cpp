#include<stdio.h>
/*
	Co tong 20000d tu 3 to giay bac 5000d, 2000d, 1000d (moi loai giay bac co it nhat 1 to).
	Viet chuong trinh lap ra tat ca cac phuong an phu hop.
*/
int main() {
	int count = 0;
	for(int i=1; i<=4; i++)		//Giay bac 5000d
		for(int j=1; j<=10; j++)	//Giay bac 2000d
			for(int k=1; k<=20; k++) 	//Giay bac 1000d
				if(i*5000+j*2000+k*1000 == 20000)
				{
					printf("%d to 5000d, %d to 2000d, %d to 1000d\n", i, j, k);
					count++;
				}
	printf("Tat ca %d phuong an", count);
	return 0;
}

