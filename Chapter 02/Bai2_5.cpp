#include<stdio.h>
/*
	H�y su dung v�ng lap for de xuat:
	-	C�c k� tu A toi Z.
	-	C�c k� tu a toi z.
	-	C�c k� tu 0 toi 9.

*/
int main() {
	printf("\nCac ki tu A --> Z: \n");
	for(int i=65; i<= 90; i++)
		printf("%5c", i);
	printf("\nCac ki tu a --> z: \n");
	for(int i=97; i<= 122; i++)
		printf("%5c", i);
	printf("\nCac ki tu 0 --> 9: \n");
	for(int i=48; i<= 57; i++)
		printf("%5c", i);
	return 0;
}

