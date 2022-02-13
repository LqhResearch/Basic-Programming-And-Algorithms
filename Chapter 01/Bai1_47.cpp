#include<stdio.h>
#include<math.h>
/*
	Nhap vao so nguyen duong n.
	Kiem tra so nguyen duong n co phai la "so nguyen to" hay khong?
*/
bool TestSNT(int n) {
	if(n <= 1)
		return false;
	for(int i=2; i<=sqrt(n); i++)
		if(n%i==0)
			return false;
	return true;	
}

int main() {
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	if(TestSNT(n))
		printf("%d la so nguyen to", n);
	else
		printf("%d khong phai la so nguyen to", n);
	return 0;
}

